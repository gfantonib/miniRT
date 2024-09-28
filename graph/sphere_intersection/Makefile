CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
SRCPATH = ../../source
MATHFLAG = -lm
INCPATH = ../../include
HEADER = -I $(INCPATH) -I ../../$(LIBMLX)/include
OBJPATH = object

LIBMLX = MLX42
MLXNAME = ../../$(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

LIBNAME = libft.a
LIBPATH = ../../libft

NAME = miniRT
SRCFILES = tuple.c color.c matrix.c matrix2.c matrix3.c matrix4.c error_exit.c epsilon.c transformation.c ray.c sphere.c intersect.c
SRCMAIN = main.c
MAINOBJ = $(OBJPATH)/$(SRCMAIN:.c=.o)
OBJ = $(SRCFILES:%.c=$(OBJPATH)/%.o)

all: libft libmlx $(NAME)

libft:
	make -C $(LIBPATH)

libmlx:
	@cmake ../../$(LIBMLX) -B ../../$(LIBMLX)/build && make -C ../../$(LIBMLX)/build -j4

$(NAME): $(MAINOBJ) $(OBJ)
	$(CC) $(CFLAGS) $(MATHFLAG) $(HEADER) $(OBJ) $(MAINOBJ) $(MLXNAME) $(LIBPATH)/$(LIBNAME) -o $(NAME)

$(MAINOBJ): $(SRCMAIN) | $(OBJPATH)
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

$(OBJPATH)/%.o: $(SRCPATH)/%.c
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

$(OBJPATH):
	mkdir -p $(OBJPATH)

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