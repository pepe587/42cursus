NAME=so_long
FLAGS=-Wall -Wextra -Werror
LIBFT=libft
MLX42=MLX42
PRINTF=printf

all: $(NAME)

$(NAME):
	@make -C src all

$(LIBFT)/libft.a:
	@make -C libft all

$(MLX42)/libmlx42.a:
	@make -C MLX42 all

$(PRINTF)/libftprintf.a:
	@make -C printf all

clean:

	@make -C src clean
	@make -C bonus clean
	@make -C MLX42 clean
	@make -C libft clean
	@make -C printf clean

fclean: $(NAME)

	@rm -f $(NAME)
	@make -C src fclean
	@make -C bonus fclean
	@make -C MLX42 fclean
	@make -C libft fclean
	@make -C printf fclean

re: fclean
	@make -C .

bonus: bonus/$(NAME)

bonus/$(NAME):
	@make -C bonus all

.PHONY: all clean fclean re BONUS

