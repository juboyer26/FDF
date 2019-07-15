/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juboyer <juboyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 13:35:53 by juboyer           #+#    #+#             */
/*   Updated: 2019/07/15 07:24:16 by juboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void        parse(t_env *env, int fd)
{
    char    *line;
    char    **line;
    int     i;
    line = (char *)malloc(sizeof(char *) )

}

void        read_map(t_env *env, char *filename)
{
    int fd;
+
    fd = open(filename, O_RDONLY);
    parse(env, fd);
    close(fd);
}
