/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 13:18:20 by arnovan-          #+#    #+#             */
/*   Updated: 2016/06/25 15:56:46 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		loop_calc_3(t_glob *g)
{
	if (g->ray.side_dist_x < g->ray.side_dist_y)
	{
		g->ray.side_dist_x += g->ray.delta_dist_x;
		g->p.map_x += g->p.step_x;
		g->ray.side = 0;
	}
	else
	{
		g->ray.side_dist_y += g->ray.delta_dist_y;
		g->p.map_y += g->p.step_y;
		g->ray.side = 1;
	}
	if (g->env.map[g->p.map_x][g->p.map_y] > 0)
		g->ray.detect_wall = 1;
	if (g->ray.side == 0)
		g->ray.perp_wall_dist = (g->p.map_x - g->ray.ray_pos_x +
				(1 - g->p.step_x) / 2) / g->ray.ray_dir_x;
	else
		g->ray.perp_wall_dist = (g->p.map_y - g->ray.ray_pos_y +
				(1 - g->p.step_y) / 2) / g->ray.ray_dir_y;
	g->ray.line_height = (int)(WIN_H / g->ray.perp_wall_dist);
	g->ray.draw_start = -g->ray.line_height / 2 + WIN_H / 2;
}

void		loop_calc_2(t_glob *g)
{
	if (g->ray.ray_dir_x < 0)
	{
		g->p.step_x = -1;
		g->ray.side_dist_x = (g->ray.ray_pos_x - g->p.map_x) *
			g->ray.delta_dist_x;
	}
	else
	{
		g->p.step_x = 1;
		g->ray.side_dist_x = (g->p.map_x + 1.0 - g->ray.ray_pos_x) *
			g->ray.delta_dist_x;
	}
	if (g->ray.ray_dir_y < 0)
	{
		g->p.step_y = -1;
		g->ray.side_dist_y = (g->ray.ray_pos_y - g->p.map_y) *
			g->ray.delta_dist_y;
	}
	else
	{
		g->p.step_y = 1;
		g->ray.side_dist_y = (g->p.map_y + 1.0 - g->ray.ray_pos_y) *
			g->ray.delta_dist_y;
	}
}

void		loop_calc_1(t_glob *g, float *x)
{
	g->ray.camera_x = 2 * *x / WIN_W - 1;
	g->ray.ray_pos_x = g->p.pos_x;
	g->ray.ray_pos_y = g->p.pos_y;
	g->ray.ray_dir_x = g->p.dir_x + g->ray.plane_x * g->ray.camera_x;
	g->ray.ray_dir_y = g->p.dir_y + g->ray.plane_y * g->ray.camera_x;
	g->p.map_x = (int)g->ray.ray_pos_x;
	g->p.map_y = (int)g->ray.ray_pos_y;
	g->ray.delta_dist_x = sqrt(1 + (g->ray.ray_dir_y * g->ray.ray_dir_y) /
			(g->ray.ray_dir_x * g->ray.ray_dir_x));
	g->ray.delta_dist_y = sqrt(1 + (g->ray.ray_dir_x * g->ray.ray_dir_x) /
			(g->ray.ray_dir_y * g->ray.ray_dir_y));
	g->ray.detect_wall = 0;
}

int			loops_hook(t_glob *g)
{
	float		x;

	x = 0;
	while(x < WIN_W)
	{
		loop_calc_1(g, &x);
		loop_calc_2(g);
		while (g->ray.detect_wall == 0)
		{
			loop_calc_3(g);
			if (g->ray.draw_start < 0)
				g->ray.draw_start = 0;
			g->ray.draw_end = g->ray.line_height / 2 + WIN_H / 2;
			if (g->ray.draw_end >= WIN_H)
				g->ray.draw_end = WIN_H - 1;
		}

		int y = g->ray.draw_start;
		while (y <= g->ray.draw_end)
		{
			if (g->ray.side == 1)
			{
				if (g->env.map[g->p.map_x][g->p.map_y] == 1)
					g->env.color = RED1;
				if (g->env.map[g->p.map_x][g->p.map_y] == 2)
					g->env.color = GREEN1;
				if (g->env.map[g->p.map_x][g->p.map_y] == 3)
					g->env.color = BLUE1;
				if (g->env.map[g->p.map_x][g->p.map_y] == 4)
					g->env.color = PURPLE1;
				if (g->env.map[g->p.map_x][g->p.map_y] == 5)
					g->env.color = YELLOW1;
			}

			if (g->ray.side == 0)
			{
				if (g->env.map[g->p.map_x][g->p.map_y] == 1)
					g->env.color = RED2;
				if (g->env.map[g->p.map_x][g->p.map_y] == 2)
					g->env.color = GREEN2;
				if (g->env.map[g->p.map_x][g->p.map_y] == 3)
					g->env.color = BLUE2;
				if (g->env.map[g->p.map_x][g->p.map_y] == 4)
					g->env.color = PURPLE2;
				if (g->env.map[g->p.map_x][g->p.map_y] == 5)
					g->env.color = YELLOW2;
			}

			printf("the poo %c \n", g->env.data[y]);
		memcpy(&g->env.data[(int)x * 4 + y * g->env.size_line], 
									&g->env.color, sizeof(int));


/*
 *{
				if (g->env.map[g->p.map_x][g->p.map_y] == 1)
					mlx_pixel_put(g->env.mlx, g->env.win, x, y, RED1);
				if (g->env.map[g->p.map_x][g->p.map_y] == 2)
					mlx_pixel_put(g->env.mlx, g->env.win, x, y, GREEN1);
				if (g->env.map[g->p.map_x][g->p.map_y] == 3)
					mlx_pixel_put(g->env.mlx, g->env.win, x, y, BLUE1);
				if (g->env.map[g->p.map_x][g->p.map_y] == 4)
					mlx_pixel_put(g->env.mlx, g->env.win, x, y, PURPLE1);
				if (g->env.map[g->p.map_x][g->p.map_y] == 5)
					mlx_pixel_put(g->env.mlx, g->env.win, x, y, YELLOW1);
			}

			if (g->ray.side == 0)
			{
				if (g->env.map[g->p.map_x][g->p.map_y] == 1)
					mlx_pixel_put(g->env.mlx, g->env.win, x, y, RED2);
				if (g->env.map[g->p.map_x][g->p.map_y] == 2)
					mlx_pixel_put(g->env.mlx, g->env.win, x, y, GREEN2);
				if (g->env.map[g->p.map_x][g->p.map_y] == 3)
					mlx_pixel_put(g->env.mlx, g->env.win, x, y, BLUE2);
				if (g->env.map[g->p.map_x][g->p.map_y] == 4)
					mlx_pixel_put(g->env.mlx, g->env.win, x, y, PURPLE2);
				if (g->env.map[g->p.map_x][g->p.map_y] == 5)
					mlx_pixel_put(g->env.mlx, g->env.win, x, y, YELLOW2);
			}


*/


			y++;
		}
		x += 0.5;
	}
	mlx_put_image_to_window(g->env.mlx, g->env.win, g->env.img, 0, 0);
//	mlx_destroy_image(g->env.mlx, g->env.img);
	return (0);
}
