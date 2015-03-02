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
	ft_putstr("2. julia\n");
	ft_putstr("3. burning\n");
	ft_putstr("4. ship\n");
	ft_putstr("8. phoenix\n");
	ft_putstr("9. brainz\n");
	ft_putstr("5. custom\n");
}

int		main(int ac, char **av)
{
	if (ac > 1)
	{
		if (!ft_strcmp(av[1], "mandelbrot"))
			draw(1);
		if (!ft_strcmp(av[1], "julia"))
			draw(2);
		if (!ft_strcmp(av[1], "burning"))
			draw(3);
		if (!ft_strcmp(av[1], "ship"))
			draw(4);
		if (!ft_strcmp(av[1], "phoenix"))
			draw(8);
		if (!ft_strcmp(av[1], "brainz"))
			draw(9);
		if (!ft_strcmp(av[1], "custom"))
			draw(5);
		else
			choice_message();
	}
	else
		choice_message();
	return (0);
}
