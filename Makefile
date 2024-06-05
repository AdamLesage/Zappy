##
## EPITECH PROJECT, 2024
## B-OOP-400-NAN-4-1-raytracer-adam.lesage
## File description:
## Makefile
##

SRC_SEVER	=	src/server/main.c											\
			src/server/close_server.c										\
			src/server/connect_client.c										\
			src/server/get_client_command.c									\
			src/server/init_core.c											\
			src/server/init_server.c										\
			src/server/lunch_server.c										\
			src/server/dataManagment/arguments/get_arguments.c				\
			src/server/dataManagment/arguments/get_port.c					\
			src/server/dataManagment/arguments/get_width.c					\
			src/server/dataManagment/arguments/get_height.c					\
			src/server/dataManagment/arguments/get_teams_name.c				\
			src/server/dataManagment/arguments/get_number_client_by_teams.c	\
			src/server/dataManagment/arguments/get_frequency.c				\
			src/server/dataManagment/map/init_map.c							\
			src/server/dataManagment/map/find_tile.c						\
			src/server/dataManagment/map/put_on_map.c						\
			src/server/dataManagment/map/put_on_map2.c						\
			src/server/dataManagment/map/remove_from_map.c					\
			src/server/dataManagment/map/remove_from_map2.c					\
			src/server/dataManagment/players/init_players.c					\
			src/server/dataManagment/players/add_player.c					\
			src/server/dataManagment/players/find_player.c					\
			src/server/dataManagment/players/delete_player.c				\
			src/server/dataManagment/players/move_player.c					\
			src/server/dataManagment/players/turn_left.c					\
			src/server/dataManagment/players/turn_right.c					\
			src/server/dataManagment/players/get_pos.c						\
			src/server/dataManagment/players/get_level.c					\
			src/server/dataManagment/players/get_inventory.c				\
			src/server/dataManagment/players/get_player_team.c				\
			src/server/dataManagment/players/find_nb_player_on_team.c		\
			src/server/dataManagment/players/add_action_on_queue.c			\
			src/server/dataManagment/players/get_action_in_queue.c			\
			src/server/utils/str_is_num.c									\
			src/server/utils/int_to_str.c									\

SRC_GUI				=	src/gui/main.cpp						   			\
						src/gui/Interface.cpp								\
						src/gui/bar.cpp										\
						src/gui/GuiConnect.cpp								\
						src/gui/my_str_to_line_array.cpp					\
						src/gui/my_str_to_word_array.cpp					\
						src/gui/Tile.cpp									\
						src/gui/Inventory.cpp								\
						src/gui/AInventory.cpp								\
						src/gui/Player.cpp									\

SRC_AI				=	src/ai/main.py										  \

SRC_TEST_SERVER		=	src/server/close_server.c							\
			src/server/connect_client.c										\
			src/server/get_client_command.c									\
			src/server/init_core.c											\
			src/server/init_server.c										\
			src/server/lunch_server.c										\
			src/server/dataManagment/arguments/get_arguments.c				\
			src/server/dataManagment/arguments/get_port.c					\
			src/server/dataManagment/arguments/get_width.c					\
			src/server/dataManagment/arguments/get_height.c					\
			src/server/dataManagment/arguments/get_teams_name.c				\
			src/server/dataManagment/arguments/get_number_client_by_teams.c	\
			src/server/dataManagment/arguments/get_frequency.c				\
			src/server/dataManagment/map/init_map.c							\
			src/server/dataManagment/map/find_tile.c						\
			src/server/dataManagment/map/put_on_map.c						\
			src/server/dataManagment/map/put_on_map2.c						\
			src/server/dataManagment/map/remove_from_map.c					\
			src/server/dataManagment/map/remove_from_map2.c					\
			src/server/dataManagment/players/init_players.c					\
			src/server/dataManagment/players/add_player.c					\
			src/server/dataManagment/players/find_player.c					\
			src/server/dataManagment/players/delete_player.c				\
			src/server/dataManagment/players/move_player.c					\
			src/server/dataManagment/players/turn_left.c					\
			src/server/dataManagment/players/turn_right.c					\
			src/server/dataManagment/players/get_pos.c						\
			src/server/dataManagment/players/get_level.c					\
			src/server/dataManagment/players/get_inventory.c				\
			src/server/dataManagment/players/get_player_team.c				\
			src/server/dataManagment/players/find_nb_player_on_team.c		\
			src/server/dataManagment/players/add_action_on_queue.c			\
			src/server/dataManagment/players/get_action_in_queue.c			\
			src/server/utils/str_is_num.c									\
			src/server/utils/int_to_str.c									\

TEST 		=	tests/server/test_arguments.c					\
				tests/server/test_init_map.c					\
				tests/server/test_init_players.c				\
				tests/server/test_find_tiles.c					\
				tests/server/test_map_put.c						\
				tests/server/test_map_remove.c					\
				tests/server/test_player_function.c				\

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
	gcc -o $(NAME_BINARY_SERVER) $(SRC_SEVER) $(CFLAGS) -Iinclude/server

zappy_gui:
	g++ -o $(NAME_BINARY_GUI) $(SRC_GUI) $(CFLAGS) $(SFML)

zappy_ai:
	ln -s -f $(SRC_AI) $(NAME_BINARY_AI)
	chmod 777 ${NAME_BINARY_AI}

clean:
	rm -f unit*
	rm -f *.o

fclean: clean
	rm -f $(NAME_BINARY_SERVER)
	rm -f $(Name)
	rm -f $(NAMETEST)
	rm -f unit*
	rm -f plugins/*.so

re: fclean all

tests_run:
	gcc -o $(NAMETEST) $(SRC_TEST_SERVER) \
	$(TEST) $(CFLAGS) -Iinclude/server -lcriterion --coverage
	./$(NAMETEST)

coverage:
	gcovr --exclude tests/

.PHONY: all clean fclean re zappy_gui

run_epitest: re
	sudo docker build -t epitest:lastest .
	sudo docker run -it epitest:lastest
