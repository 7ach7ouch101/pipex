NAME = pipex
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INC = pipex.h
RM = rm -rf

SRCS = pipex.c tools.c tools2.c find_path.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(INC)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all