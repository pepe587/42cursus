NAME=phonebook
FLAGS=-Wall -Werror -Wextra -std=c++98
SRC=main.cpp
OBJS=$(SRC:.cpp=.o)

all:$(NAME)

$(NAME):$(OBJS)
	@c++ $(FLAGS) $(OBJS) -o $(NAME)

$(OBJS):$(SRC)
	@c++ $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean re fclean