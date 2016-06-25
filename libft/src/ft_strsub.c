/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 09:43:04 by arnovan-          #+#    #+#             */
/*   Updated: 2016/05/14 11:28:08 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	k;
	size_t	str_len;

	k = 0;
	i = start;
	str_len = ft_strlen(s);
	if (s == NULL)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (i > str_len - 1)
		return (NULL);
	while (i < len + start && s[i] != '\0')
	{
		str[k] = s[i];
		i++;
		k++;
	}
	str[k] = '\0';
	return (str);
}
