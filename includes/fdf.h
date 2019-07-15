#ifndef _fdf_h_
#define _fdf_h_

#include <stdio.h>
#include <stdlib.h>

#include "libft/libft.h"
#include "get_next_line/get_next_line.h"
#include <mlx.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define KEY_ESC 53
#define KEY_RIGHT 124
#define KEY_LEFT 123
#define KEY_UP 126
#define KEY_DOWN 125


typedef struct  s_env
{
    void	    *mlx_ptr;
    void	    *win_ptr;
    char	    **map;
	int		    height;
	int		    width;
    t_pixel     *pixels;
    t_coord     *coord;

}               t_env;

typedef struct  s_pixel
{
    int         x;
    int         y;
    int         color;
}               t_pixel;

typedef struct  s_coord
{
    float       x;
    float       y;
    float       z;
}               t_coord;

#endif // !_fdf_h_
