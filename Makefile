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
		src/main.c \
		src/my_write.c \
		src/my_help.c \
		src/my_drawzone.c \
		src/my_savetoimage.c \
		src/my_brush.c \
		src/my_button.c \
		src/my_handlekey.c

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
