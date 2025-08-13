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
	g->map.y = 0;
	while (get_next_line(fd, &g->map.buf))
	{
		g->map.x = 0;
		while (*(g->map.buf) != '\0')
		{
			if ((*(g->map.buf) >= '0') && (*(g->map.buf) <= '9'))
				g->map.x++;
			g->map.buf++;
		}
		g->map.y++;
	}
	
	g->env.map = (int **)malloc(sizeof(int *) * g->map.y);
	while (++g->map.i <= g->map.x)
		g->env.map[g->map.i] = (int *)malloc(sizeof(int) * g->map.x);
	if (g->env.map == NULL)
		ft_error(1);
	close(fd);
}

void	get_map(t_glob *g, char *file)
{
	char	*str;

	str = NULL;
	g->map.i = -1;
	g->env.fd = open(file, O_RDONLY);
	check_size(g, file);
	str = (char *)malloc(sizeof(char));
	g->map.y = 0;
	while (get_next_line(g->env.fd, &g->map.buf))
	{
		g->map.x = 0;
		while (*(g->map.buf) != '\0')
		{
			if ((*(g->map.buf) >= '0') && (*(g->map.buf) <= '9'))
			{
				str[0] = *(g->map.buf);
				g->env.map[g->map.y][g->map.x] = ft_atoi(str);
				g->map.x += 1;
			}
			g->map.buf++;
		}
		g->map.y += 1;
	}
	close(g->env.fd);
}
