##
## EPITECH PROJECT, 2020
## PSU_navy_2019
## File description:
## Makefile
##


SRC = src/parsing/get_nb_ants.c \
	  src/parsing/get_rooms.c \
	  src/parsing/links.c \
	  src/parsing/parsing1.c \
	  src/parsing/word_len.c

OBJ = $(SRC:%.c=%.o)
OBJ += src/main.o

TESTS = 

COVERAGE = -lcriterion --coverage

INCLUDE = -I include

CFLAGS = $(INCLUDE) -Wall -Wshadow -Wextra

LDFLAGS = -L lib/my -lmy -L lib/lily -llily

BIN = lem_in

UT = ./ut

CC = gcc

all: $(BIN)

$(BIN): $(OBJ)
	$(MAKE) -C lib/my
	$(MAKE) -C lib/lily
	$(CC) -o $(BIN) $(OBJ) $(LDFLAGS)

tests_run:
	$(MAKE) -C lib/my
	$(MAKE) -C lib/lily
	$(CC) -o $(UT) $(SRC) $(TESTS) $(CFLAGS) $(LDFLAGS) $(COVERAGE)
	$(UT)

clean:
	$(MAKE) -C lib/my clean
	$(MAKE) -C lib/lily clean
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(BIN)
	$(RM) *.gc*
	$(RM) $(UT)

ffclean: fclean
	$(MAKE) -C lib/my fclean
	$(MAKE) -C lib/lily fclean

re: fclean all

dbg: CFLAGS += -g
dbg: re