/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 10:07:26 by arnovan-          #+#    #+#             */
/*   Updated: 2016/05/25 10:51:37 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	char			*c1;
	const char		*c2;

	i = 0;
	c1 = dst;
	c2 = src;
	while (i < n)
	{
		c1[i] = c2[i];
		if (c2[i] == c)
		{
			return (void *)&(c1[i + 1]);
		}
		i++;
	}
	return (NULL);
}
