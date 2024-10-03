NAME=so_long
FILES=map_manage.c handerrors.c character_moves.c collec.c extension.c animations.c my_split.c main.c
OBJECTS=$(FILES:.c=.o)
FLAGS=-Wall -Wextra -Werror
LIBFT=../libft
MLX42=../MLX42
PRINTF=../printf

all: $(NAME)

$(OBJECTS): %.o: %.c
	@gcc $(FLAGS) -Iinclude -c $< -o $@

$(NAME): $(OBJECTS) $(LIBFT)/libft.a $(MLX42)/libmlx42.a $(PRINTF)/libftprintf.a
	@ar crs $(NAME).a $(OBJECTS)
	@gcc $(FLAGS) $(OBJECTS) $(LIBFT)/libft.a $(PRINTF)/libftprintf.a $(MLX42)/libmlx42.a $(NAME).a -ldl -lglfw -I include -lglfw  -pthread -lm -o $(NAME)
	@mv $(NAME) ../

$(LIBFT)/libft.a:
	@make -C ../libft all

$(MLX42)/libmlx42.a:
	@make -C ../MLX42 all

$(PRINTF)/libftprintf.a:
	@make -C ../printf all

clean:
	@rm -f $(OBJECTS) $(NAME).a

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re