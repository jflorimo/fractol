#include "fractol.h"
#include "libft.h"
#include <stdio.h>

void zoom_in(t_env *e)
{
	e->mb.maxX += MOVE_STEP;
	e->mb.minX -= MOVE_STEP;
	e->mb.maxY += MOVE_STEP;
	e->mb.minY -= MOVE_STEP;
}

void zoom_out(t_env *e)
{
	e->mb.maxX -= MOVE_STEP;
	e->mb.minX += MOVE_STEP;
	e->mb.maxY -= MOVE_STEP;
	e->mb.minY += MOVE_STEP;
}