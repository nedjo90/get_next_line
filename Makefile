SRCS=get_next_line.c \
get_next_line_utils.c

CC=gcc
CFLAGS =-Wall -Wextra -Werror 
OBJ=$(SRCS:.c=.o)
AR=ar rcs
RM=rm -rf
NAME=get_next_line.a

all: fclean $(NAME)

$(NAME): $(OBJ)
	$(AR) $@ $^
	$(CC) $(CFLAGS) main.c $(NAME)
	@echo "\n"
	@echo "\n"
	./a.out multiple-line
	@echo "\n"
	@echo "\n"
	./a.out test_empty 
	@echo "\n"
	@echo "\n"
	./a.out 41_no_nl
	@echo "\n"
	@echo "\n"
	./a.out 41_with_nl
	## @echo "\n"
	## @echo "\n"
	## ./a.out big_line_with_nl

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re ./a.out main.c
