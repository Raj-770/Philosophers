NAME	:= philo

# Compiler
CC	:=	gcc
CFLAGS	:=	-Wextra -Wall -Werror
THREADFLAGS := -pthread -fsanitize=thread

# Source
SRCS	:=	src/main.c \
			src/parse_args.c \
			src/utils.c \
			src/init.c \
			src/start.c \
			src/routine.c \
			src/end.c \
			src/philo_actions.c \
			src/time.c \

OBJS	:=	$(SRCS:.c=.o)

all: $(NAME)

%.o: %c
	@$(CC) $(CFLAGS) $(THREADFLAGS) -o $@ -c $<

# Compiling Philosophers
$(NAME): $(OBJS)
	@echo "Compiling Philosophers..."
	@$(CC) $(OBJS) $(THREADFLAGS) -o $(NAME)

clean:
	@echo "Cleaning object files..."
	@rm -rf $(OBJS)

fclean: clean
	@echo "Cleaning Philosophers..."
	@rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
