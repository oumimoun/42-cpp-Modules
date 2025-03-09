NAME = bureaucrat
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
HEADER = Bureaucrat.hpp\

SRC = main.cpp\
	Bureaucrat.cpp\

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