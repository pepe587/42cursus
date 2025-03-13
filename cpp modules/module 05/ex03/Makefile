NAME="Intern"
SRC=Bureaucrat.cpp main.cpp AForm.cpp ShrubberyCreationForm.cpp \
RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp
OBJS=$(SRC:.cpp=.o)
FLAGS=-Wall -Wextra -Werror -std=c++98

all:$(NAME)

$(OBJS):$(SRC)
	@c++ $(FLAGS) $(SRC) -c

$(NAME):$(OBJS)
	@c++ $(FLAGS) $(OBJS) -o $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all