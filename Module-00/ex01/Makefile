NAME = PhoneBook
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
HEADER = PhoneBook.hpp Contact.hpp

SRC = PhoneBook.cpp\
	Contact.cpp\
	main.cpp\


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
