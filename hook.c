/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juboyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 08:51:22 by juboyer           #+#    #+#             */
/*   Updated: 2019/07/14 09:01:14 by juboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int exitfun(void)
{
    exit(0);
    return 0;
}
int main()
{
	t_env env;
	env.mlx_ptr = mlx_init();
	env.mlx_ptr = mxl_new_window(env.mlx_ptr, 500, 500, "test");
	mlx_key_hook(window, my_key_funct, 0);
	mlx_hook(env.win_ptr, 17, 0l, exitfun, &env);
	mlx_loop(env.mlx_ptr);
	return (0);
}
