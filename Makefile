##
## EPITECH PROJECT, 2024
## B-OOP-400-NAN-4-1-raytracer-adam.lesage
## File description:
## Makefile
##

SRC_SEVER			=	src/server/main.c									\
						src/server/close_server.c							\
						src/server/connect_client.c							\
						src/server/get_client_command.c						\
						src/server/init_core.c								\
						src/server/init_server.c							\
						src/server/lunch_server.c							\
						src/server/dataManagment/arguments/get_arguments.c	\
						src/server/dataManagment/arguments/get_port.c		\
						src/server/dataManagment/arguments/get_width.c		\
						src/server/dataManagment/arguments/get_height.c		\
						src/server/dataManagment/arguments/get_teams_name.c	\
						src/server/utils/str_is_num.c						\

SRC_GUI				=	src/gui/main.cpp							   		  \

TEST 		=	\

Name		=	zappy

NAME_BINARY_SERVER	=	zappy_server

NAME_BINARY_GUI		=	zappy_gui

NAMETEST 	=	unit_tests

CFLAGS		= 	-Wall -Wextra -Wshadow

all:    $(Name)

$(Name): server

server:
	gcc -o $(NAME_BINARY_SERVER) $(SRC_SEVER) $(CFLAGS)

zappy_gui:
	g++ -o $(NAME_BINARY_GUI) $(SRC_GUI) $(CFLAGS)
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

.PHONY: all clean fclean re

run_epitest: re
	sudo docker build -t epitest:lastest .
	sudo docker run -it epitest:lastest
