/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <vhaefeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:21:41 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/05/04 13:28:24 by vhaefeli         ###   ########.fr       */
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

void	draw_fractal(t_var *v)
{
	v->y = -1;
	v->nam = ft_strjoin("Fractal : ", ft_firstupper(v->ftl[v->num - 1]));
	v->len = WIN_W - 50 - ft_strlen(v->nam) * 10;
	rotate_fractal(v, v->rot);
	while (++v->y < WIN_H && (v->x = -1) == -1)
	{
		while (++v->x < WIN_W)
		{
			if (v->num == 1)
				fractal_julia(v);
			else if (v->num == 2)
				fractal_mandelbrot(v);
			else if (v->num == 3)
				fractal_mandelbrot(v);
		}
	}
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
    int     i;
    int     j;
    char    **text_interface;

    text_interface = ft_interfacetext(v, fractal, iteration);
	mlx_string_put(v->mlx, v->win, v->tpos->x, v->tpos->y, v->tcolor, "Fractal:");
	mlx_string_put(v->mlx, v->win, v->tpos->x, v->tpos->y + 20, v->tcolor, fractal_name(fractal));
    mlx_string_put(v->mlx, v->win, v->tpos->x, v->tpos->y + 40, v->tcolor, "Mouse position/focus point:");
    mlx_string_put(v->mlx, v->win, v->tpos->x, v->tpos->y + 60, v->tcolor, "Real:");
    mlx_string_put(v->mlx, v->win, v->tpos->x, v->tpos->y, v->tcolor, ft_itoa(v->mouse->x));
    mlx_string_put(v->mlx, v->win, v->tpos->x, v->tpos->y, v->tcolor, "Imaginary:");
    mlx_string_put(v->mlx, v->win, v->tpos->x, v->tpos->y, v->tcolor, ft_itoa(v->mouse->y));
    mlx_string_put(v->mlx, v->win, v->tpos->x, v->tpos->y, v->tcolor, "Iteration:");
    mlx_string_put(v->mlx, v->win, v->tpos->x, v->tpos->y, v->tcolor, ft_itoa(iteration));
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

