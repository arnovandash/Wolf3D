/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:arnovan-<arnovan-@student.wethinkcode.co.za>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 14:27:05 by arnovan-          #+#    #+#             */
/*   Updated: 2025/08/19 12:29:32 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief This function reads the map file and stores it in a 2D array.
 * 
 * @param g The global state object.
 * @param file The name of the map file.
 */
void	get_map(t_glob *g, char *file)
{
	FILE	*fp;
	char	buf[1024];
	int		fd;
	int		max_x = 0;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		error(3);
	fp = fdopen(fd, "r");
	if (fp == NULL)
		error(3);

	// First pass to get the dimensions of the map
	g->game.map.y = 0;
	while (fgets(buf, sizeof(buf), fp))
	{
		g->game.map.x = 0;
		for (int i = 0; buf[i]; i++)
		{
			if (buf[i] >= '0' && buf[i] <= '9')
				g->game.map.x++;
		}
		if (g->game.map.x > max_x)
			max_x = g->game.map.x;
		g->game.map.y++;
	}
	g->game.map.x = max_x;

	// Allocate memory for the map
	g->env.map = (int **)malloc(sizeof(int *) * g->game.map.y);
	for (int i = 0; i < g->game.map.y; i++)
		g->env.map[i] = (int *)malloc(sizeof(int) * g->game.map.x);
	if (g->env.map == NULL)
		error(1);

	// Second pass to read the map data
	rewind(fp);
	g->game.map.y = 0;
	while (fgets(buf, sizeof(buf), fp))
	{
		g->game.map.x = 0;
		for (int i = 0; buf[i]; i++)
		{
			if (buf[i] >= '0' && buf[i] <= '9')
			{
				g->env.map[g->game.map.y][g->game.map.x] = buf[i] - '0';
				g->game.map.x++;
			}
		}
		g->game.map.y++;
	}
	fclose(fp);
}
