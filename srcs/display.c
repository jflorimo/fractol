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
#include <unistd.h>
#include <sys/time.h>
#include </usr/X11/include/X11/X.h>

static double		get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec + (double)tv.tv_usec / SECOND);
}

int					main_loop(t_env *e)
{
	double			diff;

	e->start_frame = get_time();
	if (e->state)
	{
		display(e);
		e->state = 0;
	}
	e->end_frame = get_time();
	diff = e->end_frame - e->start_frame;
	usleep((SECOND / 30.0) - (diff));
	return (0);
}

void				draw(int choice)
{
	t_env			e;

	e = initenv(choice);
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIN_WIDTH, WIN_HEIGHT, "mandelbrot");
	mlx_do_key_autorepeaton(e.mlx);
	e.mb = init_fractol(choice);
	e.image.image = mlx_new_image(e.mlx, WIN_WIDTH, WIN_HEIGHT);
	e.image.data = mlx_get_data_addr(e.image.image, &(e.image.bpp),
		&(e.image.size_line), &(e.image.endian));
	mlx_hook(e.win, KeyPress, KeyPressMask, &key_hook, &e);
	mlx_hook(e.win, MotionNotify, PointerMotionMask, &mouse_hook_position, &e);
	mlx_hook(e.win, ButtonPress, ButtonPressMask, &mouse_hook_button, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop_hook(e.mlx, &main_loop, &e);
	mlx_loop(e.mlx);
}
