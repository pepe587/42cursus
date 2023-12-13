#variables

NAME=libftprintf.a
FLAGS= -Wall -Wextra -Werror
FILES=ft_printf.c ft_format.c ft_format2.c ft_dectohex.c ft_format3.c ft_putunbr_fd.c ft_printhex.c
OBJECTS=$(FILES:.c=.o)
LIBFT=libft2

#Scripts

all: $(NAME)

$(NAME):$(OBJECTS)
	@make -C $(LIBFT)
	@cp libft2/libft.a .
	@mv libft.a $(NAME)
	@ar crs $(NAME) $(OBJECTS)

%.o: %.c
	@gcc $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJECTS)
	@make -C libft2 clean

fclean:
	@rm -f $(NAME) $(OBJECTS)
	@make -C libft2 fclean

re: fclean all

.PHONY: all re clean fclean