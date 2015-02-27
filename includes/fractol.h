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

#define SECOND 1000000.0
#define MOVE_STEP 1.005

#define MANDELBROT_X 2.4
#define MANDELBROT_Y 1.5
#define MANDELBROT_ITERATION 35

#define WIN_WIDTH 800.0
#define WIN_HEIGHT 800.0
#include <stdlib.h>
#include <mlx.h>

typedef	struct		s_mandelbrot
{
	float minX;
	float maxX;
	float minY;
	float maxY;
	float rc;
	float ic;
	float rz;
	float iz;
	float r;
	float i;
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

typedef struct		s_rgb
{
	int			r;
	int			g;
	int			b;			
}					t_rgb;

typedef	struct		s_env
{
	void			*mlx;
	void			*win;
	t_image			image;
	t_mandelbrot	mb;
	t_rgb			rgb;
	float			mousex;
	float			mousey;
	double			start_frame;
	double			end_frame;
	int				state;
	int 			choice;
	float			zoom;
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

void	draw(int);
int		key_hook(int, t_env *);
int		expose_hook(t_env *);
void	display(t_env *);
void 	put_pixel_to_image(t_env *e, int x, int y, t_color color);
void 	drawfractol(t_env *e);
void change_color(int keycode, t_env *e);
/***********************
   Mandelbrot Functions
************************/

t_mandelbrot initmandelbrot( void );
void drawmandelbrot(t_env *, int x, int y);

/* Move **/
int		key_hook(int keycode, t_env *e);
int mouse_hook_position(int x, int y, t_env *e);
int mouse_hook_button(int button, int x, int y, t_env *e);
void move_up(t_env *e);
void move_down(t_env *e);
void move_left(t_env *e);
void move_right(t_env *e);

void zoom_in(t_env *e);
void zoom_out(t_env *e);

#endif
