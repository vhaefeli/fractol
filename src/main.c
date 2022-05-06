/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <vhaefeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:22:47 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/05/06 17:01:36 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int error(int type)
{
	if (type = 1)
		ft_printf("not enough argument\n");
	else if (type = 2)
		ft_printf("wrong argument\n");
	else if (type = 3)
		ft_printf("too much arguments\n");
	ft_printf("the correct way is to put ''./fractol fractal_name''\n");
	ft_printf("for the fractal_name choose between:\n");
	ft_printf("mandelbrot julia burnigship feather\n");
	return (1);
}

static int	check(char **argv, t_varmlx *v)
{
	char *str;

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

static void		assign(t_varmlx *v)
{
	v->wwidth = WIN_W;
	v->wheight = WIN_H;
	v->bcolor = 0x3c3c3c;
	v->iwidth = IMG_W;
	v->iheight = IMG_H;
	v->ipos->x = 0;
	v->ipos->y = 0;
	v->icolor = 0x000000;
	v->tcolor = 0xeeeeee;
	v->tpos->x = IMG_W + 8;
	v->tpos->y = 8;
	v->pxlpos->x = 0;
	v->pxlpos->y = 0;
	v->mi = 0.285;
	v->mr = 0.013;
	v->scale = 3 / IMG_W;
	if (v->fractal == 1)
		v->ci = IMG_W / 3 * 2;
	else
		v->ci = IMG_W / 2;
	v->cr = IMG_H / 2;
	v->i = 0;
	v->mouseonoff = 0;
}

static void		init_win(t_varmlx *v)
{
	assign(v, w);
	v->mlx = mlx_init();
	v->win = mlx_new_window(v->mlx, -1, -1, WIN_W, WIN_H, "Fract-ol");
	mlx_expose_hook(v->win, expose_hook, v);
	mlx_hook(v->win, 6, 64, motion_hook, v);
	mlx_hook(v->win, 17, 0, close_hook, v);
	mlx_hook(v->win, 2, 0, key_hook, v);
	mlx_mouse_hook(v->win, mouse_hook, v);
	mlx_do_key_autorepeaton(v->mlx);
	mlx_loop(v->mlx);
	exit(0);
}

int	main (int argc, char **argv)
{
	t_varmlx	*v;
	
	v = (t_varmlx *)malloc(sizeof(t_varmlx));
	if (argc < 2)
		return (error(0));
	else if (argc > 2)
		return (error(3));
	else if (check(argv, v) > 0)
		return (error(2));
	else
		init_win(v);
	return (0);
}
