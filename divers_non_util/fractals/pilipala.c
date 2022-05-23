/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 10:50:02 by pbondoer          #+#    #+#             */
/*   Updated: 2022/03/25 13:47:26 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include <math.h>
#include <stdio.h>

t_pixel		pilipala_pixel(int x, int y, t_viewport *v, t_mlx *mlx)
{
	t_complex	z;
	t_complex	c;
	t_complex	temp;
	long double		d;
	int			i;

	(void)mlx;
	z = screen_to_complex(x, y, v);
	c = v->mouse;
	i = 0;
	while (z.r * z.r + z.i * z.i < (1 << 8) && i < v->max)
	{
		d = 1 + pow(z.r, 4) + pow(z.i, 4) + 2* z.r * z.r - 2 * z.i * z.i + 2 * z.r *z.r * z.i * z.i;
		if (d == 0)
			break;
		temp.r = (z.i * (pow(z.i, 4) + z.i * z.i * (1 + 2 * z.i * z.i) - 3 * z.i * z.i - pow(z.i, 4))) / d  + c.r;
		temp.i = (z.i * (pow(z.i, 4) + z.i * z.i * (-1 + 2 * z.i * z.i) + 3 * z.i * z.i + pow(z.i, 4))) / d  + c.i;
		if (z.r == temp.r && z.i == temp.i)
		{
			i = v->max;
			break ;
		}
		z.r = temp.r;
		z.i = temp.i;
		i++;
	}
	return ((t_pixel){.c = z, .i = i});
}

void		pilipala_viewport(t_viewport *v)
{
	v->xmin = -2.0f;
	v->xmax = 2.0f;
	v->ymin = -2.0f;
	v->ymax = 2.0f;
	v->offx = -0.25f;
}
