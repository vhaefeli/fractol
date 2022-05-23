/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   feather.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <vhaefeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 10:50:02 by pbondoer          #+#    #+#             */
/*   Updated: 2022/05/11 11:10:16 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include <math.h>
#include <stdio.h>

t_pixel		feather_pixel(int x, int y, t_viewport *v, t_mlx *mlx)
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
		d = 1 + pow(z.r, 4) + pow(z.i, 4) + (2 * z.r * z.r) - (2 * z.i * z.i) + (2 * z.r *z.r * z.i * z.i);
		if (d == 0)
			break;
		temp.r = (pow(z.r, 5) + pow(z.r, 3) + (2 * pow(z.r, 3) * z.i * z.i) - (3 * z.r * z.i * z.i) - (z.r * pow(z.i, 4))) / d  + c.r;
		temp.i = (pow(z.i, 5) - pow(z.i, 3) + (2 * z.r * z.r * pow(z.i, 3) ) + ( 3 * z.r * z.r * z.i) + (pow(z.r, 4) * z.i))/ d  + c.i;
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

void		feather_viewport(t_viewport *v)
{
	v->xmin = -2.0f;
	v->xmax = 2.0f;
	v->ymin = -2.0f;
	v->ymax = 2.0f;
	v->offx = -0.25f;
}
