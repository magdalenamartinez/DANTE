##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## antman binary
##

NAME	=	generator

LIB	=	-L ../lib/my/ -lmy

INCLUDE	=	-I ./include/

SRC	= 	src/main.c	\
		src/generate.c	\
		src/change.c	\

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
