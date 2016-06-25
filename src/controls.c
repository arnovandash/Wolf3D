/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/29 13:43:24 by arnovan-          #+#    #+#             */
/*   Updated: 2016/06/25 09:14:17 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void turn(t_glob *g, char dir);

int		quitwin()
{
	exit(0);
}

int		key_press(int keycode, t_glob *g)
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
	loops_hook(g);
	mlx_clear_window(g->env.mlx, g->env.win);
	return (0);
}

int		key_release(int keycode, t_glob *g)
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

void		move(t_glob *g)
{
    if (g->p.up)
    {
        if (!(g->env.map[(int)(g->p.posX + g->p.dirX
                               * g->p.mspeed)][(int)(g->p.posY)]))
            g->p.posX += g->p.dirX * g->p.mspeed;
        if (!(g->env.map[(int)(g->p.posX)][(int)(g->p.posY
                                                       + g->p.dirY * g->p.mspeed)]))
            g->p.posY += g->p.dirY * g->p.mspeed;
    }
    if (g->p.left)
        turn(g, 'L');
    if (g->p.right)
        turn(g, 'R');
    if (g->p.down)
    {
        if (!(g->env.map[(int)(g->p.posX - g->p.dirX
                               * g->p.mspeed)][(int)(g->p.posY)]))
            g->p.posX -= g->p.dirX * g->p.mspeed;
        if (!(g->env.map[(int)(g->p.posX)][(int)(g->p.posY
                                                       - g->p.dirY * g->p.mspeed)]))
            g->p.posY -= g->p.dirY * g->p.mspeed;
    }
}

static void	turn(t_glob *g, char dir)
{
    double	tmpdir;
    double	tmpplane;
    int		coef;
    
    coef = 1;
    tmpdir = g->p.dirX;
    tmpplane = g->ray.planeX;
    if (dir == 'R')
        coef = -1;
    g->p.dirX = g->p.dirX * cos(coef * g->p.rspeed)
    - g->p.dirY * sin(coef * g->p.rspeed);
    g->p.dirY = tmpdir * sin(coef * g->p.rspeed)
    + g->p.dirY * cos(coef * g->p.rspeed);
    g->ray.planeX = g->ray.planeX * cos(coef * g->p.rspeed)
    - g->ray.planeY * sin(coef * g->p.rspeed);
    g->ray.planeY = tmpplane * sin(coef * g->p.rspeed)
    + g->ray.planeY * cos(coef * g->p.rspeed);
}
