#include "fractol.h"
#include "libft.h"
#include <stdio.h>

void	display(t_env *e)
{
	drawMaldelbrot(e);
}

int		expose_hook(t_env *e)
{
	display(e);
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	if (e)
	{
		if (keycode == 65307)
			exit(0);
		if (keycode == 113)
			e->mb.maxX += 0.1;
		if (keycode == 97)
			e->mb.maxX -= 0.1;
		if (keycode == 119)
			e->mb.minX += 0.1;
		if (keycode == 115)
			e->mb.minX -= 0.1;
		if (keycode == 101)
			e->mb.maxY += 0.1;
		if (keycode == 100)
			e->mb.maxY -= 0.1;
		if (keycode == 114)
			e->mb.minY += 0.1;
		if (keycode == 102)
			e->mb.minY -= 0.1;

		//UP 65464
		//DOWN 65458
		//LEFT 65460
		//RIGHT 65462
		printf("#######\nmaxX: %f, minX: %f\nmaxY: %f, minY: %f\n", 
			e->mb.maxX, e->mb.minX, e->mb.maxY, e->mb.minY);
		display(e);
	}
	return (0);
}

void put_pixel_to_image(t_env *e, int x, int y, int color)
{
	char	*pixel;
	int 	index;

	index = x*(e-)

	e.image.data
}

void	draw(void)
{
	t_env	e;


	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 800, 600, "mandelbrot");
	e.mb = initMandelbrot();

	e.image.image = mlx_new_image(e.mlx, 800, 600);
	e.image.data = mlx_get_data_addr(e.image.image, &(e.image.bpp), 
		&(e.image.size_line), &(e.image.endian));


	mlx_key_hook(e.win, key_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
}