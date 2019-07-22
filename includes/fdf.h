#ifndef _fdf_h_
#define _fdf_h_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../libft/libft.h"
#include "../get_next_line/get_next_line.h"
#include <mlx.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


#define W_H 800
#define W_W 1280
#define KEY_ESC 53
#define KEY_RIGHT 124
#define KEY_LEFT 123
#define KEY_UP 126
#define KEY_DOWN 125


# define BLACK 0x000000
# define RED 0xFF0000
# define BLUE 0x0000FF
# define ORANGE 0xFFA500
# define WHITE 0xFFFFFF
# define SILVER 0xC0C0C0
# define GRAY 0x808080
# define MAROON 0x800000
# define YELLOW 0xFFFF00
# define OLIVE 0x808000
# define LIME 0x00FF00
# define GREEN 0x008000
# define AQUA 0x00FFFF
# define TEAL 0x008080
# define NAVY 0x000080
# define FUCHSIA 0xFF00FF
# define PURPLE 0x800080

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

void		ft_render(t_env *mlx);
void		draw_line(t_env *mlx, t_pixel *p1, t_pixel *p2);
t_image		*init_img(t_env *mlx);
t_image		*del_image(t_image *image, t_env *mlx);
void		clear_image(t_env *mlx);
void		set_pixel(t_image *image, int x, int y, int color);	

int			create_x(t_env *win, int x);
int			create_y(t_env *win, int y);
t_bres		*bres_const(t_pixel *p1, t_pixel *p2);	
int			cnv_dbl_int(double num);
int			choose_color(int p1);
int			get_highest(t_pixel *p1, t_pixel *p2, t_env *mlx);
int			ft_abs(int num);
int			expose_hook(t_env *mlx);

void		calcule_coord(t_env *mlx);
void		rotate(t_env *mlx, t_rot_point *rp);
void		ft_calculate(t_env *mlx, t_pixel *pt);
#endif // !_fdf_h_
