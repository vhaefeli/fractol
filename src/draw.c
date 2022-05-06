/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <vhaefeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:21:41 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/05/06 17:01:26 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int		put_pixel(t_varmlx *w, int type)
{
	int		i;
	int		x;
	int		y;
	char	*rgb;

	x = w->pxlpos->x;
	y = w->pxlpos->y;
	if (((type == 1 && x > 213) || (type != 1 && x >= 0))
			&& x < WIN_W && y >= 0 && y < WIN_H)
	{
		i = ((int)v->x * (v->bpp / 8)) + ((int)v->y * v->sl);
		rgb = (char*)&v->clr;
		v->d[i] = rgb[0];
		v->d[++i] = rgb[1];
		v->d[++i] = rgb[2];
	}
	return (0);
}

void	draw_fractal(t_var *v, int fractal, t_irgraph *g)
{
		while (++v->y < WIN_H && (v->x = -1) == -1)
	{
		while (++v->x < WIN_W)
		{
			if (fractal  == 1)
				fractal_mandelbrot(v, g);
			else if (fractal == 2)
				fractal_julia(v, g);
			else if (fractal == 3)
				fractal_burningship(v, g);
			else if (fractal == 4)
				fractal_feather(v, g);
		}
	}
	g->i = 0;
}

char    *fractal_name(int fractal)
{
    if (fractal = 1)
        return ("Mandelbrot");
     if (fractal = 2)
        return ("Julia");
    if (fractal = 3)
        return ("Burningship");
    if (fractal = 4)
        return ("Feather");        
}

void	user_interface_texts(t_varmlx *v, int fractal, int iteration)
{
	mlx_string_put(v->mlx, v->win, 1128, 8, v->tcolor, "Fractal:");
	mlx_string_put(v->mlx, v->win, 1128, 28, v->tcolor, fractal_name(fractal));
    mlx_string_put(v->mlx, v->win, 1128, 48, v->tcolor, "Mouse position/focus point:");
    mlx_string_put(v->mlx, v->win, 1128, 68, v->tcolor, "Real:");
    mlx_string_put(v->mlx, v->win, 1128, 88, v->tcolor, ft_itoa(v->mouse->x));
    mlx_string_put(v->mlx, v->win, 1128, 108, v->tcolor, "Imaginary:");
    mlx_string_put(v->mlx, v->win, 1128, 128, v->tcolor, ft_itoa(v->mouse->y));
    mlx_string_put(v->mlx, v->win, 1128, 148, v->tcolor, "Iteration:");
    mlx_string_put(v->mlx, v->win, 1128, 168, v->tcolor, ft_itoa(iteration));
}

void	mlx_draw(t_var *v, int x, int y, int clr)
{
	int tmp1;
	int tmp2;

	tmp1 = v->x;
	tmp2 = v->y;
	v->clr = ft_shade_color(clr, 0.20);
	while (v->x <= x && put_pixel(v, 0) == 0)
		v->x++;
	while (v->y <= y && put_pixel(v, 0) == 0)
		v->y++;
	while (v->x > tmp1 && put_pixel(v, 0) == 0)
		v->x--;
	while (v->y > tmp2 && put_pixel(v, 0) == 0)
		v->y--;
}

