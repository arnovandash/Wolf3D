/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 06:35:30 by arnovan-          #+#    #+#             */
/*   Updated: 2016/06/25 10:26:18 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "mlx.h"
# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

# include <math.h>

# define WIN_W 1280
# define WIN_H 720

# define KB_ESC 53
# define KB_UP 126
# define KB_DOWN 125
# define KB_LEFT 123
# define KB_RIGHT 124

//# define RED	0xFF0000
//# define GREEN	0x00FF00
//# define BLUE	0x0000FF

typedef struct	s_raycaster
{
	double		planeX;
	double		planeY;
	double		cameraX;
	double		rayPosX;
	double		rayPosY;
	double		rayDirX;
	double		sideDistX;
	double		deltaDistX;
	double		deltaDistY;
	double		perpWallDist;
	double		sideDistY;
	int			drawStart;
	int			drawEnd;
	double		rayDirY;
	int			detect_wall;
	int			side;
	int			lineHeight;
}				t_raycaster;

typedef struct	s_player
{
	double		posX;
	double		posY;
	double		dirX;
	double		dirY;
	int			stepX;
	int			stepY;
	double		rspeed;
	double		mspeed;
	int			mapX;
	int			mapY;
	double		hcamera;
	int			wallside;
	int			left;
	int			right;
	int			up;
	int			down;
}				t_player;

typedef struct	s_map
{
	int		x;
	int		y;
	int		i;
	char	*buf;
	int		j;
}				t_map;

typedef struct s_env
{
	void	*mlx;
	void	*win;
	int		ex;
	int		ey;
	void	*img;
	int		**map;
	int		fd;
}				t_env;

typedef struct s_glob
{
	t_env		env;
	t_map		map;
	t_player	p;
	t_raycaster ray;
}				t_glob;

void	ft_error(int err);

int		ft_esc(int keycode);
int		quitwin();
int		key_press(int keycode, t_glob *g);
int		key_release(int keycode, t_glob *g);
void	get_map(t_glob *g, char *file);
int		loops_hook(t_glob *g);
void	move(t_glob *g);
#endif
