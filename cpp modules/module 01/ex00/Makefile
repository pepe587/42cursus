NAME=zombie
SRC=Zombie.cpp newZombie.cpp randomChump.cpp main.cpp
OBJ=$(SRC:.cpp=.o)
FLAGS= -Wall -Werror -Wextra -std=c++98

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