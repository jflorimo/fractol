#include "fractol.h"
#include "libft.h"
#include <stdio.h>

void change_color(int keycode, t_env *e)
{
// Q: 113 maxX++
// A: 97 maxX--

// W: 119 minX ++
// S: 115 minX--

// E: 101 maxY++
// D: 100 maxY --

// R: 114 minY ++
// F: 102 minY--
	if (keycode == 113)
		e->rgb.r++;
	if(keycode == 97)
		e->rgb.r--;
	if (keycode == 119)
		e->rgb.g++;
	if(keycode == 115)
		e->rgb.g--;
	if (keycode == 101)
		e->rgb.b++;
	if(keycode == 100)
		e->rgb.b--;
	printf("r:%d, g:%d, b:%d\n", e->rgb.r,e->rgb.g,e->rgb.b);
}