/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 10:50:02 by arnovan-          #+#    #+#             */
/*   Updated: 2016/06/25 10:50:04 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		main(int argc, char **argv)
{
	t_glob		g;

	g.env.mlx = mlx_init();
	if (argc != 2)
		ft_error(2);
	else
		get_map(&g, argv[1]);
	g.env.win = mlx_new_window(g.env.mlx, WIN_W, WIN_H, "Dingo3D");
	g.p.posX = 22;
	g.p.posY = 12;
	g.p.dirX = -1;
	g.p.dirY = 0;
	g.ray.planeX = 0;
	g.ray.planeY = 0.60;
	g.p.mspeed = 0.1;
	g.p.rspeed = 0.1;

	//////////////DEBUG//////////////////
	int i = 0;
	while (i < 24)
	{
		int j = 0;
		while (j < 24)
		{
			printf("%d", g.env.map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	////////////////////////////////////
	printf("X: %d, Y: %d\n", g.env.ex, g.env.ey);
	mlx_hook(g.env.win, 2, (1L<<0), &key_press, &g); //Pass Player !env
	mlx_hook(g.env.win, 3, (1L<<1), &key_release, &g); //Pass Player !env
	mlx_hook(g.env.win, 17, 0L, &quitwin, &g.env);
	mlx_loop(g.env.mlx);
	free(g.env.map);
	return (0);
}
