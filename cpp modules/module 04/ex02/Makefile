NAME=Animal
FLAGS=-Wall -Werror -Wextra -std=c++98 -g
SRC=Animal.cpp Dog.cpp Cat.cpp main.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp
OBJ=$(SRC:.cpp=.o)

all: $(NAME)

$(OBJ):$(SRC)
	@c++ $(FLAGS) $(SRC) -c

$(NAME):$(OBJ)
	@c++ $(FLAGS) $(OBJ) -o $(NAME)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all