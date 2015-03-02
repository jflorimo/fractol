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

void	display(t_env *e)
{
	drawfractol(e);
	mlx_put_image_to_window(e->mlx, e->win, e->image.image, 0, 0);
}

int		expose_hook(t_env *e)
{
	display(e);
	return (0);
}

void	put_pixel_to_image(t_env *e, int x, int y, t_color color)
{
	char	*pixel;
	int		index;

	index = y * (e->image.size_line) + (x * (e->image.bpp / 8));
	pixel = &(e->image.data[index]);
	pixel[0] = color.b;
	pixel[1] = color.g;
	pixel[2] = color.r;
}

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
