/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 14:27:05 by arnovan-          #+#    #+#             */
/*   Updated: 2016/06/25 14:27:18 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	check_size(t_glob *g, char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error(3);
	g->game.map.y = 0;
	while (get_next_line(fd, &g->game.map.buf))
	{
		g->game.map.x = 0;
		while (*(g->game.map.buf) != '\0')
		{
			if ((*(g->game.map.buf) >= '0') && (*(g->game.map.buf) <= '9'))
				g->game.map.x++;
			g->game.map.buf++;
		}
		g->game.map.y++;
	}
	
	g->env.map = (int **)malloc(sizeof(int *) * g->game.map.y);
	while (++g->game.map.i <= g->game.map.x)
		g->env.map[g->game.map.i] = (int *)malloc(sizeof(int) * g->game.map.x);
	if (g->env.map == NULL)
		ft_error(1);
	close(fd);
}

void	get_map(t_glob *g, char *file)
{
	char	*str;

	str = NULL;
	g->game.map.i = -1;
	g->env.fd = open(file, O_RDONLY);
	check_size(g, file);
	str = (char *)malloc(sizeof(char));
	g->game.map.y = 0;
	while (get_next_line(g->env.fd, &g->game.map.buf))
	{
		g->game.map.x = 0;
		while (*(g->game.map.buf) != '\0')
		{
			if ((*(g->game.map.buf) >= '0') && (*(g->game.map.buf) <= '9'))
			{
				str[0] = *(g->game.map.buf);
				g->env.map[g->game.map.y][g->game.map.x] = ft_atoi(str);
				g->game.map.x += 1;
			}
			g->game.map.buf++;
		}
		g->game.map.y += 1;
	}
	close(g->env.fd);
}