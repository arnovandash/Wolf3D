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

void		handle_events(t_glob *g, int *running)
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
			*running = 0;
		else if (event.type == SDL_KEYDOWN)
		{
			if (event.key.keysym.sym == SDLK_ESCAPE)
				*running = 0;
			key_press(event.key.keysym.sym, g);
		}
		else if (event.type == SDL_KEYUP)
			key_release(event.key.keysym.sym, g);
	}
}

int		main(int argc, char **argv)
{
	t_glob		g;
	int		running = 1;

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
		SDL_Init(SDL_INIT_VIDEO);
		g.env.win = SDL_CreateWindow("Wolf3D", SDL_WINDOWPOS_UNDEFINED,
				SDL_WINDOWPOS_UNDEFINED, WIN_W, WIN_H, SDL_WINDOW_SHOWN);
		g.env.ren = SDL_CreateRenderer(g.env.win, -1, SDL_RENDERER_ACCELERATED);
		g.env.tex = SDL_CreateTexture(g.env.ren, SDL_PIXELFORMAT_ARGB8888,
				SDL_TEXTUREACCESS_STREAMING, WIN_W, WIN_H);
		g.env.pixels = (uint32_t*)malloc(sizeof(uint32_t) * (WIN_W * WIN_H));
		while (running)
		{
			handle_events(&g, &running);
			move(&g);
			loops_hook(&g);
			SDL_UpdateTexture(g.env.tex, NULL, g.env.pixels, WIN_W * sizeof(uint32_t));
			SDL_RenderCopy(g.env.ren, g.env.tex, NULL, NULL);
			SDL_RenderPresent(g.env.ren);
		}
		free(g.env.pixels);
		SDL_DestroyTexture(g.env.tex);
		SDL_DestroyRenderer(g.env.ren);
		SDL_DestroyWindow(g.env.win);
		SDL_Quit();
		free(g.env.map);
	}
	else
		ft_error(2);
	return (0);
}