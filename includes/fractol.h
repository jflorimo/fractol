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

# define SECOND 1000000.0
# define MOVE_STEP 1.005

# define MANDELBROT_X 2.4
# define MANDELBROT_Y 1.5
# define MANDELBROT_ITERATION 35

# define WIN_WIDTH 800.0
# define WIN_HEIGHT 800.0
# include <stdlib.h>
# include <mlx.h>

typedef	struct		s_mandelbrot
{
	float			minx;
	float			maxx;
	float			miny;
	float			maxy;
	float			rc;
	float			ic;
	float			rz;
	float			iz;
	float			r;
	float			i;
}					t_mandelbrot;

typedef struct		s_image
{
	void			*image;
	char			*data;

	int				size_line;
	int				endian;
	int				bpp;

	int				sizex;
	int				sizey;

}					t_image;

typedef struct		s_rgb
{
	int				r;
	int				g;
	int				b;
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
	int				choice;
	float			zoom;
	int				mouse_available;
	int				custom;
}					t_env;

typedef struct		s_color
{
	char			r;
	char			g;
	char			b;
}					t_color;

void				draw(int a);
int					key_hook(int a, t_env *e);
int					expose_hook(t_env *e);
void				display(t_env *e);
void				put_pixel_to_image(t_env *e, int x, int y, t_color color);
void				drawfractol(t_env *e);

t_color				init_color(int r, int g, int b);
void				change_color(int keycode, t_env *e);
void				drawcolor(float a, t_env *e, int x, int y);

t_mandelbrot		init_fractol(int choice);
void				drawjulia(t_env *e, int x, int y);
t_mandelbrot		initjulia(void);
void				drawmandelbrot(t_env *e, int x, int y);
t_mandelbrot		initmandelbrot(void);
void				drawcustom(t_env *e, int x, int y);
t_mandelbrot		initcustom(void);
void				drawburning(t_env *e, int x, int y);
t_mandelbrot		initburning(void);
void				drawship(t_env *e, int x, int y);
t_mandelbrot		initship(void);
void				drawphoenix(t_env *e, int x, int y);
t_mandelbrot		initphoenix(void);
void				drawbrainz(t_env *e, int x, int y);
t_mandelbrot		initbrainz(void);

int					key_hook(int keycode, t_env *e);
int					mouse_hook_position(int x, int y, t_env *e);
int					mouse_hook_button(int button, int x, int y, t_env *e);
void				move_up(t_env *e);
void				move_down(t_env *e);
void				move_left(t_env *e);
void				move_right(t_env *e);

void				zoom_in(t_env *e);
void				zoom_out(t_env *e);
t_env				initenv(int choice);

#endif
