CC = g++
CFLAGS = -Wall -Wextra -Werror
NAME = convert

SRC = Convert.cpp

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	clear
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(NAME)

re: clean all
