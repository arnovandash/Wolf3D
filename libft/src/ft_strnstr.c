/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 09:33:25 by arnovan-          #+#    #+#             */
/*   Updated: 2016/05/14 18:20:46 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_index(char const *big, char const *little, size_t length)
{
	int		i;
	int		j;
	size_t	k;

	i = 0;
	k = 0;
	while (big[i] != '\0' && k < length)
	{
		j = 0;
		while (big[i] == little[j] && k < length)
		{
			if (little[j + 1] == '\0')
				return (i - j);
			i++;
			j++;
			k++;
		}
		i = i - j;
		i++;
		k++;
	}
	return (-1);
}

char		*ft_strnstr(char const *big, char const *little, size_t length)
{
	int result;

	if (little[0] == '\0')
		return ((char *)big);
	result = ft_index(big, little, length);
	if (result != -1)
		return ((char *)&(big[result]));
	return (NULL);
}
