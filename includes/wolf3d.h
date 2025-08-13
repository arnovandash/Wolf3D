/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 13:05:25 by arnovan-          #+#    #+#             */
/*   Updated: 2016/06/26 14:35:54 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <SDL2/SDL.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <math.h>

# define WIN_W 1920
# define WIN_H 1080

# define COLOR_FLOOR 0x8B4513
# define COLOR_CEILING 0x87CEEB

/**
 * @brief This struct holds all the variables related to the raycasting engine.
 */
typedef struct	s_raycaster
{
	double		plane_x;
	double		plane_y;
	double		camera_x;
	double		ray_pos_x;
	double		ray_pos_y;
	double		ray_dir_x;
	double		ray_dir_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			draw_start;
	int			draw_end;
	int			detect_wall;
	int			side;
	int			line_height;
}				t_raycaster;

/**
 * @brief This struct holds all the variables related to the player.
 */
typedef struct	s_player
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	int			step_x;
	int			step_y;
	double		r_speed;
	double		m_speed;
	int			map_x;
	int			map_y;
	double		h_camera;
	int			wall_side;
	int			left;
	int			right;
	int			up;
	int			down;
}				t_player;

/**
 * @brief This struct holds all the variables related to the map.
 */
typedef struct	s_map
{
	int		x;
	int		y;
	int		i;
	char	*buf;
	int		j;
}				t_map;

/**
 * @brief This struct holds all the variables related to the environment.
 */
typedef struct	s_env
{
	SDL_Window	*win;
	SDL_Renderer *ren;
	SDL_Texture *tex;
	uint32_t	*pixels;
	int		win_w;
	int		win_h;
	int		vsync;
	int		**map;
	int		fd;
	int		bpp;
	int		size_line;
	int		endian;
}				t_env;

/**
 * @brief This struct holds all the variables related to the game state.
 */
typedef struct s_game
{
	t_player	p;
	t_map		map;
	t_raycaster	ray;
}				t_game;

/**
 * @brief This struct holds all the global variables.
 */
typedef struct	s_glob
{
	t_env		env;
	t_game		game;
}				t_glob;

void			error(int err);
void			loop_calc_3(t_glob *g);
void			loop_calc_2(t_glob *g);
void			loop_calc_1(t_glob *g, float *x);
int				quitwin();
int				key_press(int keycode, t_glob *g);
int				key_release(int keycode, t_glob *g);
void			get_map(t_glob *g, char *file);
void			render(t_glob *g);
void			move(t_glob *g);
#endif
