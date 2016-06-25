/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 13:18:35 by arnovan-          #+#    #+#             */
/*   Updated: 2016/05/31 13:18:41 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*keep_track;
	t_list	*tracked;

	if (!alst || !*alst)
		return ;
	tracked = *alst;
	while (tracked)
	{
		keep_track = tracked->next;
		ft_lstdelone(&tracked, del);
		tracked = keep_track;
	}
	*alst = NULL;
}
