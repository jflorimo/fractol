#include "fractol.h"
#include "libft.h"

void drawFractol(t_env *e)
{
	int x;
	int y;

	x = 0;
	while (x < WIN_WIDTH)
	{
		y = 0;
		while (y < WIN_HEIGHT)
		{
			drawMandelbrot(e, x, y);
			y++;
		}
		x++;
	}
}
