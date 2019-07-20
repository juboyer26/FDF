/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juboyer <juboyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 15:48:02 by juboyer           #+#    #+#             */
/*   Updated: 2019/07/20 15:39:07 by juboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
int my_key_funct(int keycode)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

void	init_mlx(t_env *mlx)
{
	mlx->info.check = 0;
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, W_W, W_H, "Fdf");
	//mlx->image = init_img(mlx);
	mlx->anglex = 0;
	mlx->angley = 0;
	mlx->scale = 4;
	mlx->depth = 1;
	mlx->move_lr = 1;
	mlx->move_ud = 1;
	mlx->depth_max = 2;
	mlx->depth_min = -2;
	mlx_key_hook(mlx->win_ptr, my_key_funct, mlx);
	//mlx_expose_hook(mlx->win, expose_hook, mlx);
	//mlx_hook(mlx->win, MOUSE_DOWN, 0, &mouse_down, mlx);
	//mlx_hook(mlx->win, MOUSE_MOVE, 0, &ft_rotate_map, mlx);
	mlx_loop(mlx->mlx_ptr);
}

void	init(t_env *mlx)
{
	if (read_map(mlx) == -1)
	{
		ft_putendl("ERROR 404 JUSTINE MESSED UP");
		return ;
	}
	else
		ft_putendl("GG JUSTINE");
	init_mlx(mlx);
}

int	exit_button(void)
{
	exit(1);
	return (0);
}

int main(int argc, char **argv)
{
	t_env v;

	// v.mlx_ptr = mlx_init();
	// v.win_ptr = mlx_new_window(v.mlx_ptr, 500, 500, "FDF");
	if (argc != 2)
	{
		printf("Invalid parameters\n");
		printf("usage : ./fdf map");
	}
	else
	{
		v.name = argv[1];
		v.fd = v.fd = open(v.name, O_RDONLY);
		init(&v);
		// mlx_key_hook(v.win_ptr, my_key_funct, 0);
		// mlx_hook(v.win_ptr, 17, 0L, exit_button, &v);
		// mlx_loop(v.mlx_ptr);
	}
	return (0);
}
