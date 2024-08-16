##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## antman binary
##

NAME	=	solver

LIB	=	-L ../lib/my/ -lmy

INCLUDE	=	-I ./include/

SRC	= 	src/main.c	\
		src/read.c	\
		src/map.c	\

OBJ	=	$(SRC:.c=.o)

all: 	$(NAME)

$(NAME): 	$(OBJ)
		gcc -g $(OBJ) -o $(NAME) $(INCLUDE) $(LIB)

clean:
	rm -f $(NAME)

fclean: clean
	rm -f ./src/*.o

re: 	fclean all

library: fclean

exec:	re
	./$(NAME)
