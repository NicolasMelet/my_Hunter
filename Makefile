##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC =	create.c	\
	tools.c		\
	main.c		\
	main_loop.c	\
	events.c	\
	sprite_mod.c

OBJ = $(SRC:.c=.o)

NAME = MyHunter

LIB = -l csfml-graphics -l csfml-system -l csfml-window

all:	$(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC) $(LIB) -Iinclude

clean :
	rm -f $(OBJ)
	rm -f *~
	rm -f *.gcno
	rm -f *.gcda
	rm -f coding-style-reports.log

fclean : clean
	rm -f $(NAME)

re:	fclean all
