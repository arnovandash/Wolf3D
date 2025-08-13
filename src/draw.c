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

static void	draw_pixel(t_glob *g, int x, int y, int color)
{
	if (x >= 0 && x < g->env.win_w && y >= 0 && y < g->env.win_h)
		g->env.pixels[y * g->env.win_w + x] = color;
}

static int	get_wall_color(t_glob *g)
{
	if (g->game.ray.side == 1)
	{
		if (g->env.map[g->game.p.map_x][g->game.p.map_y] == 1)
			return (0xFFE65764);
		if (g->env.map[g->game.p.map_x][g->game.p.map_y] == 2)
			return (0xFFB96414);
		if (g->env.map[g->game.p.map_x][g->game.p.map_y] == 3)
			return (0xFF50873C);
		if (g->env.map[g->game.p.map_x][g->game.p.map_y] == 4)
			return (0xFFCDFA0A);
	}
	else
	{
		if (g->env.map[g->game.p.map_x][g->game.p.map_y] == 1)
			return (0xFFDC2D2D);
		if (g->env.map[g->game.p.map_x][g->game.p.map_y] == 2)
			return (0xFFDC78DC);
		if (g->env.map[g->game.p.map_x][g->game.p.map_y] == 3)
			return (0xFF9B8764);
		if (g->env.map[g->game.p.map_x][g->game.p.map_y] == 4)
			return (0xFF82C81E);
	}
	return (0);
}

static void	draw_background(t_glob *g)
{
	int x;
	int y;
	int half_h;

	half_h = g->env.win_h / 2;
	y = 0;
	while (y < g->env.win_h)
	{
		x = 0;
		while (x < g->env.win_w)
		{
			if (y < half_h)
				draw_pixel(g, x, y, COLOR_CEILING);
			else
				draw_pixel(g, x, y, COLOR_FLOOR);
			x++;
		}
		y++;
	}
}

void		render(t_glob *g)
{
	float		x;
	int		y;
	int		color;
	int		half_h;

	half_h = g->env.win_h / 2;
	draw_background(g);
	x = 0;
	while (x < g->env.win_w)
	{
		loop_calc_1(g, &x);
		loop_calc_2(g);
		while (g->game.ray.detect_wall == 0)
		{
			loop_calc_3(g);
		}
		g->game.ray.draw_start < 0 ? g->game.ray.draw_start = 0 : 0;
		g->game.ray.draw_end = g->game.ray.line_height / 2 + half_h;
		g->game.ray.draw_end >= g->env.win_h ? g->game.ray.draw_end = g->env.win_h - 1 : 0;
		color = get_wall_color(g);
		y = g->game.ray.draw_start;
		while (y <= g->game.ray.draw_end)
		{
			draw_pixel(g, x, y, color);
			y++;
		}
		x++;
	}
}
