/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initdata.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorimo <jflorimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 15:28:16 by jflorimo          #+#    #+#             */
/*   Updated: 2015/03/02 15:28:16 by jflorimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

t_env		initenv(int choice)
{
	t_env	e;

	e.choice = choice;
	e.mousex = 0;
	e.mousey = 0;
	e.zoom = 1;
	e.rgb.r = 0;
	e.rgb.g = 12;
	e.rgb.b = 6;
	e.mouse_available = 1;
	if (choice == 5)
		e.custom = 1;
	else
		e.custom = 0;
	return (e);
}
