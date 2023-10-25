NAME=so_long.a
FILES=map_manage.c handerrors.c character_moves.c collec.c extension.c animations.c steps_animation_1.c steps_animation_2.c enemies.c main.c
OBJECTS=$(FILES:.c=.o)
FLAGS=-Wall -Wextra -Wextra

all:$(NAME)

$(NAME):$(OBJECTS)
	@ar crs $(NAME) $(OBJECTS)
$(OBJECTS):$(FILES)
	@gcc $(FLAGS) -c $(FILES)
clean:
	@rm -f $(OBJECTS)
fclean:
	@rm -f $(NAME) $(OBJECTS)
re: fclean all

.PHONY: all clean fclean re