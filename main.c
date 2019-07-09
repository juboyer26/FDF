/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juboyer <juboyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 15:48:02 by juboyer           #+#    #+#             */
/*   Updated: 2019/07/09 16:23:46 by juboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


int my_key_funct(int keycode)
{
	printf("key event %d\n", keycode );
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
	if (argc != 2)
	{
		printf("Invalid parameters\n");
		printf("usage : ./fdf map");
	}
	else
	{
		argv = NULL;
		//mlx_loop_hook(v.mlx_ptr, fun, &env);
		mlx_key_hook(v.win_ptr, my_key_funct, 0);
    	mlx_hook(v.win_ptr, 17, 0L, exit_button, &v);
    	mlx_loop(v.mlx_ptr);
	}
	return (0);
}