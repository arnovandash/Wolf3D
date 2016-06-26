/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 13:35:35 by arnovan-          #+#    #+#             */
/*   Updated: 2016/06/26 13:03:15 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		main(int argc, char **argv)
{
	t_glob		g;

	if (argc == 2)
	{
		get_map(&g, argv[1]);
		g.p.pos_x = 22;
		g.p.pos_y = 12;
		g.p.dir_x = -1;
		g.p.dir_y = 0;
		g.ray.plane_x = 0;
		g.ray.plane_y = 0.60;
		g.p.m_speed = 0.1;
		g.p.r_speed = 0.1;
		g.env.mlx = mlx_init();
		g.env.win = mlx_new_window(g.env.mlx, WIN_W, WIN_H, "Dingo3D");
		mlx_hook(g.env.win, 2, (1L << 0), &key_press, &g);
		mlx_hook(g.env.win, 3, (1L << 1), &key_release, &g);
		mlx_hook(g.env.win, 17, 0L, &quitwin, &g.env);
		mlx_loop(g.env.mlx);
		free(g.env.map);
	}
	else
		ft_error(2);
	return (0);
}
