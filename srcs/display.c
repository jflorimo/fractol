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
#include <unistd.h>
#include <sys/time.h>
#include </usr/X11/include/X11/X.h>

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
		// printf("key: %d\n", keycode);
		e->state = 1;
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

static double	get_time(void)
{
	struct timeval		tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec + (double)tv.tv_usec / SECOND);
}

int main_loop(t_env *e)
{
	e->start_frame = get_time();
	if(e->state)
	{
		display(e);
		e->state = 0;
	}	
	e->end_frame = get_time();

	double diff = e->end_frame - e->start_frame;

	usleep((SECOND/30.0) - (diff));

	// printf("tadam %lf\n", 1.0/(get_time() - e->start_frame));
	return (0);
}

void		draw(void)
{
	t_env	e;

	e.mousex = 0;
	e.mousey = 0;
	e.zoom = 1;
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIN_WIDTH, WIN_HEIGHT, "mandelbrot");
	mlx_do_key_autorepeaton(e.mlx);
	e.mb = initmandelbrot();
	e.image.image = mlx_new_image(e.mlx, WIN_WIDTH, WIN_HEIGHT);
	e.image.data = mlx_get_data_addr(e.image.image, &(e.image.bpp),
		&(e.image.size_line), &(e.image.endian));
	mlx_hook(e.win, KeyPress, KeyPressMask, &key_hook, &e);
	mlx_hook(e.win, MotionNotify, PointerMotionMask, &mouse_hook_position, &e);
	mlx_hook(e.win, ButtonPress, ButtonPressMask, &mouse_hook_button, &e);
	// mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);

	mlx_loop_hook( e.mlx, &main_loop, &e);

	mlx_loop(e.mlx);
}





























