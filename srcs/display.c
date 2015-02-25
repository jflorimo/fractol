#include "fractol.h"
#include "libft.h"
#include <stdio.h>

void	display(t_env *e)
{
	drawFractol(e);
	mlx_put_image_to_window(e->mlx, e->win, e->image.image, 0, 0);
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
		if (keycode == 65362)
			move_down(e);
		if (keycode == 65364)
			move_up(e);
		if (keycode == 65361)
			move_right(e);
		if (keycode == 65363)
			move_left(e);
		if (keycode == 65451) //(zoom+)
			zoom_out(e);
		if (keycode == 65453) // (zoom-)
			zoom_in(e);
		printf("key: %d\n", keycode);
		display(e);
	}
	return (0);
}

void put_pixel_to_image(t_env *e, int x, int y, t_color color)
{
	char	*pixel;
	int 	index;
	// y * largeur + x  *bbp (bpp est en byte et je le converti en octet)
	index = y*(e->image.size_line) + (x * (e->image.bpp/8));

	pixel = &(e->image.data[index]);
	pixel[0] = color.b ;// b
	pixel[1] = color.g;//g
	pixel[2] = color.r;//r
}

void	draw(void)
{
	t_env	e;


	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIN_WIDTH, WIN_HEIGHT, "mandelbrot");
	e.mb = initMandelbrot();

	e.image.image = mlx_new_image(e.mlx, WIN_WIDTH, WIN_HEIGHT);
	e.image.data = mlx_get_data_addr(e.image.image, &(e.image.bpp), 
		&(e.image.size_line), &(e.image.endian));


	mlx_key_hook(e.win, key_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
}