/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juboyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 10:51:08 by juboyer           #+#    #+#             */
/*   Updated: 2019/06/04 12:42:56 by juboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int x;

	x = 0;
	while (((unsigned char)s1[x] != '\0') &&
			((unsigned char)s1[x] == (unsigned char)s2[x]))
		x++;
	return ((unsigned char)s1[x] - (unsigned char)s2[x]);
}
