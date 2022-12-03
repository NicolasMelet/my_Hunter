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
	sprite_mod.c	\
	display.c	\
	my_strcmp.c	\
	clean.c		\
	character.c	\
	set_score.c	\
	put.c		\
	get.c		\
	collision.c	\
	infos.c

OBJ = $(SRC:.c=.o)

NAME = my_hunter

LIB = -l csfml-graphics -l csfml-system -l csfml-window -l csfml-audio

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
