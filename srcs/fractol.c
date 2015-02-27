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

t_mandelbrot init_fractol(int choice)
{
	if (choice == 1)
		return initmandelbrot();
	if (choice == 2)
		return initjulia();
	else
		return initcustom();
}

void draw_chosen_fractol(t_env *e, int x, int y)
{
	if (e->choice == 1)
		drawmandelbrot(e, x, y);
	if (e->choice == 2)
		drawjulia(e, x, y);
	else
		drawcustom(e, x, y);
}

void drawfractol(t_env *e)
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
