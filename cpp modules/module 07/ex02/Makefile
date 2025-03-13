NAME=Iter
SRC=main.cpp
OBJS=$(SRC:.cpp=.o)
FLAGS=-Wall -Wextra -Werror -std=c++98 -g

all:$(NAME)

$(OBJS):$(SRC)
	@c++ $(FLAGS) $(SRC) -c

$(NAME):$(OBJS)
	@c++ $(FLAGS) $(OBJS) -o $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all