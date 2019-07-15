/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juboyer <juboyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 15:48:02 by juboyer           #+#    #+#             */
/*   Updated: 2019/07/14 13:34:56 by juboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// int fun(t_env *env)
// {
// 	int y = 0;
// 	int x;
// 	while (y < 3)
// 	{
// 		x = 0;
// 		while (x < 3)
// 		{
// 			printf("%i, %i : %lf\n", y, x, env->map[y][x]);
// 			x++;
// 		}
// 		y++;
// 	}
// 	return 0;
// }

int my_key_funct(int keycode)
{
//	printf("key event %d\n", keycode );
//	mlx_pixel_put(mlx, window, 300, 300, 0xFF00FF);
//	to handle the key input for the program to respond towards to
	if (keycode == 53)
		exit(0);
	return (0);
}

int	exit_button(void)
{
	exit(1);
	return (0);
}

int main(int argc, char **argv)
{
	t_env v;

	v.mlx_ptr = mlx_init();
	v.win_ptr = mlx_new_window(v.mlx_ptr, 500, 500, "FDF");
	// v.map[0][0] = 0;
	// v.map[0][1] = 0;
	// v.map[0][2] = 0;

	// v.map[1][0] = 0;
	// v.map[1][1] = 1;
	// v.map[1][2] = 0;

	// v.map[2][0] = 0;
	// v.map[2][1] = 0;
	// v.map[2][2] = 0;
	if (argc != 2)
	{
		printf("Invalid parameters\n");
		printf("usage : ./fdf map");
	}
	else
	{
		argv = NULL;
		//mlx_loop_hook(v.mlx_ptr, fun, &v);
		mlx_key_hook(v.win_ptr, my_key_funct, 0);
    	mlx_hook(v.win_ptr, 17, 0L, exit_button, &v);
    	mlx_loop(v.mlx_ptr);
	}
	return (0);
}
