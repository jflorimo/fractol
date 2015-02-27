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
	if(e->choice == 1)
		drawfractol(e);
	mlx_put_image_to_window(e->mlx, e->win, e->image.image, 0, 0);
}

int			expose_hook(t_env *e)
{
	display(e);
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
	double diff;

	e->start_frame = get_time();
	if(e->state)
	{
		display(e);
		e->state = 0;
	}	
	e->end_frame = get_time();
	diff = e->end_frame - e->start_frame;
	usleep((SECOND/30.0) - (diff));
	return (0);
}

void		draw(int choice)
{
	t_env	e;

	e.choice = choice;
	e.mousex = 0;
	e.mousey = 0;
	e.zoom = 1;
	e.rgb.r = 0;
	e.rgb.g = 12;
	e.rgb.b = 6;
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
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop_hook( e.mlx, &main_loop, &e);
	mlx_loop(e.mlx);
}





























