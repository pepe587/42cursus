NAME=philo
SRC= src/main.c src/utils.c src/utils2.c src/utils3.c
OBJS=$(SRC:.c=.o)
FLAGS= -Wall -Werror -Wextra

all: $(NAME)

$(OBJS): %.o : %.c
	@gcc $(FLAGS) -c $< -o $@
$(NAME):$(OBJS)
	@gcc $(FLAGS) $(OBJS) -o $(NAME)

clean:
	@rm -f $(OBJS)

fclean:clean
	@rm -f $(NAME)

re:fclean all

.PHONY: re all clean fclean