/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorimo <jflorimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 15:11:07 by jflorimo          #+#    #+#             */
/*   Updated: 2015/02/25 15:11:07 by jflorimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include <stdio.h>

int			key_hook(int keycode, t_env *e)
{
	if (e)
	{
		if (keycode == 65307)
			exit(0);
		if (keycode == 65362)
			move_down(e);
		if (keycode == 65364)
			move_up(e);
		if (keycode == 65361)
			move_right(e);
		if (keycode == 65363)
			move_left(e);
		if (keycode == 65451)
			zoom_in(e);
		if (keycode == 65453)
			zoom_out(e);
		change_color(keycode, e);
		e->state = 1;
	}
	return (0);
}

int mouse_hook_position(int x, int y, t_env *e)
{
	if(e)
	{
		e->mousex = ((float)x - (WIN_WIDTH / 2)) / (WIN_WIDTH / 2);
		e->mousey = ((float)y - (WIN_HEIGHT / 2)) / (WIN_HEIGHT / 2);
		e->state = 1;

		float minX = e->mb.minX;
		float maxX = e->mb.maxX;
		float minY = e->mb.minY;
		float maxY = e->mb.maxY;
		printf("maxX:%f,minX:%f,maxY:%f,minY:%f,x:%f,y:%f,zoom:%f\n",
			maxX ,minX, maxY, minY,e->mousex,e->mousey,e->zoom);
	}
	return (0);
}

int mouse_hook_button(int button, int x, int y, t_env *e)
{
	if(e)
	{
		e->mousex = (x - (WIN_WIDTH / 2)) / (WIN_WIDTH / 2);
		e->mousey = (y - (WIN_HEIGHT / 2)) / (WIN_HEIGHT / 2);
		if(button == 5)
			zoom_in(e);
		if(button == 4)
			zoom_out(e);
		e->state = 1;
	}
	return (0);
}