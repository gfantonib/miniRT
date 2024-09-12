CC = cc
CFLAGS = -Wall -Wextra -Werror
MATHFLAG = -lm
SRCPATH = ../source
INCPATH = ../include
HEADER = -I $(INCPATH)
OBJPATH = object

LIBFTNAME = libft.a
LIBFTPATH = ../libft

SRCFILES = 01_tuple.c 02_tuple.c 03_tuple.c
OBJ = $(SRCFILES:%.c=$(OBJPATH)/%.o)

# Paths for the different targets
EPSILON_PATH = epsilon
TUPLES_PATH = tuples

EPSILON_MAIN = $(EPSILON_PATH)/main.c
TUPLES_MAIN = $(TUPLES_PATH)/main.c

EPSILON_OBJ = $(OBJPATH)/epsilon_main.o
TUPLES_OBJ = $(OBJPATH)/tuples_main.o

# Targets
all: epsilon tuples

# Compile for epsilon
epsilon: libft $(EPSILON_PATH)/miniRT

$(EPSILON_PATH)/miniRT: $(OBJ) $(EPSILON_OBJ)
	$(CC) $(CFLAGS) $(MATHFLAG) $(HEADER) $(OBJ) $(EPSILON_OBJ) $(LIBFTPATH)/$(LIBFTNAME) -o $@

$(EPSILON_OBJ): $(EPSILON_MAIN) | $(OBJPATH)
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

# Compile for tuples
tuples: libft $(TUPLES_PATH)/miniRT

$(TUPLES_PATH)/miniRT: $(OBJ) $(TUPLES_OBJ)
	$(CC) $(CFLAGS) $(MATHFLAG) $(HEADER) $(OBJ) $(TUPLES_OBJ) $(LIBFTPATH)/$(LIBFTNAME) -o $@

$(TUPLES_OBJ): $(TUPLES_MAIN) | $(OBJPATH)
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

$(OBJPATH)/%.o: $(SRCPATH)/%.c | $(OBJPATH)
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

$(OBJPATH):
	mkdir -p $(OBJPATH)

libft:
	make -C $(LIBFTPATH)

clean:
	make clean -C $(LIBFTPATH)
	rm -rf $(OBJ) $(EPSILON_OBJ) $(TUPLES_OBJ) $(OBJPATH)

fclean: clean
	make fclean -C $(LIBFTPATH)
	rm -f $(EPSILON_PATH)/miniRT $(TUPLES_PATH)/miniRT

re: fclean all

val_epsilon: epsilon
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes $(EPSILON_PATH)/miniRT

val_tuples: tuples
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes $(TUPLES_PATH)/miniRT

.PHONY: all clean fclean re libft epsilon tuples