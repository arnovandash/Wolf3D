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

/**
 * @brief This function is called when the user clicks the close button.
 */
int				quitwin(void)
{
	exit(0);
}

/**
 * @brief This function is called when a key is pressed.
 * 
 * @param keycode The keycode of the key that was pressed.
 * @param g The global state object.
 * @return int 0
 */
int				key_press(int keycode, t_glob *g)
{
	if (keycode == SDLK_q || keycode == SDLK_LEFT)
		g->game.p.left = 1;
	if (keycode == SDLK_e || keycode == SDLK_RIGHT)
		g->game.p.right = 1;
	if (keycode == SDLK_w || keycode == SDLK_UP)
		g->game.p.up = 1;
	if (keycode == SDLK_s || keycode == SDLK_DOWN)
		g->game.p.down = 1;
	if (keycode == SDLK_a)
		g->game.p.strafe_left = 1;
	if (keycode == SDLK_d)
		g->game.p.strafe_right = 1;
	return (0);
}

/**
 * @brief This function is called when a key is released.
 * 
 * @param keycode The keycode of the key that was released.
 * @param g The global state object.
 * @return int 0
 */
int				key_release(int keycode, t_glob *g)
{
	if (keycode == SDLK_q || keycode == SDLK_LEFT)
		g->game.p.left = 0;
	if (keycode == SDLK_e || keycode == SDLK_RIGHT)
		g->game.p.right = 0;
	if (keycode == SDLK_w || keycode == SDLK_UP)
		g->game.p.up = 0;
	if (keycode == SDLK_s || keycode == SDLK_DOWN)
		g->game.p.down = 0;
	if (keycode == SDLK_a)
		g->game.p.strafe_left = 0;
	if (keycode == SDLK_d)
		g->game.p.strafe_right = 0;
	return (0);
}
