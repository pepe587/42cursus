NAME=WW3
SRC=main.cpp HumanA.cpp HumanB.cpp Weapon.cpp
OBJ=$(SRC:.cpp=.o)
FLAGS=-Wall -Werror -Wextra -std=c++98

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