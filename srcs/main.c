/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorimo <jflorimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/22 16:41:36 by jflorimo          #+#    #+#             */
/*   Updated: 2014/04/22 16:41:37 by jflorimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

void	choice_message(void)
{
	ft_putstr("you can choose between:\n");
	ft_putstr("1. mandelbrot\n");
}

int		main()//int ac, char **av)
{
	draw(1);
	// if (ac > 1)
	// {
	// 	if (!ft_strcmp(av[1], "mandelbrot"))
	// 		draw();
	// 	else
	// 		choice_message();
	// }
	// else
	// 	choice_message();
	return (0);
}
