/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorimo <jflorimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 14:53:18 by jflorimo          #+#    #+#             */
/*   Updated: 2015/02/25 14:53:19 by jflorimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include <stdio.h>

void		display(t_env *e)
{
	drawfractol(e);
	mlx_put_image_to_window(e->mlx, e->win, e->image.image, 0, 0);
}

int			expose_hook(t_env *e)
{
	display(e);
	return (0);
}

int			key_hook(int keycode, t_env *e)
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
		if (keycode == 65451)
			zoom_in(e);
		if (keycode == 65453)
			zoom_out(e);			
		printf("key: %d\n", keycode);
		display(e);
	}
	return (0);
}

void		put_pixel_to_image(t_env *e, int x, int y, t_color color)
{
	char	*pixel;
	int		index;

	index = y * (e->image.size_line) + (x * (e->image.bpp / 8));
	pixel = &(e->image.data[index]);
	pixel[0] = color.b;
	pixel[1] = color.g;
	pixel[2] = color.r;
}

void		draw(void)
{
	t_env	e;

	e.mousex = 0;
	e.mousey = 0;
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIN_WIDTH, WIN_HEIGHT, "mandelbrot");
	e.mb = initmandelbrot();
	e.image.image = mlx_new_image(e.mlx, WIN_WIDTH, WIN_HEIGHT);
	e.image.data = mlx_get_data_addr(e.image.image, &(e.image.bpp),
		&(e.image.size_line), &(e.image.endian));
	mlx_key_hook(e.win, key_hook, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
}
