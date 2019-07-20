#ifndef _fdf_h_
#define _fdf_h_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "libft/libft.h"
#include "get_next_line/get_next_line.h"
#include <mlx.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


#define W_H 500
#define W_W 500
#define KEY_ESC 53
#define KEY_RIGHT 124
#define KEY_LEFT 123
#define KEY_UP 126
#define KEY_DOWN 125

typedef struct	s_image
{
	void		*image;
	char		*ptr;
	int			bpp;
	int			sizel;
	int			endian;
}				t_image;

typedef struct	s_bres
{
	int			err;
	int			dx;
	int			dy;
	int			sx;
	int			sy;
}				t_bres;

typedef struct	s_render
{
	int			rows;
	int			check;
	int			cols;
	t_bres		*bres;
}				t_render;

typedef struct	s_rot_point
{
	double		act_px;
	double		act_py;
	double		act_pz;
	double		px;
	double		py;
	double		pz;
}				t_rot_point;

typedef struct	s_pixel
{
	int			x;
	int			y;
	int			z;
	int			d2x;
	int			d2y;
	int			color;
}				t_pixel;

typedef struct	s_mouse
{
	int			lastx;
	int			lasty;
	int			x;
	int			y;
	int			button1;
}				t_mouse;

typedef struct	s_env
{
	int			fd;
	char		*name;
	void		*mlx_ptr;
	void		*win_ptr;
	t_pixel	    **map;
	t_image		*image;
	t_render	info;
	t_mouse		mouse;
	int			depth_max;
	int			depth_min;
	int			scale;
	double		depth;
	double		anglex;
	double		angley;
	int			move_lr;
	int			move_ud;
}				t_env;


int			read_map(t_env *mlx);
int			malloc_rows_cols(t_env *mlx);
int			ft_col_row(t_env *mlx, char *line);

#endif // !_fdf_h_
