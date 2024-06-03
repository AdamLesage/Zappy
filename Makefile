##
## EPITECH PROJECT, 2024
## B-OOP-400-NAN-4-1-raytracer-adam.lesage
## File description:
## Makefile
##

SRC_SEVER			=	src/server/main.c									  \
						src/server/close_server.c							  \
						src/server/connect_client.c							  \
						src/server/get_client_command.c						  \
						src/server/init_core.c								  \
						src/server/init_server.c							  \
						src/server/lunch_server.c							  \

SRC_GUI				=	src/gui/main.cpp						   			\
						src/gui/Interface.cpp								\
						src/gui/bar.cpp										\
						src/gui/gui_connect.cpp								\
						src/gui/my_str_to_line_array.cpp					\
						src/gui/my_str_to_word_array.cpp					\
						src/gui/Tile.cpp									\
						src/gui/Inventory.cpp								\
						src/gui/AInventory.cpp								\
						src/gui/Player.cpp									\

SRC_AI				=	src/ai/main.py										  \

TEST 		=	\

Name		=	zappy

NAME_BINARY_SERVER	=	zappy_server

NAME_BINARY_GUI		=	zappy_gui

NAME_BINARY_AI		=	zappy_ai

NAMETEST 	=	unit_tests

CFLAGS		= 	-Wall -Wextra -Wshadow

SFML		=	-lsfml-graphics -lsfml-window -lsfml-system

all:    $(Name)

$(Name): zappy_server zappy_ai

zappy_server:
	gcc -o $(NAME_BINARY_SERVER) $(SRC_SEVER) $(CFLAGS)

zappy_gui:
	g++ -o $(NAME_BINARY_GUI) $(SRC_GUI) $(CFLAGS) $(SFML)

zappy_ai:
	ln -s -f $(SRC_AI) $(NAME_BINARY_AI)
	chmod 777 ${NAME_BINARY_AI}

clean:
	rm -f unit*
	rm -f *.o

fclean: clean
	rm -f $(Name)
	rm -f $(NAMETEST)
	rm -f unit*
	rm -f plugins/*.so

re: fclean all

tests_run:
	g++ -o $(NAMETEST) $(SRC_TEST) $(TEST) $(CFLAGS) -lcriterion --coverage
	./$(NAMETEST)

coverage:
	gcovr --exclude tests/

.PHONY: all clean fclean re zappy_gui

run_epitest: re
	sudo docker build -t epitest:lastest .
	sudo docker run -it epitest:lastest
