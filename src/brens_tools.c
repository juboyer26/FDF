/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brens_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juboyer <juboyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 14:02:10 by juboyer           #+#    #+#             */
/*   Updated: 2019/07/21 14:02:57 by juboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		create_x(t_env *win, int x)
{
	return (x + win->move_lr);
}

int		create_y(t_env *win, int y)
{
	return (y + win->move_ud);
}

t_bres	*bres_const(t_pixel *p1, t_pixel *p2)
{
	t_bres	*bres;

	bres = (t_bres *)malloc(sizeof(t_bres));
	bres->dx = ft_abs(p2->d2x - p1->d2x);
	bres->sx = p1->d2x < p2->d2x ? 1 : -1;
	bres->dy = ft_abs(p2->d2y - p1->d2y);
	bres->sy = p1->d2y < p2->d2y ? 1 : -1;
	bres->err = (bres->dx > bres->dy ? bres->dx : -bres->dy) / 2;
	return (bres);
}