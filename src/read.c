/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juboyer <juboyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 13:52:02 by juboyer           #+#    #+#             */
/*   Updated: 2019/07/20 15:30:12 by juboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int			ft_col_row(t_env *mlx, char *line)
{
	int		x;
	char	**tab;

	x = 0;
	tab = ft_strsplit(line, ' ');
	while (tab[x])
	{
		free(tab[x]);
		x++;
	}
	if (mlx->info.rows == 0)
		mlx->info.cols = x;
	else
	{
		if (x != mlx->info.cols)
			return (-1);
	}
	free(line);
	free(tab);
	mlx->info.rows++;
	return (0);
}
int			malloc_rows_cols(t_env *mlx)
{
	char	*line;
	int		ret;

	line = NULL;
	mlx->info.rows = 0;
	mlx->info.cols = 0;
	//ft_putendl("Check1 malloc func ");
	while ((ret = get_next_line(mlx->fd, &line)) > 0)
	{
		//ft_putendl("Check2 11malloc func ");
		if (ft_col_row(mlx, line) == -1)
			return (-1);
		//ft_putendl("Check2 12malloc func ");
	}
	//ft_putendl("Check2 malloc func ");
	mlx->map = ft_memalloc(sizeof(t_pixel*) * mlx->info.rows);
	close(mlx->fd);
	mlx->fd = open(mlx->name, O_RDONLY);
	//ft_putendl("Check3 malloc func ");
	printf("%d",mlx->info.cols);
	return (0);
}

int			read_map(t_env *mlx)
{
	char	*line;
	char	**tab;
	int		xytab[3];

	xytab[1] = 0;
	//ft_putendl("Check1");
	if (malloc_rows_cols(mlx) == -1)
		return (-1);
	//ft_putendl("Check2");
	while ((xytab[2] = get_next_line(mlx->fd, &line)) > 0)
	{
		xytab[0] = 0;
		tab = ft_strsplit(line, ' ');
		mlx->map[xytab[1]] = ft_memalloc(sizeof(t_pixel) * mlx->info.cols);
		while (tab[xytab[0]] != NULL)
		{
			mlx->map[xytab[1]][xytab[0]].x = xytab[0];
			mlx->map[xytab[1]][xytab[0]].y = xytab[1];
			mlx->map[xytab[1]][xytab[0]].z = atoi(tab[xytab[0]]);
			free(tab[xytab[0]]);
			xytab[0]++;
		}
		free(tab);
		free(line);
		xytab[1]++;
	}
	//ft_putendl("Check3");
	return ((xytab[2] == -1) ? -1 : 0);
}