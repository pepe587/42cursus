NAME=Bank
FLAGS=-Wall -Werror -Wextra -std=c++98
SRC=tests.cpp Account.cpp
OBJS=$(SRC:.cpp=.o)

all:$(NAME)

$(NAME):$(OBJS)
	@c++ $(FLAGS) $(OBJS) -o $(NAME)

$(OBJS): %.o : %.cpp
	@c++ $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re