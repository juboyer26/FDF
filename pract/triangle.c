#include <mlx.h>

# define PIXEL mlx_pixel_put(mlx, win, right, down, 0x0ffffff)
int	main()
{
	void *win;
	void *mlx;

	int right;
	int down;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "test");

	right = 250;
	down = 200;

	while (right > 1)
	{
		PIXEL;
		right --;
		down ++;
	}

	while (right < 498)
	{
		PIXEL;
		right ++;
	}

	while (right >= 250)
	{
		PIXEL;
		down--;
		right --;
	}
	mlx_loop(mlx);
	return(0);
}
