#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jflorimo <jflorimo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/04/22 18:17:27 by jflorimo          #+#    #+#              #
#    Updated: 2014/04/22 18:17:27 by jflorimo         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =	fractol

SRCDIR = srcs/

CFILES =	main.c display.c mandelbrot.c move.c zoom.c fractol.c controls.c\
			color.c julia.c custom.c\

MLX = -L/usr/X11/lib -lmlx -lXext -lX11

SRC = $(addprefix $(SRCDIR), $(CFILES))

GCC = gcc -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

HDDIR = includes/

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@$(GCC) -o $(NAME) $(OBJ) libft/libft.a $(MLX)
	@echo "\033[33m"compilation of $(NAME) : "\033[32m"Success"\033[0m"

%.o: %.c
	@echo -n .
	@$(GCC) -c -o $@ $^  -I $(HDDIR)

clean:
	@make -C libft/ clean
	@rm -f $(OBJ)

fclean: clean
	@make -C libft/ fclean
	@rm -rf $(NAME)
	@echo "\033[31m"$(NAME) : deleted"\033[0m"

re: fclean all

.PHONY: clean fclean re