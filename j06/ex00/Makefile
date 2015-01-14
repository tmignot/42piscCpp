CC = g++
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = src
NAME = convert

SRC = $(SRC_DIR)/Convert.cpp

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(NAME)

fclean: clean

re: clean all
