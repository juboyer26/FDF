/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juboyer <juboyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 09:19:00 by juboyer           #+#    #+#             */
/*   Updated: 2019/07/20 15:15:24 by juboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		newl(char **s, char **line, int fd, int ret)
{
	int		len;
	char	*tmp;

	len = 0;
	while (s[fd][len] != '\n' && s[fd][len] != '\0')
		len++;
	if (s[fd][len] == '\n')
	{
		*line = ft_strsub(s[fd], 0, len);
		tmp = strdup(s[fd] + len + 1);
		free(s[fd]);
		s[fd] = tmp;
		if (s[fd][0]  == '\0')
			ft_strdel(&s[fd]);
	}
	else if (s[fd][len] == '\0')
	{
		*line = strdup(s[fd]);
		ft_strdel(&s[fd]);
		if (ret == BUFF_SIZE)
			return (0);
	}
	return (1);

}
int		outp(char **s, char **line, int fd, int ret)
{
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (s[fd] == NULL || s[fd][0] == '\0'))
		return (0);
	return(newl(s, line, fd, ret));
}

int		get_next_line(const int fd, char **line)
{
	char		*tmp;
	static char *fd_arr[1024];
	int			ret;
	char		*buf;

	if (fd < 0 || line == NULL)
		return (-1);
	buf = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1 ));
	buf[BUFF_SIZE] = '\0';
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (fd_arr[fd] == NULL)
			fd_arr[fd] = ft_strnew(1);
		tmp = ft_strjoin(fd_arr[fd], buf);
		free(fd_arr[fd]);
		fd_arr[fd] = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	free(buf);
	return (outp(fd_arr, line, fd, ret));
}
