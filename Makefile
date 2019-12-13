##
## EPITECH PROJECT, 2019
##
## File description:
##
##

SRC 	=	main.c		\
			double_circular_linked_list.c		\
			simple_linked_list.c		\
			radix.c			\
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
