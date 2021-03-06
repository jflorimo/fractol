/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorimo <jflorimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 14:49:32 by jflorimo          #+#    #+#             */
/*   Updated: 2015/03/02 14:49:33 by jflorimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

t_color	init_color(int r, int g, int b)
{
	t_color color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

void	change_color(int keycode, t_env *e)
{
	if (keycode == 113)
		e->rgb.r++;
	if (keycode == 97)
		e->rgb.r--;
	if (keycode == 119)
		e->rgb.g++;
	if (keycode == 115)
		e->rgb.g--;
	if (keycode == 101)
		e->rgb.b++;
	if (keycode == 100)
		e->rgb.b--;
}
