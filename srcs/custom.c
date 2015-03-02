/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorimo <jflorimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 14:49:47 by jflorimo          #+#    #+#             */
/*   Updated: 2015/03/02 14:49:48 by jflorimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include <math.h>

t_mandelbrot		initcustom(void)
{
	t_mandelbrot	mandelbrot;

	mandelbrot.minx = -MANDELBROT_X;
	mandelbrot.maxx = MANDELBROT_X;
	mandelbrot.miny = -MANDELBROT_Y;
	mandelbrot.maxy = MANDELBROT_Y;
	mandelbrot.rc = 0.6;
	mandelbrot.ic = 0.76;
	return (mandelbrot);
}

void				drawcustom(t_env *e, int x, int y)
{
	float			a;

	e->mb.rz = e->mb.minx + (e->mb.maxx - e->mb.minx) /
	WIN_WIDTH * (x / e->zoom);
	e->mb.iz = e->mb.miny + (e->mb.maxy - e->mb.miny) /
	WIN_HEIGHT * (y / e->zoom);
	if (e->mouse_available)
	{
		e->mb.rc = e->mousex;
		e->mb.ic = e->mousey;
	}
	a = 0;
	while (a < MANDELBROT_ITERATION)
	{
		e->mb.r = e->mb.rz;
		e->mb.i = e->mb.iz;
		e->mb.rz = e->mb.r * e->mb.r - e->mb.i * e->mb.i + e->mb.rc;
		e->mb.iz = 2 * e->mb.r * e->mb.i + e->mb.ic;
		if ((e->mb.rz * e->mb.rz + e->mb.iz * e->mb.iz) >= 4)
			break ;
		a++;
	}
	drawcolor(a, e, x, y);
}
