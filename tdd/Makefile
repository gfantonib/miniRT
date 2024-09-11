CC = cc
CFLAGS = -Wall -Wextra -Werror
MATHFLAG = -lm
SRCPATH = ../source
INCPATH = ../include
HEADER = -I $(INCPATH) -I $(LIBMLX)/include
OBJPATH = object
MLXNAME = $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

LIBFTNAME = libft.a
LIBFTPATH = ../libft

NAME = miniRT
SRCFILES = 01_tuple.c 02_tuple.c 03_tuple.c

MAIN = main.c
TDD_FILES = epsilon tuples
TDD_FULLPATH = $(addsuffix /$(MAIN), $(TDD_FILES))


MAINOBJ = $(OBJPATH)/$(MAIN:.c=.o)
OBJ = $(SRCFILES:%.c=$(OBJPATH)/%.o)

all: libft $(TDD_FILES:%=%/$(NAME))

libft:
	make -C $(LIBFTPATH)

%/$(NAME): %/$(MAIN) $(OBJ)
	$(CC) $(CFLAGS) $(MATHFLAG) $(HEADER) $(OBJ) $< $(LIBFTPATH)/$(LIBFTNAME) -o $@

$(TDD_FULLPATH:.c=.o): %.o : %.c | $(OBJPATH)
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

$(OBJPATH)/%.o: $(SRCPATH)/%.c
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

$(OBJPATH):
	mkdir -p $(OBJPATH)


clean:
	make clean -C $(LIBFTPATH)
	rm -rf $(OBJ) $(OBJ_TST) $(OBJPATH)
	@rm -rf $(LIBMLX)/build

fclean: clean
	make fclean -C $(LIBFTPATH)
	rm -f $(NAME) $(NAME_TST)

re: fclean all

val: all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

.PHONY: all clean fclean re libft