# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avannest <avannest@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/06 06:41:46 by avannest          #+#    #+#              #
#    Updated: 2015/01/15 01:21:12 by avannest         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =				iter
CC =				g++
CFLAGS =			-Wall -Werror -Wextra
SRC =				main.cpp
SRC_PATH =			./
SRC_FILES =			$(addprefix $(SRC_PATH),$(SRC))
OBJ =				$(SRC_FILES:.cpp=.o)
H_PATH =			./

all:				$(NAME)
$(NAME):			$(OBJ)
	$(CC) -o $(NAME) $^ -I $(H_PATH)
%.o:				%.cpp
	$(CC) -c $^ -o $@ $(CFLAGS) -I $(H_PATH) 
clean:
	rm -f $(OBJ)
fclean:				clean
	rm -f $(NAME)
re:					fclean all
