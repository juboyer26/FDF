/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juboyer <juboyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 13:48:36 by juboyer           #+#    #+#             */
/*   Updated: 2019/07/21 13:50:21 by juboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
void	set_pixel(t_image *image, int x, int y, int color)
{
	if (x < 0 || y < 0 || x >= W_W - 1 || y >= W_H - 1)
		return ;
	*(int *)(image->ptr + ((x + y * W_W) * image->bpp)) = color;
}

void	clear_image(t_env *mlx)
{
	ft_bzero(mlx->image->ptr, W_W * W_H * mlx->image->bpp);
}

t_image	*del_image(t_image *image, t_env *mlx)
{
	if (image != NULL)
	{
		if (image->image != NULL)
			mlx_destroy_image(mlx->mlx_ptr, image->image);
		ft_memdel((void **)&image);
	}
	return (NULL);
}

t_image	*init_img(t_env *mlx)
{
	t_image	*img;

	if (!(img = (t_image *)malloc(sizeof(t_image))))
		return (NULL);
	if (!(img->image = mlx_new_image(mlx->mlx_ptr, W_W, W_H)))
		return (del_image(img, mlx));
	img->ptr = mlx_get_data_addr(img->image, &img->bpp,
		&img->sizel, &img->endian);
	img->bpp /= 8;
	return (img);
}