/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorimo <jflorimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 14:52:40 by jflorimo          #+#    #+#             */
/*   Updated: 2015/02/25 14:52:42 by jflorimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

t_mandelbrot		initmandelbrot(void)
{
	t_mandelbrot	mandelbrot;

	mandelbrot.minX = -2.0;
	mandelbrot.maxX = 2.0;
	mandelbrot.minY = -1.1;
	mandelbrot.maxY = 1.1;
	return (mandelbrot);
}

void				drawmandelbrot(t_env *e, int x, int y)
{
	int				a;
	t_color			color;

	e->mb.rc = e->mb.minX + (e->mb.maxX - e->mb.minX) / WIN_WIDTH * x;
	e->mb.ic = e->mb.minY + (e->mb.maxY - e->mb.minY) / WIN_HEIGHT * y;
	e->mb.rz = 0;
	e->mb.iz = 0;
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
	color.r = (255 * a) / MANDELBROT_ITERATION;
	color.g = 0;
	color.b = 255;
	put_pixel_to_image(e, x, y, color);
}
