/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carre.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:25:37 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/03/18 16:15:52 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// programme test de la minilibx et du makefile

#include "mlx.h"
#include "libft.h"

int main (void)
{
	void	*mlx_ptr;
//	void	*img_ptr;
	void	*win_ptr;
//	char	*str;
	int		color;
	int		i = 50;
	int		j = 50;

	color = 0x000000;
	mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 610, 610, "Le beau carre");
	while(j++ < 560)
	{
		if (j%2 == 0)
			color += 0x10000;

		while(i++ < 562)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, i, j, color);
			if (i%2 == 0)
				color += 0x010101;
		}
		i = 50;
	}
   mlx_loop(mlx_ptr);
}
