/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 13:50:32 by arnovan-          #+#    #+#             */
/*   Updated: 2016/05/31 13:50:36 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	size_t	i;

	if ((str = (char*)malloc(sizeof(char) * ft_strlen(s) + 1)) == NULL)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s))
	{
		str[i] = f(s[i]);
		i += 1;
	}
	return (str);
}
