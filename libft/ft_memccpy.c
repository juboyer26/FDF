/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juboyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:07:16 by juboyer           #+#    #+#             */
/*   Updated: 2019/06/05 11:43:07 by juboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*temdst;
	unsigned char	*temsrc;
	unsigned char	ch;
	size_t			i;

	temdst = (unsigned char*)dst;
	temsrc = (unsigned char*)src;
	ch = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		temdst[i] = temsrc[i];
		if (temsrc[i] == ch)
			return (temdst + i + 1);
		i++;
	}
	return (NULL);
}
