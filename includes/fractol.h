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

#define MOVE_STEP 0.1
#define MANDELBROT_ITERATION 35
#define WIN_WIDTH 800
#define WIN_HEIGHT 800
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

typedef struct		s_color
{
	char			r;
	char			g;
	char			b;			
}					t_color;

/***********************
	Display Functions
************************/

void	draw(void);
int		key_hook(int, t_env *);
int		expose_hook(t_env *);
void	display(t_env *);
void 	put_pixel_to_image(t_env *e, int x, int y, t_color color);
void 	drawFractol(t_env *e);
/***********************
   Mandelbrot Functions
************************/

t_mandelbrot initMandelbrot( void );
void drawMandelbrot(t_env *, int x, int y);

/* Move **/
void move_up(t_env *e);
void move_down(t_env *e);
void move_left(t_env *e);
void move_right(t_env *e);

void zoom_in(t_env *e);
void zoom_out(t_env *e);

#endif
