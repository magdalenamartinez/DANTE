##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## antman binary
##

NAME	=	dante

LIB	=	-L lib/my/ -lmy

INCLUDE	=	-I ./include/

CDLIB = lib/my/
all: 	$(NAME)

$(NAME): 	$(OBJ)
		make -C $(CDLIB)
		make -C ./generator
		make -C ./solver

clean:
	rm -f $(NAME)
	make -C $(CDLIB) fclean
	rm -f libmy.a
	make -C generator fclean
	make -C solver fclean

fclean: clean

re: 	fclean all

library: fclean

exec:	re
	./$(NAME)
