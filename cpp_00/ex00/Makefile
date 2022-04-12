CC = clang++
FLAGS = -Wall -Wextra -Werror
NAME = megaphone
SRCS = ./megaphone.cpp
OBJS = $(SRCS:.cpp=.o)

all		: $(NAME)

.cpp.o	:
	@$(CC) $(FLAGS) -c $< -o $(OBJS)

$(NAME)	:	$(OBJS)
	@$(CC) $(FLAGS) $(OBJS) -o $@
	@echo "$(NAME) complete."

clean	:
	@rm $(OBJS)
	@echo "clean $(OBJS)"

fclean	:
	@rm $(OBJS) $(NAME)
	@echo "full clean"

re		: fclean $(NAME)

.PHONY	:	all clean fclean re