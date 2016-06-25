/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 09:33:39 by arnovan-          #+#    #+#             */
/*   Updated: 2016/05/14 16:39:45 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		length;

	length = ft_strlen(s);
	dest = (char*)malloc(sizeof(char) * length);
	if (dest == NULL)
		return (NULL);
	return (ft_strcpy(dest, s));
}
