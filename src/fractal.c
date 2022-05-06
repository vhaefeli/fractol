/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <vhaefeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:21:55 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/05/06 17:00:52 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	fractal_mandelbrot(t_varmlx	*v)
{
	t_complex	z;
	t_complex	c;
	t_complex	temp;
	int			i;

	z.r = 0;
	z.i = 0;
	c.i = (v->pxlpos->x - v->cx) * v->scale;
	c.r = (- v->pxlpos-> + c->cy) * v->scale;
	i = 0;
	while (z.r * z.r + z.i * z.i < 4 && i++ < v->itmax)
	{
		temp.r = z.r * z.r - z.i * z.i + c.r;
		temp.i = z.r * z.i * 2 + c.i;
		if (z.r == temp.r && z.i == temp.i)
		{
			i = v->max;
			break ;
		}
		z.r = temp.r;
		z.i = temp.i;
	}
	ft_shade_color(v, i);
	put_pixel(v);
}

void	fractal_julia(t_var *v)
{
	v->i = -1.0;
	v->mod = 2;
	v->zr = (v->e == 0 || v->e == 2) ? (D(v->x) / v->z) + v->minx :
	(D(v->y) / v->z) + v->miny;
	v->zi = (v->e == 0 || v->e == 2) ? (D(v->y) / v->z) + v->miny :
	(D(v->x) / v->z) + v->minx;
	while (++v->i < v->imax && (v->zr * v->zr + v->zi * v->zi) < 4)
	{
		v->tmp = v->zr;
		v->zr = (v->zr * v->zr) - (v->zi * v->zi) + v->jr;
		v->zi = v->mod * v->zi * v->tmp + v->ji;
	}
	v->clr = edit_hue_hex(v);
	if (((v->x >= 25 && v->x <= 188) &&
	((v->y >= 25 && v->y <= 213) || (v->y >= 237 && v->y <= 326) ||
	(v->y >= (WIN_H - 133) && v->y <= (WIN_H - 25)))) ||
	(v->x >= (v->len - 1) && v->x <= (WIN_W - 25) &&
	v->y >= (WIN_H - 65) && v->y <= (WIN_H - 25)))
		v->clr = ft_shade_color(v->clr, 0.35);
	put_pixel(v, 0);
}

