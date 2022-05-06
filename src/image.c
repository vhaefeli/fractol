/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <vhaefeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 11:09:30 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/05/06 17:01:52 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// here the real numbers correspond to the -y axis and the imaginary to the x axis
void    zoom_focused(t_varmlx *v)
{
    int zoomstep;

    zoomstep = 1.5;
    if (v->i == 0)
    {
        v->scale = v->scale / zoomstep;
        v->cx = v->mouse->x - ((v->mouse->x - g->cx) * zoomstep);
        v->cy = v->mouse->y - ((v->mouse->y - g->cy) * zoomstep);
        v->i = 1;  
    }
    v->xi = (v->pxlpos->x - v->cx) * v->scale;
    v->yr = (- v->plxpos->y + v->cy) * v->scale;
}

void    convertmousepos(t_varmlx *v)
{
    v->mi = (v->mousepos->x - v->cx) * v->scale;
    v->mr = (- v->mouse->y + v->cy) * v->scale;
}