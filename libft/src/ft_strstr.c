/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 09:29:58 by arnovan-          #+#    #+#             */
/*   Updated: 2016/05/14 18:10:51 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find_index(char const *big, char const *little)
{
	int	i;
	int	j;

	i = 0;
	while (big[i] != '\0')
	{
		j = 0;
		while (big[i] == little[j])
		{
			if (little[j + 1] == '\0')
				return (i - j);
			i++;
			j++;
		}
		i = i - j;
		i++;
	}
	return (-1);
}

char		*ft_strstr(char const *big, char const *little)
{
	int	re;

	if (little[0] == '\0')
		return ((char *)big);
	re = ft_find_index(big, little);
	if (re != -1)
		return ((char *)&(big[re]));
	return (NULL);
}
