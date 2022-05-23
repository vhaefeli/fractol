/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <vhaefeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:22:17 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/05/18 16:28:06 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_win(t_varmlx *v)
{
	assign(v);
	v->mlx = mlx_init();
	v->win = mlx_new_window(v->mlx, WIN_W, WIN_H, "Fract-ol");
	mlx_expose_hook(v->win, expose_hook, v);
	mlx_hook(v->win, EVENT_ON_MOUSEMOVE, 64, motion_hook, v);
	mlx_hook(v->win, EVENT_ON_DESTROY, 0, close_hook, v);
	mlx_hook(v->win, EVENT_ON_KEYDOWN, 0, key_hook, v);
	mlx_hook(v->win, EVENT_ON_MOUSEDOWN, 0, mouse_hook, v);
	mlx_do_key_autorepeaton(v->mlx);
	mlx_loop(v->mlx);
	exit(0);
}

int	expose_hook(t_varmlx *v)
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
		v->itmax += 10;
	else if (keycode == KEY_DOWN)
		v->itmax -= 10;
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
		if (v->fractal > 1)
			v->fractal--;
		else
			v->fractal = 4;
		assign(v);
	}
}

int	key_hook(int keycode, t_varmlx *v)
{
	int	r;

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

int	close_hook(int button, t_varmlx *v)
{
	(void)button;
	(void)v;
	exit(0);
	return (0);
}
