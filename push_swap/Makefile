NAME = push_swap
SRC = main.c swap.c push.c reverse_rotate.c rotate.c errors.c radix.c utils.c sort.c
FLAGS = -Wall -Wextra -Werror
OBJS = $(SRC:.c=.o)
LIBFT = libft
PRINTF = printf

all: $(NAME)

$(OBJS): %.o: %.c
	@gcc $(FLAGS) -Iinclude -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)/libft.a $(PRINTF)/libftprintf.a
	@ar crs $(NAME).a $(OBJS)
	@gcc $(FLAGS) $(NAME).a $(LIBFT)/libft.a $(PRINTF)/libftprintf.a $(NAME).a -o $(NAME)

$(PRINTF)/libftprintf.a:
	@make -C $(PRINTF) all

$(LIBFT)/libft.a:
	@make -C $(LIBFT) all

clean:
	@rm -f $(OBJS) $(NAME).a
	@make -C $(LIBFT) clean
	@make -C $(PRINTF) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT) fclean
	@make -C $(PRINTF) fclean

re: fclean all

.PHONY: all clean fclean re