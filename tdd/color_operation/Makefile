CC = cc
CFLAGS = -Wall -Wextra -Werror 
SRCPATH = ../../source
MATHFLAG = -lm
INCPATH = ../../include
HEADER = -I$(INCPATH)
OBJPATH = object

LIBNAME = libft.a
LIBPATH = ../../libft

NAME = miniRT
SRCFILES = tuple.c color.c matrix.c matrix2.c matrix3.c epsilon.c error_exit.c
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
	$(CC) $(CFLAGS) $(MATHFLAG) $(HEADER) $(OBJ) $(MAINOBJ) $(LIBPATH)/$(LIBNAME) -o $(NAME)

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