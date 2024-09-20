CC = cc
CFLAGS = -Wall -Wextra -Werror
MATHFLAG = -lm
SRCPATH = source
INCPATH = include
LIBMLX = MLX42
HEADER = -I $(INCPATH) -I $(LIBMLX)/include
OBJPATH = object
MLXNAME = $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

LIBFTNAME = libft.a
LIBFTPATH = libft

NAME = miniRT
SRCFILES = tuple.c tuple2.c tuple3.c
SRCMAIN = main.c
MAINOBJ = $(OBJPATH)/$(SRCMAIN:.c=.o)
OBJ = $(SRCFILES:%.c=$(OBJPATH)/%.o)

NAME_TST = 
SRCFILES_TST =
SRCMAIN_TST = 
MAINOBJ_TST = $(OBJPATH)/$(SRCMAIN_TST:.c=.o)
OBJ_TST = $(SRCFILES_TST:%.c=$(OBJPATH)/%.o)

all: libft libmlx $(NAME)

libft:
	make -C $(LIBFTPATH)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(NAME): $(MAINOBJ) $(OBJ)
	$(CC) $(CFLAGS) $(MATHFLAG)  $(HEADER) $(OBJ) $(MAINOBJ) $(MLXNAME) $(LIBFTPATH)/$(LIBFTNAME)  -o $(NAME)

$(MAINOBJ): $(SRCMAIN) | $(OBJPATH)
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

$(OBJPATH)/%.o: $(SRCPATH)/%.c
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

$(OBJPATH):
	mkdir -p $(OBJPATH)

test: all
	$(MAKE) NAME=$(NAME_TST) SRCFILES=$(SRCFILES_TST) SRCMAIN=$(SRCMAIN_TST) OBJ=$(OBJ_TST) MAINOBJ=$(MAINOBJ_TST) all

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