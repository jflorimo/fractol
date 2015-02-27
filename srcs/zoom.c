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

void rescale(t_env *e)
{
	e->mb.maxX += e->mousex/4/e->zoom;
	e->mb.minX += e->mousex/4/e->zoom;
	e->mb.maxY += e->mousey/4/e->zoom;
	e->mb.minY += e->mousey/4/e->zoom;
}

void zoom_in(t_env *e)
{
	rescale(e);
	e->zoom *= 1.005;
}

void zoom_out(t_env *e)
{
	rescale(e);
	e->zoom *= 0.995;
}
