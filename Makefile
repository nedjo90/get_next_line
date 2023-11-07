SRCS=get_next_line.c \
get_next_line_utils.c \

CC=gcc
CFLAGS=-Wall -Wextra -Werror
OBJ=$(SRCS:.c=.o)
AR=ar rcs
RM=rm -rf
NAME=get_next_line.a

run: re
	$(CC) $(CFLAGS) test_get.c $(NAME)
	./a.out
	

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $@ $^

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME) a.out

re: fclean all
	
