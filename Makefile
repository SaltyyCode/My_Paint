##
## EPITECH PROJECT, 2023
## Makefile my_hunter
## File description:
## Makefile for my_hunter
##

NAME	=	my_paint

CFLAGS	=	-W -Wall -Wextra

SRC =	src/init/my_window.c \
     	src/handle_events/my_event.c \
		src/main.c \
		src/my_write.c \
		src/my_help.c \
		src/drawzone/my_drawzone.c \
		src/save_image/my_savetoimage.c \
		src/drawzone/my_brush.c \
		src/button/my_button.c \
		src/button/my_about.c \
		src/handle_events/my_handlekey.c \
		src/init/init_tools.c \
		src/button/handle_actions.c \
		src/button/draw_button.c \
		src/init/init_images.c

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
