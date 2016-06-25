/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 10:50:14 by arnovan-          #+#    #+#             */
/*   Updated: 2016/06/25 10:50:21 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		loop_calc_3(t_glob *g)
{
	//jump to next map square, OR in x-direction, OR in y-direction
	if (g->ray.sideDistX < g->ray.sideDistY)
	{
		g->ray.sideDistX += g->ray.deltaDistX;
		g->p.mapX += g->p.stepX;
		g->ray.side = 0;
	}
	else
	{
		g->ray.sideDistY += g->ray.deltaDistY;
		g->p.mapY += g->p.stepY;
		g->ray.side = 1;
	}
	//Check if ray has hit a wall
	if (g->env.map[g->p.mapX][g->p.mapY] > 0)
		g->ray.detect_wall = 1;
	if (g->ray.side == 0)
		g->ray.perpWallDist = (g->p.mapX - g->ray.rayPosX +
				(1 - g->p.stepX) / 2) / g->ray.rayDirX;
	else
		g->ray.perpWallDist = (g->p.mapY - g->ray.rayPosY +
				(1 - g->p.stepY) / 2) / g->ray.rayDirY;
	
	//Calculate heig->t of line to draw on screen
	g->ray.lineHeight = (int)(WIN_H / g->ray.perpWallDist);
	//calculate lowest and hig->est pixel to fill in current stripe
	g->ray.drawStart = -g->ray.lineHeight / 2 + WIN_H / 2;
}

void		loop_calc_2(t_glob *g)
{
	if (g->ray.rayDirX < 0)
	{
		g->p.stepX = -1;
		g->ray.sideDistX = (g->ray.rayPosX - g->p.mapX) * g->ray.deltaDistX;
	}
	else
	{
		g->p.stepX = 1;
		g->ray.sideDistX = (g->p.mapX + 1.0 - g->ray.rayPosX) *
			g->ray.deltaDistX;
	}
	if (g->ray.rayDirY < 0)
	{
		g->p.stepY = -1;
		g->ray.sideDistY = (g->ray.rayPosY - g->p.mapY) * g->ray.deltaDistY;
	}
	else
	{
		g->p.stepY = 1;
		g->ray.sideDistY = (g->p.mapY + 1.0 - g->ray.rayPosY) *
			g->ray.deltaDistY;
	}
}

void		loop_calc_1(t_glob *g, float *x)
{
	//ray_calc
	//calculate ray position and direction
	g->ray.cameraX = 2 * *x / WIN_W - 1; //x-coordinate in camera space
	g->ray.rayPosX = g->p.posX;
	g->ray.rayPosY = g->p.posY;
	g->ray.rayDirX = g->p.dirX + g->ray.planeX * g->ray.cameraX;
	g->ray.rayDirY = g->p.dirY + g->ray.planeY * g->ray.cameraX;
	//which box of the map we're in
	g->p.mapX = (int)g->ray.rayPosX;
	g->p.mapY = (int)g->ray.rayPosY;
	//leng->h of ray from current position to next x or y-side.
	//double sideDistX;
	//double sideDistY;
	//leng->h of ray from one x or y-side to next x or y-side
	g->ray.deltaDistX = sqrt(1 + (g->ray.rayDirY * g->ray.rayDirY) /
			(g->ray.rayDirX * g->ray.rayDirX));
	g->ray.deltaDistY = sqrt(1 + (g->ray.rayDirX * g->ray.rayDirX) /
			(g->ray.rayDirY * g->ray.rayDirY));
	//double perpWallDist;
	//what direction to step in x or y-direction (either +1 or -1)
	//int stepX;
	//int stepY;
	g->ray.detect_wall = 0; //was there a wall hit?
	//g->ray.side; //was a NS or a EW wall hit?
	//calculate step and initial sideDist
}


int			loops_hook(t_glob *g)
{
	float		x;

	x = 0;
	while(x < WIN_W)
	{
		loop_calc_1(g, &x);
		loop_calc_2(g);

		//perform DDA
		while (g->ray.detect_wall == 0)
		{
			loop_calc_3(g);
			if (g->ray.drawStart < 0)
				g->ray.drawStart = 0;
			g->ray.drawEnd = g->ray.lineHeight / 2 + WIN_H / 2;
			if (g->ray.drawEnd >= WIN_H)
				g->ray.drawEnd = WIN_H - 1;
		}

		//  DRAW FUNCTION CALL PROTOTYPE
		//  draw_line(x, drawStart, drawEnd


		/////////////////////// DRAW FUNCTION ////////////
		int y = g->ray.drawStart;
		while (y <= g->ray.drawEnd)
		{
			mlx_pixel_put(g->env.mlx, g->env.win, x, y, 0x00FF00);
			y++;
		}
		x += 0.5;
		//////////////////////////////////////////////////	
	}
	return (0);
}
