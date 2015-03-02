/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ship.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorimo <jflorimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 14:49:14 by jflorimo          #+#    #+#             */
/*   Updated: 2015/03/02 14:49:15 by jflorimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include <math.h>

t_mandelbrot		initship(void)
{
	t_mandelbrot	mandelbrot;

	mandelbrot.minx = -MANDELBROT_X;
	mandelbrot.maxx = MANDELBROT_X;
	mandelbrot.miny = -MANDELBROT_Y;
	mandelbrot.maxy = MANDELBROT_Y;
	mandelbrot.rc = 0.6;
	mandelbrot.ic = 0.76;
	mandelbrot.rz = 0;
	mandelbrot.iz = 0;
	return (mandelbrot);
}

void				drawship(t_env *e, int x, int y)
{
	float			a;

	e->mb.rc = e->mb.minx + (e->mb.maxx - e->mb.minx) /
	WIN_WIDTH * (x / e->zoom);
	e->mb.ic = e->mb.miny + (e->mb.maxy - e->mb.miny) /
	WIN_HEIGHT * (y / e->zoom);
	e->mb.rz = 0;
	e->mb.iz = 0;
	a = 0;
	while (a < MANDELBROT_ITERATION)
	{
		e->mb.r = e->mb.rz;
		e->mb.i = e->mb.iz;
		e->mb.rz = e->mb.r * e->mb.r - e->mb.i * e->mb.i + e->mb.rc;
		e->mb.iz = 2 * fabs(e->mb.r * e->mb.i) + e->mb.ic;
		if ((e->mb.rz * e->mb.rz + e->mb.iz * e->mb.iz) >= 4)
			break ;
		a++;
	}
	drawcolor(a, e, x, y);
}
