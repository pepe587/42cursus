NAME = server
NAME2 = client
FLAGS = -Wall -Wextra -Werror
OBJS = $(NAME).o $(NAME2).o
LIBFT = libft
PRINTF = printf

all: $(NAME) $(NAME2)

$(NAME).o: $(NAME).c
	@gcc $(FLAGS) -Iinclude -c $< -o $@

$(NAME2).o: $(NAME2).c
	@gcc $(FLAGS) -Iinclude -c $< -o $@

$(LIBFT)/libft.a:
	@make -C $(LIBFT) all

$(PRINTF)/libftprintf.a:
	@make -C $(PRINTF) all

$(NAME): $(OBJS) $(LIBFT)/libft.a $(PRINTF)/libftprintf.a
	@gcc $(FLAGS) $(NAME).o $(LIBFT)/libft.a $(PRINTF)/libftprintf.a -o $(NAME)

$(NAME2): $(OBJS) $(LIBFT)/libft.a $(PRINTF)/libftprintf.a
	@gcc $(FLAGS) $(NAME2).o $(LIBFT)/libft.a $(PRINTF)/libftprintf.a -o $(NAME2)

clean:
	@rm -f $(OBJS)
	@make -C $(LIBFT) fclean
	@make -C $(PRINTF) fclean

fclean: clean
	@rm -f $(NAME) $(NAME2)
	@make -C $(LIBFT) fclean
	@make -C $(PRINTF) fclean

re: fclean all

.PHONY: all clean fclean re
