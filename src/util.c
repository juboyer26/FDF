/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juboyer <juboyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 14:03:46 by juboyer           #+#    #+#             */
/*   Updated: 2019/07/27 13:49:09 by juboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

//converts double to int
int		cnv_dbl_int(double num)
{
	int		i;
	double	j;

	i = (int)num;
	j = num - (double)i;
	if (j <= 0.5)
		return (i);
	else
		return (i + 1);
}

int		expose_hook(t_env *mlx)
{
	//gets all the coordinates and the puts the image with the drawn coordinates
	//to the window
	calcule_coord(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->image->image, 0, 0);
	return (0);
}

int		choose_color(int p1)
{
	if (p1 == 0)
		return (GREEN);
	else if (p1 > 0 && p1 < 5)
		return (MAROON);
	else if (p1 >= 5 && p1 < 10)
		return (RED);
	else if (p1 >= 10 && p1 < 14)
		return (ORANGE);
	else if (p1 >= 14 && p1 <= 20)
		return (YELLOW);
	else if (p1 > 20)
		return (WHITE);
	else if (p1 < 0 && p1 > -10)
		return (LIME);
	else if (p1 <= -10 && p1 > -14)
		return (AQUA);
	else if (p1 <= -14 && p1 >= -20)
		return (BLUE);
	else if (p1 < -20)
		return (NAVY);
	return (SILVER);
}

int		get_highest(t_pixel *p1, t_pixel *p2, t_env *mlx)
{
	if (p1->z > p2->z)
		return (p1->z * mlx->depth);
	return (p2->z * mlx->depth);
}

int		ft_abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}
