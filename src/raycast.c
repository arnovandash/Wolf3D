/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 13:18:20 by arnovan-          #+#    #+#             */
/*   Updated: 2016/06/26 14:19:07 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		loop_calc_3(t_glob *g)
{
	int half_h;

	half_h = g->env.win_h / 2;
	if (g->game.ray.side_dist_x < g->game.ray.side_dist_y)
	{
		g->game.ray.side_dist_x += g->game.ray.delta_dist_x;
		g->game.p.map_x += g->game.p.step_x;
		g->game.ray.side = 0;
	}
	else
	{
		g->game.ray.side_dist_y += g->game.ray.delta_dist_y;
		g->game.p.map_y += g->game.p.step_y;
		g->game.ray.side = 1;
	}
	if (g->env.map[g->game.p.map_x][g->game.p.map_y] > 0)
		g->game.ray.detect_wall = 1;
	if (g->game.ray.side == 0)
		g->game.ray.perp_wall_dist = (g->game.p.map_x - g->game.ray.ray_pos_x +
				(1 - g->game.p.step_x) / 2) / g->game.ray.ray_dir_x;
	else
		g->game.ray.perp_wall_dist = (g->game.p.map_y - g->game.ray.ray_pos_y +
				(1 - g->game.p.step_y) / 2) / g->game.ray.ray_dir_y;
	g->game.ray.line_height = (int)(g->env.win_h / g->game.ray.perp_wall_dist);
	g->game.ray.draw_start = -g->game.ray.line_height / 2 + half_h;
}

void		loop_calc_2(t_glob *g)
{
	if (g->game.ray.ray_dir_x < 0)
	{
		g->game.p.step_x = -1;
		g->game.ray.side_dist_x = (g->game.ray.ray_pos_x - g->game.p.map_x) *
			g->game.ray.delta_dist_x;
	}
	else
	{
		g->game.p.step_x = 1;
		g->game.ray.side_dist_x = (g->game.p.map_x + 1.0 - g->game.ray.ray_pos_x) *
			g->game.ray.delta_dist_x;
	}
	if (g->game.ray.ray_dir_y < 0)
	{
		g->game.p.step_y = -1;
		g->game.ray.side_dist_y = (g->game.ray.ray_pos_y - g->game.p.map_y) *
			g->game.ray.delta_dist_y;
	}
	else
	{
		g->game.p.step_y = 1;
		g->game.ray.side_dist_y = (g->game.p.map_y + 1.0 - g->game.ray.ray_pos_y) *
			g->game.ray.delta_dist_y;
	}
}

void		loop_calc_1(t_glob *g, float *x)
{
	g->game.ray.camera_x = 2 * *x / g->env.win_w - 1;
	g->game.ray.ray_pos_x = g->game.p.pos_x;
	g->game.ray.ray_pos_y = g->game.p.pos_y;
	g->game.ray.ray_dir_x = g->game.p.dir_x + g->game.ray.plane_x * g->game.ray.camera_x;
	g->game.ray.ray_dir_y = g->game.p.dir_y + g->game.ray.plane_y * g->game.ray.camera_x;
	g->game.p.map_x = (int)g->game.ray.ray_pos_x;
	g->game.p.map_y = (int)g->game.ray.ray_pos_y;
	g->game.ray.delta_dist_x = sqrt(1 + (g->game.ray.ray_dir_y * g->game.ray.ray_dir_y) /
			(g->game.ray.ray_dir_x * g->game.ray.ray_dir_x));
	g->game.ray.delta_dist_y = sqrt(1 + (g->game.ray.ray_dir_x * g->game.ray.ray_dir_x) /
			(g->game.ray.ray_dir_y * g->game.ray.ray_dir_y));
	g->game.ray.detect_wall = 0;
}
