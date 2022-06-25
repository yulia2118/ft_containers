# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdarrin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/13 16:28:39 by fdarrin           #+#    #+#              #
#    Updated: 2021/06/13 16:28:42 by fdarrin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = containers

CC = clang++

FLAGS = -Wall -Wextra -Werror -std=c++98

HEADER = vector.hpp map.hpp stack.hpp vector_iterator.hpp map_iterator.hpp utils.hpp

SRC = main.cpp

OBJ = $(SRC:.cpp=.o)

%.o: %.cpp $(HEADER)
		$(CC) -c $(FLAGS) $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(OBJ) -o $(NAME)

clean:
		rm -rf $(OBJ)

fclean:
		rm -rf $(OBJ) $(NAME)

re:		fclean all

.PHONY: clean fclean all re
