/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juboyer <juboyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 12:24:02 by juboyer           #+#    #+#             */
/*   Updated: 2019/07/27 13:49:05 by juboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_line(t_env *mlx, t_pixel *p1, t_pixel *p2)
{
	int i[2];
	int e2;
	int color;

	mlx->info.bres = bres_const(p1, p2);
	//gets the slope between two points using the bresenhem algo
	i[0] = p1->d2x;
	i[1] = p1->d2y;
	//assigns the values to the array for both the x and y
	while (1)
	{
		color = choose_color(get_highest(p1, p2, mlx));
		//gets the hgihest point on the map so to make it 
		//a different color than the rest -
		set_pixel(mlx->image, create_x(mlx, i[0]), create_y(mlx, i[1]), color);
		if (i[0] == p2->d2x && i[1] == p2->d2y)
			break ;
		if ((e2 = mlx->info.bres->err) > -(mlx->info.bres->dx))
		{
			mlx->info.bres->err -= mlx->info.bres->dy;
			i[0] += mlx->info.bres->sx;
		}
		if (e2 < mlx->info.bres->dy)
		{
			mlx->info.bres->err += mlx->info.bres->dx;
			i[1] += mlx->info.bres->sy;
		}
	}
	free(mlx->info.bres);
}

void	ft_render(t_env *mlx)
{
	int x;
	int	y;

	y = 0;
	while (y < mlx->info.rows)
	{
		//while the lines hae been read by gnl we use the y to run a loop over them
		//the loop runs from the x and y to the next point x and y + 1
		x = 0;
		while (x < mlx->info.cols)
		{
			//and we use the x to run a loop for the columns and a line 
			//from the x and y to the next point whivh will be x + 1 and y
			if (x < mlx->info.cols - 1)
				draw_line(mlx, &(mlx->map[y][x]), &(mlx->map[y][x + 1]));
			if (y < mlx->info.rows - 1)
				draw_line(mlx, &(mlx->map[y][x]), &(mlx->map[y + 1][x]));
			x++;
		}
		y++;
	}
}
