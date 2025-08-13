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
#include <getopt.h>

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

void	parse_args(int argc, char **argv, t_env *env)
{
	int opt;
	static struct option long_options[] = {
		{"width", required_argument, 0, 'w'},
		{"height", required_argument, 0, 'h'},
		{"vsync", no_argument, 0, 'v'},
		{0, 0, 0, 0}
	};

	env->win_w = WIN_W;
	env->win_h = WIN_H;
	env->vsync = 0;
	while ((opt = getopt_long(argc, argv, "w:h:v", long_options, NULL)) != -1)
	{
		switch (opt)
		{
			case 'w':
				env->win_w = ft_atoi(optarg);
				break;
			case 'h':
				env->win_h = ft_atoi(optarg);
				break;
			case 'v':
				env->vsync = 1;
				break;
		}
	}
}

int		main(int argc, char **argv)
{
	t_glob		g;
	int		running = 1;

	parse_args(argc, argv, &g.env);
	if (optind < argc)
	{
		get_map(&g, argv[optind]);
		g.p.pos_x = 22;
		g.p.pos_y = 12;
		g.p.dir_x = -1;
		g.p.dir_y = 0;
		g.ray.plane_x = 0;
		g.ray.plane_y = 0.60;
		g.p.m_speed = 0.1;
		g.p.r_speed = 0.1;
		g.p.up = 0;
		g.p.down = 0;
		g.p.left = 0;
		g.p.right = 0;
		SDL_Init(SDL_INIT_VIDEO);
		g.env.win = SDL_CreateWindow("Wolf3D", SDL_WINDOWPOS_UNDEFINED,
				SDL_WINDOWPOS_UNDEFINED, g.env.win_w, g.env.win_h, SDL_WINDOW_SHOWN);
		g.env.ren = SDL_CreateRenderer(g.env.win, -1,
				g.env.vsync ? SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC : SDL_RENDERER_ACCELERATED);
		g.env.tex = SDL_CreateTexture(g.env.ren, SDL_PIXELFORMAT_ARGB8888,
				SDL_TEXTUREACCESS_STREAMING, g.env.win_w, g.env.win_h);
		g.env.pixels = (uint32_t*)malloc(sizeof(uint32_t) * (g.env.win_w * g.env.win_h));
		while (running)
		{
			handle_events(&g, &running);
			move(&g);
			loops_hook(&g);
			SDL_UpdateTexture(g.env.tex, NULL, g.env.pixels, g.env.win_w * sizeof(uint32_t));
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
