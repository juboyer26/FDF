/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juboyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 11:22:14 by juboyer           #+#    #+#             */
/*   Updated: 2019/06/14 10:03:11 by juboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t d;
	size_t s;

	d = 0;
	s = 0;
	while (dst[d] && d < dstsize)
	{
		d++;
	}
	while (src[s] && (d + s + 1) < (dstsize))
	{
		dst[d + s] = src[s];
		s++;
	}
	if (d != dstsize)
		dst[d + s] = '\0';
	return (d + (size_t)ft_strlen(src));
}
