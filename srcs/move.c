#include "fractol.h"
#include "libft.h"
#include <stdio.h>

void move_up(t_env *e)
{
	e->mb.maxY += MOVE_STEP;
	e->mb.minY += MOVE_STEP;
}

void move_down(t_env *e)
{
	e->mb.maxY -= MOVE_STEP;
	e->mb.minY -= MOVE_STEP;
}

void move_left(t_env *e)
{
	e->mb.maxX += MOVE_STEP;
	e->mb.minX += MOVE_STEP;
}

void move_right(t_env *e)
{
	e->mb.maxX -= MOVE_STEP;
	e->mb.minX -= MOVE_STEP;
}
