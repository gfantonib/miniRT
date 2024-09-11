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
MAIN_PATH = epsilon

MAINOBJ = $(OBJPATH)/$(MAIN:.c=.o)
OBJ = $(SRCFILES:%.c=$(OBJPATH)/%.o)

all: libft $(NAME)

libft:
	make -C $(LIBFTPATH)

$(NAME): $(MAINOBJ) $(OBJ)
	$(CC) $(CFLAGS) $(MATHFLAG)  $(HEADER) $(OBJ) $(MAINOBJ) $(LIBFTPATH)/$(LIBFTNAME)  -o $(MAIN_PATH)/$(NAME)

$(MAINOBJ): $(MAIN_PATH)/$(MAIN) | $(OBJPATH)
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