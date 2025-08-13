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
	if (keycode == SDLK_LEFT || keycode == SDLK_a)
		g->game.p.left = 1;
	if (keycode == SDLK_RIGHT || keycode == SDLK_d)
		g->game.p.right = 1;
	if (keycode == SDLK_UP || keycode == SDLK_w)
		g->game.p.up = 1;
	if (keycode == SDLK_DOWN || keycode == SDLK_s)
		g->game.p.down = 1;
	return (0);
}

int				key_release(int keycode, t_glob *g)
{
	if (keycode == SDLK_LEFT || keycode == SDLK_a)
		g->game.p.left = 0;
	if (keycode == SDLK_RIGHT || keycode == SDLK_d)
		g->game.p.right = 0;
	if (keycode == SDLK_UP || keycode == SDLK_w)
		g->game.p.up = 0;
	if (keycode == SDLK_DOWN || keycode == SDLK_s)
		g->game.p.down = 0;
	return (0);
}