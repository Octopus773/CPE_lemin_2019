##
## EPITECH PROJECT, 2019
## makefile
## File description:
## Makefile
##

SRC			=	src/get_nb_ants.c	\
				src/get_rooms.c		\
				src/links.c			\
				src/parsing1.c		\

MAIN		=	src/main.c			\

LIB			=	lib/my_getnbr.c		\
				lib/my_put_nbr.c	\
				lib/my_putchar.c	\
				lib/my_putstr.c		\
				lib/my_strcmp.c		\
				lib/my_strlen.c		\
				lib/word_len.c		\

OBJ			=	$(SRC:.c=.o)
OBJ			+=	$(MAIN:.c=.o)
OBJ			+=	$(LIB:.c=.o)

TESTS_FILES	=

CFLAGS		=	-I./include -Wall -Wextra -Wshadow

LDFLAGS		= 	-I./include

CC			=	gcc

NAME		=	parsing

all:		$(NAME)

$(NAME):		$(OBJ)
			$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

clean:
			rm -f $(OBJ)

clean_tests:
			rm -f unit_tests
			rm -f *.gcno
			rm -f *.gcda

fclean:		clean clean_tests
			rm -f $(NAME)

re:			fclean all

tests_run:
			$(CC) -o unit_tests $(SRC) $(TESTS_FILES) $(CFLAGS) $(LDFLAGS) -lcriterion --coverage
			./unit_tests
