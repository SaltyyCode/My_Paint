##
## EPITECH PROJECT, 2023
## Makefile my_hunter
## File description:
## Makefile for my_hunter
##

NAME	=	my_paint

CFLAGS	=	-W -Wall -Wextra

SRC =	src/my_window.c \
     	src/my_event.c \
		src/main.c

OBJ = $(SRC:.c=.o)

CSFML	=	-lcsfml-graphics -lcsfml-window -lcsfml-audio -lcsfml-system

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc $(OBJ) -o $(NAME) -I../include $(CFLAGS) $(CSFML) -g3

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re