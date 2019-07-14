/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juboyer <juboyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 15:11:52 by juboyer           #+#    #+#             */
/*   Updated: 2019/07/14 10:45:58 by juboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "fdf.h"

int		count(const char *line)
{
	int count;
	int i;
	int len;
	char lastchar;

	i = 0;
	count = 0;
	len = ft_strlen(line);
	if (len > 0)
		lastchar = line[0];
	while (i <= len)
	{
		if (line[i] == ' ' || line[i] == '\0' && lastchar != ' ')
			count++;
		lastchar = line[i];
		i++;
	}
	return (count);
}

int		getinfo(char *pathname, int c)
{
	int fd;
	int ret;
	char *line;

	ret = 0;
	fd = open(pathname, O_RDONLY);
	if (c == 1)
	{
		while (get_next_line(fd, &line) > 0)
			ret++;
		close (fd);
	}
	else
	{
		get_next_line(fd, &line);
		ret = count(line);
		while (get_next_line(fd, &line) > 0)
		{
			if (count(line) != ret)
				exit_error(1);
		}
		close (fd);
	}
	return (ret);
}

void	p_args(char * filepath, t_env *env)
{
	int index;

	index = 0;
	env->height = getinfo(filepath, 1);
	env->width = getinfo(filepath, 2);
	env->map = (t_point **)malloc(sizeof(t_point) * env->width);
	while (index < env->height)
	{
		env->map[index] = (t_point *)malloc(sizeof(t_point) *env->width);
		index++;
	}
}


