/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 09:57:56 by arnovan-          #+#    #+#             */
/*   Updated: 2016/05/14 16:39:15 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*d;
	char	*s;
	size_t	n;
	size_t	length;

	d = (char *)dst;
	s = (char *)src;
	n = size;
	while (*d != '\0' && n--)
		d++;
	length = d - dst;
	n = size - length;
	if (n == 0)
		return (length + ft_strlen(s));
	while (*s != '\0')
	{
		if (n-- != 1)
			*d++ = *s;
		s++;
	}
	*d = '\0';
	return (length + (s - src));
}
