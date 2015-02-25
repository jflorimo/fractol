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

int mouse_hook(int button, int x, int y, t_env *e)
{
	if(e)
	{
		e->mousex = x - (WIN_WIDTH / 2);
		e->mousey = y - (WIN_HEIGHT / 2);
		printf("x:%d, y:%d, button:%d\n",e->mousex , e->mousey, button);
		if(button == 5)
			zoom_in(e);
		display(e);
	}
	return (0);
}