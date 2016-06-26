/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 13:31:16 by arnovan-          #+#    #+#             */
/*   Updated: 2016/06/26 11:56:36 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int				quitwin(void)
{
	exit(0);
}

int				key_press(int keycode, t_glob *g)
{
	if (keycode == KB_ESC)
		exit(0);
	if (keycode == KB_LEFT)
		g->p.left = 1;
	if (keycode == KB_RIGHT)
		g->p.right = 1;
	if (keycode == KB_UP)
		g->p.up = 1;
	if (keycode == KB_DOWN)
		g->p.down = 1;
	move(g);
	g->env.img = mlx_new_image(g->env.mlx, WIN_W, WIN_H);
	g->env.data = mlx_get_data_addr(g->env.img, &g->env.bpp, &g->env.size_line,
			&g->env.endian);
	loops_hook(g);
	mlx_put_image_to_window(g->env.mlx, g->env.win, g->env.img, 0, 0);
	return (0);
}

int				key_release(int keycode, t_glob *g)
{
	if (keycode == KB_LEFT)
		g->p.left = 0;
	if (keycode == KB_RIGHT)
		g->p.right = 0;
	if (keycode == KB_UP)
		g->p.up = 0;
	if (keycode == KB_DOWN)
		g->p.down = 0;
	return (0);
	g->env.fd = 0;
}

static void		turn(t_glob *g, char dir)
{
	double	tmpdir;
	double	tmpplane;
	int		coef;

	coef = 1;
	tmpdir = g->p.dir_x;
	tmpplane = g->ray.plane_x;
	if (dir == '1')
		coef = -1;
	g->p.dir_x = g->p.dir_x * cos(coef * g->p.r_speed)
		- g->p.dir_y * sin(coef * g->p.r_speed);
	g->p.dir_y = tmpdir * sin(coef * g->p.r_speed)
		+ g->p.dir_y * cos(coef * g->p.r_speed);
	g->ray.plane_x = g->ray.plane_x * cos(coef * g->p.r_speed)
		- g->ray.plane_y * sin(coef * g->p.r_speed);
	g->ray.plane_y = tmpplane * sin(coef * g->p.r_speed)
		+ g->ray.plane_y * cos(coef * g->p.r_speed);
}

void			move(t_glob *g)
{
	if (g->p.up)
	{
		if (!(g->env.map[(int)(g->p.pos_x + g->p.dir_x
						* g->p.m_speed)][(int)(g->p.pos_y)]))
			g->p.pos_x += g->p.dir_x * g->p.m_speed;
		if (!(g->env.map[(int)(g->p.pos_x)][(int)(g->p.pos_y
						+ g->p.dir_y * g->p.m_speed)]))
			g->p.pos_y += g->p.dir_y * g->p.m_speed;
	}
	if (g->p.left)
		turn(g, '0');
	if (g->p.right)
		turn(g, '1');
	if (g->p.down)
	{
		if (!(g->env.map[(int)(g->p.pos_x - g->p.dir_x
						* g->p.m_speed)][(int)(g->p.pos_y)]))
			g->p.pos_x -= g->p.dir_x * g->p.m_speed;
		if (!(g->env.map[(int)(g->p.pos_x)][(int)(g->p.pos_y
						- g->p.dir_y * g->p.m_speed)]))
			g->p.pos_y -= g->p.dir_y * g->p.m_speed;
	}
}
