/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tool.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 11:59:19 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/04/26 12:25:28 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_TOOLS_H
# define MLX_TOOLS_H
# include "../libft/libft.h"


typedef struct s_varmlx
{
	void	*mlx;
	void	*win;
	int		bcolor;
	int		wwidth;
	int		wheight;
	void	*img;
	int		icolor;
	int		iwidth;
	int		iheight;
	t_pos	ipos;
	int		tcolor;
	t_pos	tpos;
	int		pxlcolor;
	t_pos	pxlpos;
	t_pos	mouse;
	int		zoom;
}	t_varmlx;

#endif
