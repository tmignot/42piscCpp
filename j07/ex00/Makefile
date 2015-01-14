NAME = iter
LIBNAME =
C = \033[0;36m
CFLAGS = -Wall -Werror -Wextra
SRCPATH = srcs
OBJPATH = obj
INCLUDE = ./

SRCS = \
	   iter.cpp

V = 0
SILENCE_1 :=
SILENCE_0 :=@
SILENCE = $(SILENCE_$(V))
LNAME = $(addprefix lib, $(LIBNAME))
CLNAME = $(addprefix -l, $(LIBNAME))
LIB = $(addprefix -L, $(addsuffix /, $(LNAME))) $(CLNAME)
LINCLUDE =
CC = $(SILENCE)g++
RM = $(SILENCE)rm -rf
MAKE = $(SILENCE)make V=$(V)
INCLUDES = -I $(INCLUDE) $(addprefix -I, $(LINCLUDE))
SRC = $(addprefix $(SRCPATH)/, $(SRCS))
OBJS= $(SRCS:.cpp=.o)
SKIP_1 :=
SKIP_0 := \033[A
SKIP = $(SKIP_$(V))
U = $(C)[$(NAME)]----->\033[0m
OBJDIR = $(addprefix $(OBJPATH)/, $(OBJS))

all: createdir $(LIBNAME) $(NAME)

$(NAME): $(OBJDIR)
	@echo "$(U)$(C)[COMPILE:\033[1;32m DONE$(C)]\033[0m"
	@echo "$(U)$(C)[BUILD]\033[0;32m"
	$(CC) -o $(NAME) $(OBJDIR) $(CFLAGS) $(INCLUDES) $(LIB)
	@echo "$(SKIP)\033[2K"
	@echo "$(SKIP)$(U)$(C)[BUILD  :\033[1;32m DONE$(C)]\033[0m"

$(OBJPATH)/%.o: srcs/%.cpp
	@echo "$(U)$(C)[COMPILE: \033[1;31m$<\033[A\033[0m"
	@echo "\033[0;32m"
	$(CC) -o $@ $(CFLAGS) $(INCLUDES) -c $<
	@echo "\033[1;31m [.working.]"
	@echo "$(SKIP)\033[2K\033[A\033[2K$(SKIP)"

clean:
	@echo "$(U)$(C)[CLEAN]\033[0;32m"
	$(RM) $(OBJPATH)
	@echo "$(SKIP)$(U)$(C)[CLEAN:\033[1;32m   DONE$(C)]\033[0m"

fclean: clean
	@echo "$(U)$(C)[F-CLEAN]\033[0;32m"
	$(RM) $(NAME)
	@echo "$(SKIP)$(U)$(C)[F-CLEAN:\033[1;32m DONE$(C)]\033[0m"

createdir:
	@mkdir -p $(OBJPATH)

re: fclean all
.PHONY: clean fclean createdir all re
