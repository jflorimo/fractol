#include "fractol.h"
#include "libft.h"

t_mandelbrot initMandelbrot(void)
{
	t_mandelbrot mandelbrot;

	mandelbrot.minX = -2.0;
	mandelbrot.maxX = 2.0;
	mandelbrot.minY = -1.1;
	mandelbrot.maxY = 1.1;
	return mandelbrot;
}


void drawMandelbrot(t_env *e, int x, int y)
{
	int a = 0;
	float rc;
	float ic;
	float rz;
	float iz;
	float r;
	float i;
	t_color color;
	
	rc = e->mb.minX + (e->mb.maxX - e->mb.minX) / WIN_WIDTH * x;
	ic = e->mb.minY + (e->mb.maxY - e->mb.minY) / WIN_HEIGHT * y;

	rz = 0;
	iz = 0;

	a = 0;
	while (a < MANDELBROT_ITERATION)
	{
		r = rz;

		i = iz;

		rz = r*r - i*i + rc;
		iz = 2 * r*i + ic;

		if ((rz*rz + iz*iz) >= 4)
			break;
		a++;
	}
	color.r = (255*a)/ MANDELBROT_ITERATION;
	color.g = 0;
	color.b = 255;
	put_pixel_to_image(e, x, y, color);	
}
