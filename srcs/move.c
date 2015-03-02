/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorimo <jflorimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 14:42:19 by jflorimo          #+#    #+#             */
/*   Updated: 2015/02/25 14:42:20 by jflorimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

void move_up(t_env *e)
{
	e->mb.maxy += 1 / e->zoom / 25;
	e->mb.miny += 1 / e->zoom / 25;
}

void move_down(t_env *e)
{
	e->mb.maxy -= 1 / e->zoom / 25;
	e->mb.miny -= 1 / e->zoom / 25;
}

void move_left(t_env *e)
{
	e->mb.maxx += 1 / e->zoom / 25;
	e->mb.minx += 1 / e->zoom / 25;
}

void move_right(t_env *e)
{
	e->mb.maxx -= 1 / e->zoom / 25;
	e->mb.minx -= 1 / e->zoom / 25;
}
