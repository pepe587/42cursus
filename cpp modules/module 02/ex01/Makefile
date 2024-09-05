NAME=fixed
SRC=main.cpp Fixed.cpp
OBJ=$(SRC:.cpp=.o)
FLAGS=-Wall -Wextra -Werror -std=c++98

all:$(NAME)

$(OBJ):$(SRC)
	@c++ $(FLAGS) $(SRC) -c

$(NAME):$(OBJ)
	@c++ $(FLAGS) $(OBJ) -o $(NAME)

clean:
	@rm -fr $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all