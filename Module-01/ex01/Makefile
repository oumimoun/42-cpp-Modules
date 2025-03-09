NAME = ZombieHorde
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp\
	Zombie.cpp\
	zombieHorde.cpp\

HEADER = Zombie.hpp

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
