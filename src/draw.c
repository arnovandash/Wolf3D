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

void		draw_pixel(t_glob *g, int x, int y, int color)
{
	if (x >= 0 && x < g->env.win_w && y >= 0 && y < g->env.win_h)
		g->env.pixels[y * g->env.win_w + x] = color;
}

void		set_color_west_east(t_glob *g, int x, int y)
{
	int color;

	if (g->env.map[g->p.map_x][g->p.map_y] == 1)
		color = 0xFFE65764;
	if (g->env.map[g->p.map_x][g->p.map_y] == 2)
		color = 0xFFB96414;
	if (g->env.map[g->p.map_x][g->p.map_y] == 3)
		color = 0xFF50873C;
	if (g->env.map[g->p.map_x][g->p.map_y] == 4)
		color = 0xFFCDFA0A;
	draw_pixel(g, x, y, color);
}

void		set_color_north_south(t_glob *g, int x, int y)
{
	int color;

	if (g->env.map[g->p.map_x][g->p.map_y] == 1)
		color = 0xFFDC2D2D;
	if (g->env.map[g->p.map_x][g->p.map_y] == 2)
		color = 0xFFDC78DC;
	if (g->env.map[g->p.map_x][g->p.map_y] == 3)
		color = 0xFF9B8764;
	if (g->env.map[g->p.map_x][g->p.map_y] == 4)
		color = 0xFF82C81E;
	draw_pixel(g, x, y, color);
}

int			loops_hook(t_glob *g)
{
	float		x;
	int			y;

	x = 0;
	ft_memset(g->env.pixels, 0, g->env.win_w * g->env.win_h * sizeof(uint32_t));
	while (x < g->env.win_w)
	{
		loop_calc_1(g, &x);
		loop_calc_2(g);
		while (g->ray.detect_wall == 0)
		{
			loop_calc_3(g);
			g->ray.draw_start < 0 ? g->ray.draw_start = 0 : 0;
			g->ray.draw_end = g->ray.line_height / 2 + g->env.win_h / 2;
			g->ray.draw_end >= g->env.win_h ? g->ray.draw_end = g->env.win_h - 1 : 0;
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
