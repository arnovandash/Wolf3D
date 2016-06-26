/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/26 12:07:18 by arnovan-          #+#    #+#             */
/*   Updated: 2016/06/26 14:35:20 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void		set_color_west_east(t_glob *g, int x, int y)
{
	if (g->env.map[g->p.map_x][g->p.map_y] == 1)
	{
		g->env.data[((int)x * 4) + (y * g->env.size_line) + 2] = 100;
		g->env.data[((int)x * 4) + (y * g->env.size_line) + 1] = 87;
		g->env.data[((int)x * 4) + (y * g->env.size_line)] = 230;
	}
	if (g->env.map[g->p.map_x][g->p.map_y] == 2)
	{
		g->env.data[((int)x * 4) + (y * g->env.size_line) + 2] = 20;
		g->env.data[((int)x * 4) + (y * g->env.size_line) + 1] = 100;
		g->env.data[((int)x * 4) + (y * g->env.size_line)] = 185;
	}
	if (g->env.map[g->p.map_x][g->p.map_y] == 3)
	{
		g->env.data[((int)x * 4) + (y * g->env.size_line) + 2] = 60;
		g->env.data[((int)x * 4) + (y * g->env.size_line) + 1] = 135;
		g->env.data[((int)x * 4) + (y * g->env.size_line)] = 80;
	}
	if (g->env.map[g->p.map_x][g->p.map_y] == 4)
	{
		g->env.data[((int)x * 4) + (y * g->env.size_line) + 2] = 10;
		g->env.data[((int)x * 4) + (y * g->env.size_line) + 1] = 250;
		g->env.data[((int)x * 4) + (y * g->env.size_line)] = 205;
	}
}

void		set_color_north_south(t_glob *g, int x, int y)
{
	if (g->env.map[g->p.map_x][g->p.map_y] == 1)
	{
		g->env.data[((int)x * 4) + (y * g->env.size_line) + 2] = 60;
		g->env.data[((int)x * 4) + (y * g->env.size_line) + 1] = 45;
		g->env.data[((int)x * 4) + (y * g->env.size_line)] = 220;
	}
	if (g->env.map[g->p.map_x][g->p.map_y] == 2)
	{
		g->env.data[((int)x * 4) + (y * g->env.size_line) + 2] = 100;
		g->env.data[((int)x * 4) + (y * g->env.size_line) + 1] = 160;
		g->env.data[((int)x * 4) + (y * g->env.size_line)] = 220;
	}
	if (g->env.map[g->p.map_x][g->p.map_y] == 3)
	{
		g->env.data[((int)x * 4) + (y * g->env.size_line) + 2] = 100;
		g->env.data[((int)x * 4) + (y * g->env.size_line) + 1] = 235;
		g->env.data[((int)x * 4) + (y * g->env.size_line)] = 155;
	}
	if (g->env.map[g->p.map_x][g->p.map_y] == 4)
	{
		g->env.data[((int)x * 4) + (y * g->env.size_line) + 2] = 30;
		g->env.data[((int)x * 4) + (y * g->env.size_line) + 1] = 200;
		g->env.data[((int)x * 4) + (y * g->env.size_line)] = 130;
	}
}

int			loops_hook(t_glob *g)
{
	float		x;
	int			y;

	x = 0;
	while (x < WIN_W)
	{
		loop_calc_1(g, &x);
		loop_calc_2(g);
		while (g->ray.detect_wall == 0)
		{
			loop_calc_3(g);
			g->ray.draw_start < 0 ? g->ray.draw_start = 0 : 0;
			g->ray.draw_end = g->ray.line_height / 2 + WIN_H / 2;
			g->ray.draw_end >= WIN_H ? g->ray.draw_end = WIN_H - 1 : 0;
		}
		y = g->ray.draw_start;
		while (y <= g->ray.draw_end)
		{
			g->ray.side == 1 ? set_color_west_east(g, x, y) : NULL;
			g->ray.side == 0 ? set_color_north_south(g, x, y) : NULL;
			y++;
		}
		x += 0.5;
	}
	return (0);
}
