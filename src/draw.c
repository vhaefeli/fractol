/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <vhaefeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:21:41 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/05/13 13:50:21 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h" 

void	ft_shade_color(t_varmlx *v, int i)
{
	if (i == v->itmax)
		v->pxlcolor = 0xFF000000;
	else
		v->pxlcolor = 0xFF00FFFF - 0x001000 * i;
}


int		put_pixel(t_varmlx *v)
{
	int		i;
	int		x;
	int		y;
	char	*rgb;

	x = v->pxlpos.x;
	y = v->pxlpos.y;
	i = ((int)v->pxlpos.x * (v->bpp / 8)) + ((int)v->pxlpos.y * v->size_line);
	rgb = (char*)&v->pxlcolor;
	v->imgdata[i] = rgb[0];
	v->imgdata[++i] = rgb[1];
	v->imgdata[++i] = rgb[2];
	return (0);
}

void	draw_fractal(t_varmlx *v)
{
	while (++v->pxlpos.y < IMG_H)
	{
		v->pxlpos.x = -1;
		while (++v->pxlpos.x < IMG_W)
		{
			if (v->fractal  == 1)
				fractal_mandelbrot(v);
			else if (v->fractal == 2)
				fractal_julia(v);
			else if (v->fractal == 3)
				fractal_burningship(v);
			else if (v->fractal == 4)
				fractal_feather(v);
		}
	}
	v->pxlpos.y = -1;
}

char    *fractal_name(int fractal)
{
    if (fractal == 1)
        return ("Mandelbrot");
    if (fractal == 2)
        return ("Julia");
    if (fractal == 3)
        return ("Burningship");
	if (fractal == 4)
        return ("Feather");
	else
		return (NULL);	
}

void	user_interface_texts(t_varmlx *v)
{
	mlx_string_put(v->mlx, v->win, 2128, 28, v->tcolor, "Fractal:");
	mlx_string_put(v->mlx, v->win, 2191, 28, v->tcolor, fractal_name(v->fractal));
	mlx_string_put(v->mlx, v->win, 2128, 48, v->tcolor, "Use < or > to change");
    mlx_string_put(v->mlx, v->win, 2128, 68, v->tcolor, "Mouse position/focus point:");
    mlx_string_put(v->mlx, v->win, 2128, 88, v->tcolor, "Real (y):");
    mlx_string_put(v->mlx, v->win, 2128, 108, v->tcolor, ft_itoa((int)(v->mr * 10000)));
	mlx_string_put(v->mlx, v->win, 2163, 108, v->tcolor, "*10^-4");
    mlx_string_put(v->mlx, v->win, 2128, 128, v->tcolor, "Imaginary (x):");
    mlx_string_put(v->mlx, v->win, 2128, 148, v->tcolor, ft_itoa((int)(v->mi * 10000)));
	mlx_string_put(v->mlx, v->win, 2163, 148, v->tcolor, "*10^-4");
    mlx_string_put(v->mlx, v->win, 2128, 168, v->tcolor, "Max Iteration:");
    mlx_string_put(v->mlx, v->win, 2128, 188, v->tcolor, ft_itoa(v->itmax));
	mlx_string_put(v->mlx, v->win, 2128, 208, v->tcolor, "Use UP or DOWN to change");
	mlx_string_put(v->mlx, v->win, 2128, 228, v->tcolor, "scale:");
	mlx_string_put(v->mlx, v->win, 2128, 248, v->tcolor, ft_itoa((int)(1 / v->scale)));
	mlx_string_put(v->mlx, v->win, 2128, 268, v->tcolor, "Mouse on:");
	mlx_string_put(v->mlx, v->win, 2198, 268, v->tcolor, ft_itoa(v->mouseonoff));
}
