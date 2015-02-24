#include "fractol.h"
#include "libft.h"

t_mandelbrot initMandelbrot( void )
{
	t_mandelbrot mandelbrot;

	mandelbrot.minX = -2.0;
	mandelbrot.maxX = 2.0;

	mandelbrot.minY = -1.1;
	mandelbrot.maxY = 1.1;

	return mandelbrot;
}

void drawMaldelbrot(t_env *e)
{
	int x = 0;
	int y = 0;
	int a = 0;
	float rc;
	float ic;
	float rz;
	float iz;
	float r;
	float i;
	
	while (x < 800)
	{
		y = 0;
		while (y < 600)
		{
			rc = e->mb.minX + (e->mb.maxX - e->mb.minX) / 800 * x;
			ic = e->mb.minY + (e->mb.maxY - e->mb.minY) / 600 * y;

			rz = 0;
			iz = 0;

			a = 0;
			while (a < 15)
			{
				r = rz;

				i = iz;

				rz = r*r - i*i + rc;
				iz = 2 * r*i + ic;

				if ((rz*rz + iz*iz) >= 4)
					break;
				a++;
			}
			mlx_pixel_put(e->mlx, e->win, x, y, (255*a)/15);

			y++;
		}
		x++;
	}
}