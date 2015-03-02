/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorimo <jflorimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 14:53:05 by jflorimo          #+#    #+#             */
/*   Updated: 2015/02/25 14:53:06 by jflorimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include <math.h>

void			drawcolor(float a, t_env *e, int x, int y)
{
	t_color		color;

	if (a >= MANDELBROT_ITERATION)
	{
		color.r = 0;
		color.g = 0;
		color.b = 0;
	}
	else
	{
		color.r = sin(a / e->rgb.r) * 255;
		color.g = sin(a / e->rgb.g) * 255;
		color.b = sin(a / e->rgb.b) * 255;
	}
	put_pixel_to_image(e, x, y, color);
}

t_mandelbrot	init_fractol(int choice)
{
	if (choice == 1)
		return (initmandelbrot());
	else if (choice == 2)
		return (initjulia());
	else if (choice == 3)
		return (initburning());
	else if (choice == 4)
		return (initship());
	else if (choice == 8)
		return (initphoenix());
	else if (choice == 9)
		return (initbrainz());
	else
		return (initcustom());
}

void			draw_chosen_fractol(t_env *e, int x, int y)
{
	if (e->choice == 1)
		drawmandelbrot(e, x, y);
	else if (e->choice == 2)
		drawjulia(e, x, y);
	else if (e->choice == 3)
		drawburning(e, x, y);
	else if (e->choice == 4)
		drawship(e, x, y);
	else if (e->choice == 8)
		drawphoenix(e, x, y);
	else if (e->choice == 9)
		drawbrainz(e, x, y);
	else
		drawcustom(e, x, y);
}

void			drawfractol(t_env *e)
{
	int x;
	int y;

	x = 0;
	while (x < WIN_WIDTH)
	{
		y = 0;
		while (y < WIN_HEIGHT)
		{
			draw_chosen_fractol(e, x, y);
			y++;
		}
		x++;
	}
}
