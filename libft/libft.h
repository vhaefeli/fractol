/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <vhaefeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:23:04 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/05/14 15:42:20 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_pos
{
	double			x;
	double			y;
	double			z;
}	t_pos;

typedef struct s_complex
{
	long double	r;
	long double	i;
}	t_complex;


typedef struct s_list
{
	void			*content;
	char			*src;
	int				nbr;
	int				position;
	struct s_list	*next;
}	t_list;


char	*ft_strtolower(char *src);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_itoa(int n);
int		ft_printf(const char *src, ...);

#endif
