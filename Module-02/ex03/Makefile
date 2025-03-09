NAME = bsp
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
HEADER = Fixed.hpp\
		Point.hpp\

SRC = main.cpp\
	Fixed.cpp\
	bsp.cppFixed.cpp\
	Point.cpp\

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean 
	rm -f $(NAME)

re: fclean all
