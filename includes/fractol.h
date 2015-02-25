/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorimo <jflorimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/22 17:38:11 by jflorimo          #+#    #+#             */
/*   Updated: 2014/04/22 17:38:13 by jflorimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdlib.h>
#include <mlx.h>

typedef	struct		s_mandelbrot
{
	float minX;
	float maxX;
	float minY;
	float maxY;
}					t_mandelbrot;

typedef struct		s_image
{
	void			*image;
	char			*data;

	int				size_line;
	int 			endian;
	int				bpp;

	int				sizeX;
	int				sizeY;

}					t_image;

typedef	struct		s_env
{
	void			*mlx;
	void			*win;
	t_mandelbrot	mb;
	t_image			image;

}					t_env;

/***********************
	Display Functions
************************/

void	draw(void);
int		key_hook(int, t_env *);
int		expose_hook(t_env *);
void	display(t_env *);

/***********************
   Mandelbrot Functions
************************/

t_mandelbrot initMandelbrot( void );
void drawMaldelbrot(t_env *);

#endif
