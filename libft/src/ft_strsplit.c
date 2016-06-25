/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 13:32:43 by arnovan-          #+#    #+#             */
/*   Updated: 2016/05/31 13:32:48 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_parts(char const *s, char c)
{
	int	substring;
	int	cnt;

	substring = 0;
	cnt = 0;
	while (*s != '\0')
	{
		if (substring == 1 && *s == c)
			substring = 0;
		if (substring == 0 && *s != c)
		{
			substring = 1;
			cnt += 1;
		}
		s++;
	}
	return (cnt);
}

static int	ft_wordlen(char const *s, char c)
{
	int	len;

	len = 0;
	while (*s != '\0' && *s != c)
	{
		len += 1;
		s++;
	}
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		index;
	int		words;

	index = 0;
	words = ft_count_parts(s, c);
	str = (char **)malloc(sizeof(*str) * words + 1);
	if (str == NULL)
		return (NULL);
	while (words--)
	{
		while (*s == c && *s != '\0')
			s++;
		str[index] = ft_strsub(s, 0, ft_wordlen(s, c));
		if (str[index] == NULL)
			return (NULL);
		s = s + ft_wordlen(s, c);
		index += 1;
	}
	str[index] = NULL;
	return (str);
}
