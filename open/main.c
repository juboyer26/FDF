/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juboyer <juboyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 14:33:05 by juboyer           #+#    #+#             */
/*   Updated: 2019/07/04 16:27:14 by juboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

int		main(void)
{
	void *mlx;
	void *window;
  
  	mlx = mlx_init();
  	window = mlx_new_window(mlx, 500, 500, "Title");

	int x = 25 ;
	int x1 = 25 ; 
	while (x < 200)
	{
		/* code */
	
		mlx_pixel_put (mlx, window, x, x1, 0x0FFB6C1);
		//mlx_pixel_put (mlx, window, x1, 27, 0x0FFD700);
		x++;
		x1++;
		//mlx_pixel_put (mlx, window, 50, 50, 0x0ffffff);
	
	}
	x = 200;
	x1 = 25;
	while (x > 25)
		{
			/* code */
	
		mlx_pixel_put (mlx, window, x, x1, 0x0FF1493);
		//mlx_pixel_put (mlx, window, x1, 27, 0x0FFD700);
		x--;
		x1++;
		//mlx_pixel_put (mlx, window, 50, 50, 0x0ffffff);
	
		}	
  	x = 100;
	//x1 = 25;
	while (x > 200)
		{
			/* code */
	
		mlx_pixel_put (mlx, window, x, 25, 0x0ff0000);
		//mlx_pixel_put (mlx, window, x1, 27, 0x0FFD700);
		x++;
		//x1++;
		//mlx_pixel_put (mlx, window, 50, 50, 0x0ffffff);
		}
	mlx_loop(mlx);
	return (0);
}