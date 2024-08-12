CC = cc
CFLAGS = -Wall -Wextra -Werror -lm
SRCPATH = source
INCPATH = include
HEADER = -I$(INCPATH)
OBJPATH = object

LIBNAME = libft.a
LIBPATH = library

NAME = miniRT
SRCFILES = 01_tuple.c 02_tuple.c 03_tuple.c
SRCMAIN = main.c
MAINOBJ = $(OBJPATH)/$(SRCMAIN:.c=.o)
OBJ = $(SRCFILES:%.c=$(OBJPATH)/%.o)

NAME_TST = 
SRCFILES_TST =
SRCMAIN_TST = 
MAINOBJ_TST = $(OBJPATH)/$(SRCMAIN_TST:.c=.o)
OBJ_TST = $(SRCFILES_TST:%.c=$(OBJPATH)/%.o)

all: libft $(NAME)

libft:
	make -C $(LIBPATH)

$(NAME): $(MAINOBJ) $(OBJ)
	$(CC) $(CFLAGS) $(HEADER) $(OBJ) $(MAINOBJ) $(LIBPATH)/$(LIBNAME) -o $(NAME)

$(MAINOBJ): $(SRCMAIN) | $(OBJPATH)
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

$(OBJPATH)/%.o: $(SRCPATH)/%.c
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

$(OBJPATH):
	mkdir -p $(OBJPATH)

test: all
	$(MAKE) NAME=$(NAME_TST) SRCFILES=$(SRCFILES_TST) SRCMAIN=$(SRCMAIN_TST) OBJ=$(OBJ_TST) MAINOBJ=$(MAINOBJ_TST) all

clean:
	make clean -C $(LIBPATH)
	rm -rf $(OBJ) $(OBJ_TST) $(OBJPATH)

fclean: clean
	make fclean -C $(LIBPATH)
	rm -f $(NAME) $(NAME_TST)

re: fclean all

val: all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

.PHONY: all clean fclean re