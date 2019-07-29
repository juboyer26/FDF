/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juboyer <juboyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 13:21:16 by juboyer           #+#    #+#             */
/*   Updated: 2019/07/27 13:21:48 by juboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		mouse_down(int button, int x, int y, t_env *mlx)
{
	(void)x;
	if (y < 0)
		return (0);
	mlx->mouse.button1 = 0;
	mlx->mouse.button1 = button;
	return (0);
}

int		ft_rotate_map(int x, int y, t_env *mlx)
{
	mlx->mouse.lastx = mlx->mouse.x;
	mlx->mouse.lasty = mlx->mouse.y;
	mlx->mouse.x = x;
	mlx->mouse.y = y;
	if (mlx->mouse.button1 == 1)
	{
		mlx->anglex += (double)((mlx->mouse.lasty - mlx->mouse.y) / 200.0f);
		mlx->angley -= (double)((mlx->mouse.lastx - mlx->mouse.x) / 200.0f);
		erase(mlx);
	}
	return (0);
}