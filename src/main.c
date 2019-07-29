/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juboyer <juboyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 15:48:02 by juboyer           #+#    #+#             */
/*   Updated: 2019/07/27 13:44:24 by juboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/fdf.h"
int my_key_funct(int keycode, t_env *mlx)
{
	if (keycode == 53)
		exit(0);
	ft_depth(keycode, mlx);
	ft_scale(keycode, mlx);
	ft_xy_trans(keycode, mlx);
	return (0);
}

void	erase(t_env *mlx)
{
	clear_image(mlx);
	expose_hook(mlx);
}

void	init_mlx(t_env *mlx)
{
	mlx->info.check = 0;
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, W_W, W_H, "Fdf");
	mlx->image = init_img(mlx);
	mlx->anglex = 0;
	mlx->angley = 0;
	mlx->scale = 8;
	mlx->depth = -1;
	mlx->move_lr = 1;
	mlx->move_ud = 1;
	mlx->depth_max = -2;
	mlx->depth_min = 2;
	mlx_key_hook(mlx->win_ptr, my_key_funct, mlx);
	mlx_expose_hook(mlx->win_ptr, expose_hook, mlx);
	mlx_hook(mlx->win_ptr, MOUSE_DOWN, 0, &mouse_down, mlx);
	mlx_hook(mlx->win_ptr, MOUSE_MOVE, 0, &ft_rotate_map, mlx);
	mlx_loop(mlx->mlx_ptr);
}

void	init(t_env *mlx)
{
	if (read_map(mlx) == -1)
	{
		ft_putendl("MAP ERROR");
		return ;
	}
	else
	{
		init_mlx(mlx);
	}
}

int	exit_button(void)
{
	exit(1);
	return (0);
}

int main(int argc, char **argv)
{
	t_env v;

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
	}
	return (0);
}
