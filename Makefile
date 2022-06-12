NAME = pipex

CFLAGS = -Wall -Wextra -Werror -c -g

RM = rm -f

SRCS = pipex.c tools.c tools2.c find_path.c

OBJS = $(SRCS:.c=.o)

C_OBJS = $(C_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) pipex.h
	cc $(CFLAGS) $(SRCS)
	cc $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all