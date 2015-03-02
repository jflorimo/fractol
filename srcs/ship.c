#include "fractol.h"
#include "libft.h"
#include <math.h>

t_mandelbrot		initship(void)
{
	t_mandelbrot	mandelbrot;

	mandelbrot.minX = -MANDELBROT_X;
	mandelbrot.maxX = MANDELBROT_X;
	mandelbrot.minY = -MANDELBROT_Y;
	mandelbrot.maxY = MANDELBROT_Y;
	mandelbrot.rc = 0.6;
	mandelbrot.ic = 0.76;
	mandelbrot.rz = 0;
	mandelbrot.iz = 0;
	return (mandelbrot);
}

void				drawship(t_env *e, int x, int y)
{
	float			a;
	t_color			color;
	e->mb.rc = e->mb.minX + (e->mb.maxX - e->mb.minX) / WIN_WIDTH * (x/e->zoom);
	e->mb.ic = e->mb.minY + (e->mb.maxY - e->mb.minY) / WIN_HEIGHT * (y/e->zoom);
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
	if (a >= MANDELBROT_ITERATION)
	{
		color.r = 0;
		color.g = 0;
		color.b = 0;		
	}
	else
	{
		color.r = sin(a/e->rgb.r)*255;
		color.g = sin(a/e->rgb.g)*255;
		color.b = sin(a/e->rgb.b)*255;		
	}
	put_pixel_to_image(e, x, y, color);
}