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

#define PLAYER_SIZE 0.2

/**
 * @brief This function checks if there is a wall at the given coordinates.
 * 
 * @param g The global state object.
 * @param x The x coordinate to check.
 * @param y The y coordinate to check.
 * @return int 1 if there is a wall, 0 otherwise.
 */
static int	is_wall(t_glob *g, double x, double y)
{
	if (x < 0 || x >= g->game.map.x || y < 0 || y >= g->game.map.y)
		return (1);
	return (g->env.map[(int)x][(int)y] > 0);
}

/**
 * @brief This function turns the player left or right.
 * 
 * @param g The global state object.
 * @param dir The direction to turn ('0' for left, '1' for right).
 */
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

/**
 * @brief This function moves the player.
 * 
 * @param g The global state object.
 */
void		move(t_glob *g)
{
	double move_x;
	double move_y;

	move_x = 0;
	move_y = 0;
	if (g->game.p.up) // Move forward (W)
	{
		move_x += g->game.p.dir_x * g->game.p.m_speed;
		move_y += g->game.p.dir_y * g->game.p.m_speed;
	}
	if (g->game.p.down) // Move backward (S)
	{
		move_x -= g->game.p.dir_x * g->game.p.m_speed;
		move_y -= g->game.p.dir_y * g->game.p.m_speed;
	}
	if (g->game.p.strafe_left) // Strafe left (A)
	{
		move_x -= g->game.p.dir_y * g->game.p.m_speed;
		move_y += g->game.p.dir_x * g->game.p.m_speed;
	}
	if (g->game.p.strafe_right) // Strafe right (D)
	{
		move_x += g->game.p.dir_y * g->game.p.m_speed;
		move_y -= g->game.p.dir_x * g->game.p.m_speed;
	}

	if (is_wall(g, g->game.p.pos_x + move_x + (move_x > 0 ? PLAYER_SIZE : -PLAYER_SIZE), g->game.p.pos_y))
		move_x = 0;
	if (is_wall(g, g->game.p.pos_x, g->game.p.pos_y + move_y + (move_y > 0 ? PLAYER_SIZE : -PLAYER_SIZE)))
		move_y = 0;

	g->game.p.pos_x += move_x;
	g->game.p.pos_y += move_y;

	if (g->game.p.left) // Turn left (Q)
		turn(g, '0');
	if (g->game.p.right) // Turn right (E)
		turn(g, '1');
}
