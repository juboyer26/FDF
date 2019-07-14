#ifndef _fdf_h_
#define _fdf_h_

#include <stdio.h>
#include <stdlib.h>

#include "libft/libft.h"
#include "get_next_line/get_next_line.h"
#include <mlx.h>
#include <math.h>

#define KEY_ESC 53
#define KEY_RIGHT 124
#define KEY_LEFT 123
#define KEY_UP 126
#define KEY_DOWN 125


typedef struct  s_env
{
    void	*mlx_ptr;
    void	*win_ptr;
    float	**map;
	int		height;
	int		width;;
}               t_env;

typedef struct  s_pixel
{
    int x;
    int y;
}               t_pixel;

typedef struct  s_coord
{
    float x;
    float y;
    float z;
}               t_coord;

#endif // !_fdf_h_
