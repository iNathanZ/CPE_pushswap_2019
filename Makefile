##
## EPITECH PROJECT, 2019
##
## File description:
##
##

SRC 	=	main.c		\
		lib/libmy.a

NAME	= 	pushswap


all: $(NAME)

$(NAME):
	make -C lib/my all
	gcc -o $(NAME) $(SRC) -g3 -lm

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all
