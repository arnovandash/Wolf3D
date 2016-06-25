/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 15:27:19 by arnovan-          #+#    #+#             */
/*   Updated: 2016/06/05 14:42:05 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*temp;

	i = 0;
	temp = (char*)s;
	while (i < n)
	{
		if (temp[i] == (unsigned char)c)
			return (&temp[i]);
		i++;
	}
	return (0);
}
