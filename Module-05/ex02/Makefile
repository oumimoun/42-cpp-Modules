NAME = bureaucrat
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
HEADER = Bureaucrat.hpp\
		AForm.hpp\
		PresidentialPardonForm.hpp\
		RobotomyRequestForm.hpp\
		ShrubberyCreationForm.hpp\

SRC = main.cpp\
	Bureaucrat.cpp\
	AForm.cpp\
	PresidentialPardonForm.cpp\
	RobotomyRequestForm.cpp\
	ShrubberyCreationForm.cpp\

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
	rm -rf garden_shrubbery
	rm -rf home_shrubbery

re: fclean all
