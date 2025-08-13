/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 13:31:16 by arnovan-          #+#    #+#             */
/*   Updated: 2016/06/26 11:56:36 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	turn(t_glob *g, char dir)
{
	double	tmpdir;
	double	tmpplane;
	int		coef;

	coef = 1;
	tmpdir = g->game.p.dir_x;
	tmpplane = g->game.ray.plane_x;
	if (dir == '1')
		coef = -1;
	g->game.p.dir_x = g->game.p.dir_x * cos(coef * g->game.p.r_speed)
		- g->game.p.dir_y * sin(coef * g->game.p.r_speed);
	g->game.p.dir_y = tmpdir * sin(coef * g->game.p.r_speed)
		+ g->game.p.dir_y * cos(coef * g->game.p.r_speed);
	g->game.ray.plane_x = g->game.ray.plane_x * cos(coef * g->game.p.r_speed)
		- g->game.ray.plane_y * sin(coef * g->game.p.r_speed);
	g->game.ray.plane_y = tmpplane * sin(coef * g->game.p.r_speed)
		+ g->game.ray.plane_y * cos(coef * g->game.p.r_speed);
}

void		move(t_glob *g)
{
	if (g->game.p.up)
	{
		if (!(g->env.map[(int)(g->game.p.pos_x + g->game.p.dir_x
						* g->game.p.m_speed)][(int)(g->game.p.pos_y)]))
			g->game.p.pos_x += g->game.p.dir_x * g->game.p.m_speed;
		if (!(g->env.map[(int)(g->game.p.pos_x)][(int)(g->game.p.pos_y
						+ g->game.p.dir_y * g->game.p.m_speed)]))
			g->game.p.pos_y += g->game.p.dir_y * g->game.p.m_speed;
	}
	if (g->game.p.left)
		turn(g, '0');
	if (g->game.p.right)
		turn(g, '1');
	if (g->game.p.down)
	{
		if (!(g->env.map[(int)(g->game.p.pos_x - g->game.p.dir_x
						* g->game.p.m_speed)][(int)(g->game.p.pos_y)]))
			g->game.p.pos_x -= g->game.p.dir_x * g->game.p.m_speed;
		if (!(g->env.map[(int)(g->game.p.pos_x)][(int)(g->game.p.pos_y
						- g->game.p.dir_y * g->game.p.m_speed)]))
			g->game.p.pos_y -= g->game.p.dir_y * g->game.p.m_speed;
	}
}