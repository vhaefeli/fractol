/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <vhaefeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:21:55 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/05/18 16:28:49 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_shade_color(t_varmlx *v, int i)
{
	if (i == v->itmax)
		v->pxlcolor = 0xFF001000;
	else
		v->pxlcolor = 0xFF00FFFF - 0x0001000 * i;
}

void	fractal_mandelbrot(t_varmlx	*v)
{
	t_complex	z;
	t_complex	c;
	t_complex	temp;
	int			i;

	z.r = 0;
	z.i = 0;
	c.r = (v->pxlpos.x - v->cx) * v->scale / IMG_W;
	c.i = (-(v->pxlpos.y) + v->cy) * v->scale / IMG_W;
	i = 0;
	while (z.r * z.r + z.i * z.i < 4 && i++ < v->itmax)
	{
		temp.r = z.r * z.r - z.i * z.i + c.r;
		temp.i = z.r * z.i * 2 + c.i;
		z.r = temp.r;
		z.i = temp.i;
	}
	ft_shade_color(v, i);
	put_pixel(v);
}

void	fractal_julia(t_varmlx *v)
{
	t_complex	z;
	t_complex	c;
	t_complex	temp;
	int			i;

	z.r = (v->pxlpos.x - v->cx) * v->scale / IMG_W;
	z.i = (-(v->pxlpos.y) + v->cy) * v->scale / IMG_W;
	c.i = v->mi;
	c.r = v->mr;
	i = 0;
	while (z.r * z.r + z.i * z.i < 4 && i++ < v->itmax)
	{
		temp.r = z.r * z.r - z.i * z.i + c.r;
		temp.i = z.r * z.i * 2 + c.i;
		z.r = temp.r;
		z.i = temp.i;
	}
	ft_shade_color(v, i);
	put_pixel(v);
}

void	fractal_burningship(t_varmlx *v)
{
	t_complex	z;
	t_complex	c;
	t_complex	temp;
	int			i;

	z.r = (v->pxlpos.x - v->cx) * v->scale / IMG_W;
	z.i = -(-(v->pxlpos.y) + v->cy) * v->scale / IMG_W;
	c.r = (v->pxlpos.x - v->cx) * v->scale / IMG_W;
	c.i = -(-(v->pxlpos.y) + v->cy) * v->scale / IMG_W;
	i = 0;
	while (z.r * z.r + z.i * z.i < 4 && i < v->itmax)
	{
		z.r = fabsl(z.r);
		z.i = fabsl(z.i);
		temp.r = z.r * z.r - z.i * z.i + c.r;
		temp.i = z.r * z.i * 2 + c.i;
		z.r = temp.r;
		z.i = temp.i;
		i++;
	}
	ft_shade_color(v, i);
	put_pixel(v);
}

void	fractal_feather(t_varmlx *v)
{
	t_complex	z;
	t_complex	c;
	t_complex	temp;
	long double	d;
	int			i;

	z.i = (v->pxlpos.x - v->cx) * v->scale / IMG_W;
	z.r = (-(v->pxlpos.y) + v->cy) * v->scale / IMG_W;
	c.i = v->mi;
	c.r = v->mr;
	i = 0;
	while (z.r * z.r + z.i * z.i < 20 && i < v->itmax)
	{
		d = 1 + pow(z.r, 4) + pow(z.i, 4) + (2 * z.r * z.r) - (2 * z.i * z.i)
			+ (2 * z.r * z.r * z.i * z.i);
		temp.r = (pow(z.r, 5) + pow(z.r, 3) + (2 * pow(z.r, 3) * z.i * z.i)
				- (3 * z.r * z.i * z.i) - (z.r * pow(z.i, 4))) / d + c.r;
		temp.i = (pow(z.i, 5) - pow(z.i, 3) + (2 * z.r * z.r * pow(z.i, 3))
				+ (3 * z.r * z.r * z.i) + (pow(z.r, 4) * z.i)) / d + c.i;
		z.r = temp.r;
		z.i = temp.i;
		i++;
	}
	ft_shade_color(v, i);
	put_pixel(v);
}
