/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <vhaefeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:46:30 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/05/16 15:49:40 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// here the real numbers correspond to the -y axis
//and the imaginary to the x axis
static void	zoom_focused(t_varmlx *v, double zoomstep)
{
	v->scale = v->scale / zoomstep;
	v->cx = v->mouse.x - ((v->mouse.x - v->cx) * zoomstep);
	v->cy = v->mouse.y - ((v->mouse.y - v->cy) * zoomstep);
	v->xi = (v->pxlpos.x - v->cx) * v->scale / IMG_W;
	v->yr = (-(v->pxlpos.y) + v->cy) * v->scale / IMG_W;
}

int	mouse_hook(int button, int x, int y, t_varmlx *v)
{
	int		r;

	v->mouse.x = x;
	v->mouse.y = y;
	r = 0;
	if (x >= 0 && x < IMG_W && y >= 0 && y < IMG_H && ++r > 0)
	{
		if (button == MOUSE_SCROLL_UP)
		{
			v->itmax = v->itmax - 2;
			zoom_focused(v, 1 / 1.2);
		}
		else if (button == MOUSE_SCROLL_DOWN)
		{
			v->itmax = v->itmax + 5;
			zoom_focused(v, 2);
		}
	}
	if (r > 0)
	{
		mlx_destroy_image(v->mlx, v->img);
		mlx_clear_window(v->mlx, v->win);
		expose_hook(v);
	}
	return (0);
}

int	motion_hook(int x, int y, t_varmlx *v)
{
	v->mouse.x = x;
	v->mouse.y = y;
	if (v->mouseonoff == 1)
	{
		v->mi = (v->mouse.x - v->cx) * v->scale / IMG_W;
		v->mr = (-(v->mouse.y) + v->cy) * v->scale / IMG_W;
		mlx_destroy_image(v->mlx, v->img);
		mlx_clear_window(v->mlx, v->win);
		expose_hook(v);
	}
	return (0);
}
