/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 06:52:23 by arnovan-          #+#    #+#             */
/*   Updated: 2016/05/14 13:47:22 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*ptr;
	char	*ret;

	ptr = (char*)malloc(sizeof(char) * (size + 1));
	ret = ptr;
	if (ptr == NULL)
		return (NULL);
	while (size--)
	{
		*ptr = '\0';
		ptr++;
	}
	*ptr = '\0';
	return (ret);
}
