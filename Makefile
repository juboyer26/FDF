# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juboyer <juboyer@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/09 12:59:05 by juboyer           #+#    #+#              #
#    Updated: 2019/07/21 14:20:27 by juboyer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = src/main.c\
	  src/read.c \
	  src/image.c \
	  src/render.c \
	  src/util.c	\
	  src/brens_tools.c\
	  src/cal_functions.c \
	  

OBJ = $(patsubst %.c, %.o, $(SRC))

NAME = fdf

FLAGS = -Wextra -Werror -Wall -I libft -I get_next_line -I  .

all: LIBFT get_next_line $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) -o $(NAME) $(OBJ) libft/libft.a get_next_line/get_next_line.o -lmlx -framework OpenGL -framework AppKit
	@echo "Compilation of fdf:	\033[1;32mOK\033[m"
	@rm -f $(OBJ)

LIBFT:
	make -C libft

get_next_line:
	gcc -c $(FLAGS) get_next_line/get_next_line.c -o get_next_line/get_next_line.o

%.o: %.c
	gcc -c $(FLAGS) -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: LIBFT re fclean clean get_next_line all
