/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tool.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <vhaefeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 11:59:19 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/05/11 16:04:10 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_TOOLS_H
# define MLX_TOOLS_H
# include "../libft/libft.h"


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
	int			scale;
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

#endif
