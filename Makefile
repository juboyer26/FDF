# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juboyer <juboyer@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/09 12:59:05 by juboyer           #+#    #+#              #
#    Updated: 2019/07/09 16:29:05 by juboyer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c

OBJ = $(patsubst %.c, %.o, $(SRC))

NAME = fdf

FLAGS = -Wextra -Werror -Wall -I libft -I get_next_line -I  .

all: LIBFT get_next_line $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) -o $(NAME) $(OBJ) libft/libft.a get_next_line/get_next_line.o -lmlx -framework OpenGL -framework AppKit
	@echo "Compilation of fdf:	\033[1;32mOK\033[m"
	@rm -f $(OBJ)

LIBFT:
	git submodule init libft
	git submodule update libft
	make -C libft

get_next_line:
	git submodule init get_next_line
	git submodule update get_next_line
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
