/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juboyer <juboyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 14:19:12 by juboyer           #+#    #+#             */
/*   Updated: 2019/07/21 14:21:30 by juboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		rotate(t_env *mlx, t_rot_point *rp)
{
	rp->px = cos(mlx->angley) * rp->act_px + sin(mlx->angley) * rp->act_pz;
	rp->pz = -sin(mlx->angley) * rp->act_px + cos(mlx->angley) * rp->act_pz;
	rp->py = cos(mlx->anglex) * rp->act_py - sin(mlx->anglex) * rp->pz;
}

void		ft_calculate(t_env *mlx, t_pixel *pt)
{
	t_rot_point *rp;

	rp = (t_rot_point *)malloc(sizeof(t_rot_point));
	rp->act_px = (double)(pt->x - ((mlx->info.cols - 1) / 2));
	rp->act_py = (double)(pt->y - ((mlx->info.rows - 1) / 2));
	rp->act_pz = (double)(pt->z * mlx->depth);
	rotate(mlx, rp);
	rp->px *= mlx->scale;
	rp->py *= mlx->scale;
	pt->d2x = cnv_dbl_int(rp->px - rp->py + (W_W / 2));
	pt->d2y = cnv_dbl_int(rp->pz + rp->px + rp->py + (W_H / 2));
	free(rp);
}


void		calcule_coord(t_env *mlx)
{
	int i;
	int j;

	j = 0;
	while (j < mlx->info.rows)
	{
		i = 0;
		while (i < mlx->info.cols)
		{
			ft_calculate(mlx, &(mlx->map[j][i]));
			i++;
		}
		j++;
	}
	ft_render(mlx);
}
