/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juboyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 11:17:50 by juboyer           #+#    #+#             */
/*   Updated: 2019/07/05 15:18:22 by juboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>


int my_key_funct(int keycode, void *mlx)
{
	mlx = NULL;
	printf("key event %d\n", keycode );
//	mlx_pixel_put(mlx, window, 300, 300, 0xFF00FF);
//	to handle the key input for the program to respond towards to
	if (keycode == 53)
		exit(0);
	return (0);
}

int main()
{
	void *mlx;
	void *window;
	int x;
	int y;

	mlx = mlx_init();
	window = mlx_new_window(mlx, 500, 500, "File 1");
	y = 50;
	while (y < 150)
	{
		x = 50;
		while (x < 150)
		{
			mlx_pixel_put(mlx, window, x, y, 0xFF0000);
			x++;
		}
		y++;
	}
	mlx_key_hook(window, my_key_funct, 0);
	mlx_loop(mlx);
}
