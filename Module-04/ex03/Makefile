NAME = Recap
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
HEADER = AMateria.hpp\
		Character.hpp\
		Cure.hpp\
		ICharacter.hpp\
		IMateriaSource.hpp\
		Ice.hpp\
		MateriaSource.hpp\

SRC = main.cpp\
		AMateria.cpp\
		Character.cpp\
		Cure.cpp\
		Ice.cpp\
		MateriaSource.cpp\

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
