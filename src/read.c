/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juboyer <juboyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 13:52:02 by juboyer           #+#    #+#             */
/*   Updated: 2019/07/27 12:50:48 by juboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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
	while ((ret = get_next_line(mlx->fd, &line)) > 0)
	{
		if (ft_col_row(mlx, line) == -1)
			return (-1);
	}
	mlx->map = ft_memalloc(sizeof(t_pixel*) * mlx->info.rows);
	close(mlx->fd);
	mlx->fd = open(mlx->name, O_RDONLY);
	return (0);
}

int			read_map(t_env *mlx)
{
	char	*line;
	char	**tab;
	int		xytab[3];

	xytab[1] = 0;
	//xytab[1] is our y coordinate so the first point needs to be (0,0,0)
	if (malloc_rows_cols(mlx) == -1)
		return (-1);
	//allcate memory based of the number of rows and cols
	//we get from using the maaloc_rows_cols function;
	while ((xytab[2] = get_next_line(mlx->fd, &line)) > 0)
	{
		//because the number we need is the height on the map
		//we use xytab[2] 
		xytab[0] = 0;
		//same for the x coordinate shold be initialised at 0;
		tab = ft_strsplit(line, ' ');
		//split the line based of spaces so as to have different arrays to work with 
		mlx->map[xytab[1]] = ft_memalloc(sizeof(t_pixel) * mlx->info.cols);
		//allocate the the variable in our header (**map) at y for the columns
		while (tab[xytab[0]] != NULL)
		{
			//run a loop that will assign the coordinate for each of the points 
			//begining at point (0,0, 0)
			mlx->map[xytab[1]][xytab[0]].x = xytab[0];
			mlx->map[xytab[1]][xytab[0]].y = xytab[1];
			//when we get the value of z we atoi it because GNL gets the string so we
			//need to convert to int to assign to our z in the header
			mlx->map[xytab[1]][xytab[0]].z = atoi(tab[xytab[0]]);
			free(tab[xytab[0]]);
			xytab[0]++;
			// the loop will run for the x first then will increment for the y
		}
		free(tab);
		free(line);
		xytab[1]++;
	}
	//based of the outcome of how GNL reads for our z which is xytab[2] it should return
	//-1 for an error or 0 that it has completed reading
	return ((xytab[2] == -1) ? -1 : 0);
}
