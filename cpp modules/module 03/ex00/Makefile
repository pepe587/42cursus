NAME=ClapTrap
FLAGS=-std=c++98 -Wall -Wextra -Werror
SRC=ClapTrap.cpp main.cpp
OBJS=$(SRC:.cpp=.o)

all: $(NAME)

$(NAME):$(OBJS)
	@c++ $(FLAGS) $(OBJS) -o $(NAME)

$(OBJS):$(SRC)
	@c++ $(FLAGS) $(SRC) -c

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean re fclean
