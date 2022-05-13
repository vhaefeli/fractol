/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <vhaefeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:22:17 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/05/12 15:30:25 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		expose_hook(t_varmlx *v)
{
	v->img = mlx_new_image(v->mlx, WIN_W, WIN_H);
	v->imgdata = mlx_get_data_addr(v->img, &v->bpp, &v->size_line, &v->endian);
	draw_fractal(v);
	mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
	user_interface_texts(v);
	return (0);
}

static void	key_control(t_varmlx *v, int keycode)
{
	if (keycode == KEY_UP)
			v->itmax += 5;
	else if (keycode == KEY_DOWN)
			v->itmax -= 5;
	else if (keycode == KEY_RIGHT)
	{
		if (v->fractal < 4)
			v->fractal++;
		else 
			v->fractal = 1;
		assign(v);
	}
	else if (keycode == KEY_LEFT)
	{
		if (v->fractal > 0)
			v->fractal--;
		else 
			v->fractal = 4;
		assign(v);
	}
}

int		key_hook(int keycode, t_varmlx *v)
{
	int		r;

	r = 0;
	if (keycode == KEY_ESC)
	{
		mlx_destroy_image(v->mlx, v->img);
		mlx_destroy_window(v->mlx, v->win);
		exit(0);
	}
	else
	{
		if (keycode == KEY_M && ++r > 0 && v->mouseonoff == 0)
			v->mouseonoff = 1;
		else if (keycode == KEY_M && ++r > 0 && v->mouseonoff == 1)
			v->mouseonoff = 0;
		else if (keycode > 122 && keycode < 127 && ++r > 0)
			key_control(v, keycode);
		if (r > 0)
		{
			mlx_destroy_image(v->mlx, v->img);
			mlx_clear_window(v->mlx, v->win);
			expose_hook(v);
		}
	}
	return (0);
}

// here the real numbers correspond to the -y axis and the imaginary to the x axis
static void    zoom_focused(t_varmlx *v, double zoomstep)
{
    if (v->i == 0)
    {
        v->scale = v->scale / zoomstep;
        v->cx = v->mouse.x - ((v->mouse.x - v->cx) * zoomstep);
        v->cy = v->mouse.y - ((v->mouse.y - v->cy) * zoomstep);
        v->i = 1;  
    }
    v->xi = (v->pxlpos.x - v->cx) * v->scale;
    v->yr = (- v->pxlpos.y + v->cy) * v->scale;
}

int		mouse_hook(int button, int x, int y, t_varmlx *v)
{
	v->mouse.x = x;
	v->mouse.y = y;
	if (x >= 0 && x < IMG_W && y >= 0 && y < IMG_H)
	{
		if (v->mouseonoff == 1)
    	{
        	v->mi = (v->mouse.x - v->cx) * v->scale;
        	v->mr = (- v->mouse.y + v->cy) * v->scale;
    	}
		if (button == MOUSE_SCROLL_UP)
			zoom_focused(v, 1.5);
		if (button == MOUSE_SCROLL_DOWN)
			zoom_focused(v, 1 / 1.5);
		mlx_destroy_image(v->mlx, v->img);
		mlx_clear_window(v->mlx, v->win);
		expose_hook(v);
	}
	return (0);
}

int		close_hook(int button, t_varmlx *v)
{
	(void)button;
	(void)v;
	exit(0);
	return (0);
}

int		motion_hook(int x, int y, t_varmlx *v)
{
	if (x >= 0 && x < IMG_W && y >= 0 && y < IMG_H &&
		v->fractal % 2 == 0 && v->mouseonoff == 1)
	{
		v->mouse.x = (((MAX_J - MIN_J) / ((double)(IMG_W) - 0.0)) * ((double)(x) - 0.0)) + MIN_J;
		v->mouse.y = (((MAX_J - MIN_J) / ((double)(IMG_W) - 0.0)) * ((double)(y) - 0.0)) + MIN_J;
		mlx_destroy_image(v->mlx, v->img);
		mlx_clear_window(v->mlx, v->win);
		expose_hook(v);
	}
	return (0);
}