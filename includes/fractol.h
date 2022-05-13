/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <vhaefeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 08:50:29 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/05/12 14:29:50 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "keys.h"
# include "mlx.h"
# include <math.h>

# define WIN_W 2320
# define WIN_H 1280

# define IMG_W 2120
# define IMG_H 1280

# define MID_W IMG_W / 2
# define MID_H IMG_H / 2

# define MIN_J -3.20
# define MAX_J 3.200

typedef struct s_varmlx
{
	void		*mlx;
	void		*win;
	int			bcolor;
	int			wwidth;
	int			wheight;
	void		*img;
	char		*imgdata;
	int			bpp;
	int			size_line;
	int			endian;
	int			icolor;
	int			iwidth;
	int			iheight;
	t_pos		ipos;
	int			tcolor;
	t_pos		tpos;
	int			pxlcolor;
	t_pos		pxlpos;
	t_pos		mouse;
	long double	scale;
	int			mouseonoff;
	int         i;
	int			fractal;
	long double mi;
	long double mr;
	long double	xi;
    long double	yr;
    long double	cx;
    long double cy;
	int			itmax;
}	t_varmlx;

void	ft_shade_color(t_varmlx *v, int i);
int		put_pixel(t_varmlx *v);
void	draw_fractal(t_varmlx *v);
char    *fractal_name(int fractal);
void	user_interface_texts(t_varmlx *v);

void	fractal_mandelbrot(t_varmlx	*v);
void	fractal_julia(t_varmlx *v);
void	fractal_burningship(t_varmlx *v);
void	fractal_feather(t_varmlx *v);

int		expose_hook(t_varmlx *v);
int		key_hook(int keycode, t_varmlx *v);
int		mouse_hook(int button, int x, int y, t_varmlx *v);
int		close_hook(int button, t_varmlx *v);
int		motion_hook(int x, int y, t_varmlx *v);

void		assign(t_varmlx *v);

#endif
