# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juboyer <juboyer@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/23 07:26:13 by juboyer           #+#    #+#              #
#    Updated: 2019/07/27 13:51:31 by juboyer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = src/main.c   \
	  src/read.c    \
	  src/image.c    \
	  src/render.c    \
	  src/util.c	   \
	  src/brens_tools.c \
	  src/cal_functions.c\
	  src/mouse.c         \
	  src/keyboard.c 	   \

OBJ = $(patsubst %.c, %.o, $(SRC))

NAME = fdf

HEADERS = fdf.h

FLAGS = -Wextra -Werror -Wall -I libft -I get_next_line -I .

all: LIBFT get_next_line $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) -o $(NAME) $(OBJ) libft/libft.a get_next_line/get_next_line.o -lmlx -framework OpenGL -framework AppKit
	@echo "Compilation of fdf:	\033[1;32mOK\033[m"

LIBFT:
	git submodule init libft
	git submodule update libft
	make -C libft

get_next_line:
	git submodule init get_next_line
	git submodule update get_next_line
	gcc -c $(FLAGS) get_next_line/get_next_line.c -o get_next_line/get_next_line.o

%.o: %.c $(HEADERS)
	gcc -g -c $(FLAGS) -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f get_next_line/*.o
	make -C libft fclean

re: fclean all

updateSubmodules:
	make fclean
	git submodule foreach git checkout master
	git submodule foreach git pull origin master
	git add .
	git commit -m "submodule update"
	git push

.PHONY: LIBFT re fclean clean get_next_line all updateSubmodules
