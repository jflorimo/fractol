/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorimo <jflorimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 14:42:02 by jflorimo          #+#    #+#             */
/*   Updated: 2015/02/25 14:42:04 by jflorimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include <stdio.h>

void zoom_in(t_env *e)
{
	e->mb.maxX /= MOVE_STEP;
	e->mb.minX /= MOVE_STEP;
	e->mb.maxY /= MOVE_STEP;
	e->mb.minY /= MOVE_STEP;
	printf("INmaxX: %f, minX: %f, maxY: %f, minY: %f\n", e->mb.maxX, e->mb.minX, e->mb.maxY, e->mb.minY);
}

void zoom_out(t_env *e)
{
	e->mb.maxX *= MOVE_STEP;
	e->mb.minX *= MOVE_STEP;
	e->mb.maxY *= MOVE_STEP;
	e->mb.minY *= MOVE_STEP;
	printf("OUTmaxX: %f, minX: %f, maxY: %f, minY: %f\n", e->mb.maxX, e->mb.minX, e->mb.maxY, e->mb.minY);
}
