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
	e->mb.maxX += e->mousex/e->zoom;
	e->mb.minX += e->mousex/e->zoom;

	e->mb.maxY += e->mousey/e->zoom;
	e->mb.minY += e->mousey/e->zoom;
	printf("scalex:%f,scaley:%f\n", e->mousex/e->zoom /10, e->mousey/e->zoom /10);

}

void zoom_in(t_env *e)
{
	// if (e->mousex > 0)
	// {
	// 	}else
	// 	{
	// 		e->mb.maxY -= e->zoom * e->mousey/10;
	// 		e->mb.minY -= e->zoom * e->mousey/10;		
	// 	}
	// }
	// if (e->mousex < 0)
	// {
	// 	e->mb.maxX -= e->zoom * e->mousex/10;
	// 	e->mb.minX -= e->zoom * e->mousex/10;
	// 	if( e->mousey > 0)
	// 	{
	// 		e->mb.maxY += e->zoom * e->mousey/10;
	// 		e->mb.minY += e->zoom * e->mousey/10;
	// 	}else
	// 	{
	// 		e->mb.maxY -= e->zoom * e->mousey/10;
	// 		e->mb.minY -= e->zoom * e->mousey/10;		
	// 	}
	// }
	// rescale(e);

	// e->mb.maxX = e->mb.maxX *0.95;
	// e->mb.minX = e->mb.minX *0.95;
	// e->mb.maxY = e->mb.maxY *0.95;
	// e->mb.minY = e->mb.minY *0.95;
	e->mb.minX += (e->mousex/4/e->zoom); 
	e->mb.maxX += (e->mousex/4/e->zoom); 
	e->mb.minY += (e->mousey/4/e->zoom); 
	e->mb.maxY += (e->mousey/4/e->zoom); 
	e->zoom *= 1.005;
	
	// printf("INmaxX: %f, minX: %f, maxY: %f, minY: %f\n", e->mb.maxX, e->mb.minX, e->mb.maxY, e->mb.minY);
}

void zoom_out(t_env *e)
{
	// rescale(e);

	// e->mb.maxX *= MOVE_STEP;
	// e->mb.minX *= MOVE_STEP;
	// e->mb.maxY *= MOVE_STEP;
	// e->mb.minY *= MOVE_STEP;
	e->zoom *= 0.995;
	// printf("OUTmaxX: %f, minX: %f, maxY: %f, minY: %f\n", e->mb.maxX, e->mb.minX, e->mb.maxY, e->mb.minY);
}
