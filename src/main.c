/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <vhaefeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:22:47 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/05/16 15:54:31 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_error(int type)
{
	if (type == 1)
		ft_printf("not enough argument\n");
	else if (type == 2)
		ft_printf("wrong argument\n");
	else if (type == 3)
		ft_printf("too much arguments\n");
	ft_printf("the correct way is to put ''./fractol fractal_name''\n");
	ft_printf("for the fractal_name choose between:\n");
	ft_printf("mandelbrot julia burnigship feather\n");
	return (1);
}

static int	check(char **argv, t_varmlx *v)
{
	char	*str;

	str = ft_strtolower(argv[1]);
	if (ft_strcmp(str, "mandelbrot") == 0)
		v->fractal = 1;
	else if (ft_strcmp(str, "julia") == 0)
		v->fractal = 2;
	else if (ft_strcmp(str, "burningship") == 0)
		v->fractal = 3;
	else if (ft_strcmp(str, "feather") == 0)
		v->fractal = 4;
	else
		return (1);
	return (0);
}

void	assign(t_varmlx *v)
{
	v->wwidth = WIN_W;
	v->wheight = WIN_H;
	v->bcolor = 0x3c3c3c;
	v->iwidth = IMG_W;
	v->iheight = IMG_H;
	v->ipos.x = 0.;
	v->ipos.y = 0.;
	v->icolor = 0x000000;
	v->tcolor = 0xeeeeee;
	v->tpos.x = IMG_W + 8.;
	v->tpos.y = 8.;
	v->pxlpos.x = 0.;
	v->pxlpos.y = 0.;
	v->scale = 4.;
	v->itmax = 30;
	v->mouseonoff = 0;
	assign_fractal(v);
}

void	assign_fractal(t_varmlx *v)
{
	v->cy = IMG_H / 2;
	if (v->fractal == 1)
		v->cx = IMG_W / 3 * 2;
	if (v->fractal == 2)
	{
		v->cx = IMG_W / 2;
		v->mr = 0.285;
		v->mi = 0.013;
	}
	if (v->fractal == 3)
	{
		v->itmax = 20;
		v->scale = 0.5;
		v->cx = IMG_W * 4;
		v->cy = IMG_H / 3 * 2;
		v->mr = 0.312;
		v->mi = 0.469;
	}
	if (v->fractal == 4)
	{
		v->scale = 20.;
		v->cx = IMG_W / 2;
		v->mr = 0.0566;
		v->mi = 0.6226;
	}
}

int	main(int argc, char **argv)
{
	t_varmlx	*v;

	v = (t_varmlx *)malloc(sizeof(t_varmlx));
	if (argc < 2)
		return (ft_error(0));
	else if (argc > 2)
		return (ft_error(3));
	else if (check(argv, v) > 0)
		return (ft_error(2));
	else
		init_win(v);
	return (0);
}
