NAME				:= seralize
SRCS				:= main.cpp Data.cpp

PATH_OBJ			:= obj
PATH_SRC			:= src
PATH_INC			:= inc

CXX					:= g++
CXXFLAGS			:= -Wall -Wextra -Werror
OBJECTS				:= $(patsubst %.cpp, $(PATH_OBJ)/%.o, $(SRCS))

INCLUDES			:= -I./$(PATH_INC)

.PHONY: all

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CXX) -o $@ $(OBJECTS) $(LIBRARY) $(DEBUG) $(CXXFLAGS)

$(PATH_OBJ)/%.o: $(addprefix $(PATH_SRC)/,%.cpp)
	@mkdir -p $(PATH_OBJ)
	$(CXX) -c -o $@ $(CXXFLAGS) $^ $(DEBUG) $(INCLUDES)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)
