/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juboyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 07:19:38 by juboyer           #+#    #+#             */
/*   Updated: 2019/05/27 15:56:42 by juboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char			*str;
	unsigned char	replace;
	size_t			count;

	str = (char *)b;
	replace = c;
	count = 0;
	while (count < len)
	{
		str[count] = replace;
		count++;
	}
	return (b);
}
