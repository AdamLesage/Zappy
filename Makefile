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
			src/server/check_food_players.c									\
			src/server/check_win_game.c										\
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
			src/server/dataManagment/map/refill_map.c						\
			src/server/dataManagment/map/find_number_eggs_on_team.c			\
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
			src/server/dataManagment/players/put_on_inventory.c				\
			src/server/dataManagment/players/remove_from_inventory.c		\
			src/server/dataManagment/players/get_player_k.c					\
			src/server/dataManagment/client/add_client.c					\
			src/server/command/GUI_command/execute_gui_command.c			\
			src/server/command/GUI_command/gui_command.c					\
			src/server/command/GUI_command/bct.c							\
			src/server/command/GUI_command/mct.c							\
			src/server/command/GUI_command/msz.c							\
			src/server/command/GUI_command/pin.c							\
			src/server/command/GUI_command/plv.c							\
			src/server/command/GUI_command/ppo.c							\
			src/server/command/GUI_command/sgt.c							\
			src/server/command/GUI_command/sst.c							\
			src/server/command/GUI_command/tna.c							\
			src/server/command/Player_command/get_time_action.c				\
			src/server/command/Player_command/is_know_player_command.c		\
			src/server/command/Player_command/check_player_command.c		\
			src/server/command/Player_command/client_command.c				\
			src/server/command/Player_command/broadcast.c					\
			src/server/command/Player_command/connect_nbr.c					\
			src/server/command/Player_command/eject.c						\
			src/server/command/Player_command/fork.c						\
			src/server/command/Player_command/forward.c						\
			src/server/command/Player_command/incantation.c					\
			src/server/command/Player_command/incantation_is_valide.c		\
			src/server/command/Player_command/incantation_destroy_stone.c	\
			src/server/command/Player_command/inventory.c					\
			src/server/command/Player_command/left.c						\
			src/server/command/Player_command/look.c						\
			src/server/command/Player_command/right.c						\
			src/server/command/Player_command/set.c							\
			src/server/command/Player_command/take.c						\
			src/server/Event/pnw.c											\
			src/server/Event/pex.c											\
			src/server/Event/pbc.c											\
			src/server/Event/pic.c											\
			src/server/Event/pie.c											\
			src/server/Event/pfk.c											\
			src/server/Event/pdr.c											\
			src/server/Event/pgt.c											\
			src/server/Event/pdi.c											\
			src/server/Event/enw.c											\
			src/server/Event/ebo.c											\
			src/server/Event/edi.c											\
			src/server/Event/seg.c											\
			src/server/Event/smg.c											\
			src/server/command/authentification.c							\
			src/server/utils/send_response.c								\
			src/server/utils/str_is_num.c									\
			src/server/utils/int_to_str.c									\
			src/server/utils/free_array.c									\
			src/server/utils/my_str_to_word_array.c							\
			src/server/utils/len_array.c									\
			src/server/utils/string_to_object.c								\

SRC_GUI	=	src/gui/main.cpp						   						\
			src/gui/Interface/Interface.cpp									\
			src/gui/Interface/bar.cpp										\
			src/gui/Interface/InventoryDisplay.cpp							\
			src/gui/Interface/Button.cpp									\
			src/gui/Interface/InfoDisplay.cpp								\
			src/gui/Interface/Broadcast.cpp									\
			src/gui/ServerInfo/GuiConnect.cpp								\
			src/gui/lib/my_str_to_line_array.cpp							\
			src/gui/lib/my_str_to_word_array.cpp							\
			src/gui/lib/split.cpp											\
			src/gui/Entity/Tile.cpp											\
			src/gui/Entity/Inventory.cpp									\
			src/gui/Entity/AInventory.cpp									\
			src/gui/Entity/Player.cpp										\
			src/gui/Entity/Egg.cpp											\
			src/gui/ServerInfo/ServerInfo.cpp								\
			src/gui/ServerInfo/CommandFactory.cpp							\
			src/gui/ServerInfo/ACommand.cpp									\
			src/gui/ServerInfo/Command/MSZ.cpp								\
			src/gui/ServerInfo/Command/PNW.cpp								\
			src/gui/ServerInfo/Command/PPO.cpp								\
			src/gui/ServerInfo/Command/TNA.cpp								\
			src/gui/ServerInfo/Command/PLV.cpp								\
			src/gui/ServerInfo/Command/PIN.cpp								\
			src/gui/ServerInfo/Command/PEX.cpp								\
			src/gui/ServerInfo/Command/PBC.cpp								\
			src/gui/ServerInfo/Command/PIC.cpp								\
			src/gui/ServerInfo/Command/PIE.cpp								\
			src/gui/ServerInfo/Command/PFK.cpp								\
			src/gui/ServerInfo/Command/PDR.cpp								\
			src/gui/ServerInfo/Command/PGT.cpp								\
			src/gui/ServerInfo/Command/PDI.cpp								\
			src/gui/ServerInfo/Command/ENW.cpp								\
			src/gui/ServerInfo/Command/EBO.cpp								\
			src/gui/ServerInfo/Command/EDI.cpp								\
			src/gui/ServerInfo/Command/SGT.cpp								\
			src/gui/ServerInfo/Command/SST.cpp								\
			src/gui/ServerInfo/Command/SEG.cpp								\
			src/gui/ServerInfo/Command/SMG.cpp								\
			src/gui/ServerInfo/Command/SUC.cpp								\
			src/gui/ServerInfo/Command/SBP.cpp								\
			src/gui/ServerInfo/Command/BCT.cpp								\
			src/gui/ServerInfo/Command/MCT.cpp								\
			src/gui/DataManagement/egg_management.cpp						\
			src/gui/DataManagement/player_management.cpp					\
			src/gui/DataManagement/tile_management.cpp						\
			src/gui/DataManagement/server_info_management.cpp				\

SRC_AI				=	src/ai/main.py										\

SRC_TEST_SERVER		=	src/server/close_server.c							\
			src/server/connect_client.c										\
			src/server/get_client_command.c									\
			src/server/init_core.c											\
			src/server/init_server.c										\
			src/server/lunch_server.c										\
			src/server/check_food_players.c									\
			src/server/check_win_game.c										\
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
			src/server/dataManagment/map/refill_map.c						\
			src/server/dataManagment/map/find_number_eggs_on_team.c			\
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
			src/server/dataManagment/players/put_on_inventory.c				\
			src/server/dataManagment/players/remove_from_inventory.c		\
			src/server/dataManagment/players/get_player_k.c					\
			src/server/command/GUI_command/execute_gui_command.c			\
			src/server/command/GUI_command/gui_command.c					\
			src/server/command/GUI_command/bct.c							\
			src/server/command/GUI_command/mct.c							\
			src/server/command/GUI_command/msz.c							\
			src/server/command/GUI_command/pin.c							\
			src/server/command/GUI_command/plv.c							\
			src/server/command/GUI_command/ppo.c							\
			src/server/command/GUI_command/sgt.c							\
			src/server/command/GUI_command/sst.c							\
			src/server/command/GUI_command/tna.c							\
			src/server/command/Player_command/get_time_action.c				\
			src/server/command/Player_command/is_know_player_command.c		\
			src/server/command/Player_command/check_player_command.c		\
			src/server/command/Player_command/client_command.c				\
			src/server/command/Player_command/broadcast.c					\
			src/server/command/Player_command/connect_nbr.c					\
			src/server/command/Player_command/eject.c						\
			src/server/command/Player_command/fork.c						\
			src/server/command/Player_command/forward.c						\
			src/server/command/Player_command/incantation.c					\
			src/server/command/Player_command/incantation_is_valide.c		\
			src/server/command/Player_command/incantation_destroy_stone.c	\
			src/server/command/Player_command/inventory.c					\
			src/server/command/Player_command/left.c						\
			src/server/command/Player_command/look.c						\
			src/server/command/Player_command/right.c						\
			src/server/command/Player_command/set.c							\
			src/server/command/Player_command/take.c						\
			src/server/command/authentification.c							\
			src/server/Event/pnw.c											\
			src/server/Event/pex.c											\
			src/server/Event/pbc.c											\
			src/server/Event/pic.c											\
			src/server/Event/pie.c											\
			src/server/Event/pfk.c											\
			src/server/Event/pdr.c											\
			src/server/Event/pgt.c											\
			src/server/Event/pdi.c											\
			src/server/Event/enw.c											\
			src/server/Event/ebo.c											\
			src/server/Event/edi.c											\
			src/server/Event/seg.c											\
			src/server/Event/smg.c											\
			src/server/utils/send_response.c								\
			src/server/utils/str_is_num.c									\
			src/server/utils/int_to_str.c									\
			src/server/utils/free_array.c									\
			src/server/utils/my_str_to_word_array.c							\
			src/server/utils/len_array.c									\
			src/server/utils/string_to_object.c								\

SRC_TEST_GUI =  src/gui/Interface/Interface.cpp								\
				src/gui/Interface/bar.cpp									\
				src/gui/Interface/InventoryDisplay.cpp						\
				src/gui/Interface/Button.cpp								\
				src/gui/ServerInfo/GuiConnect.cpp							\
				src/gui/lib/my_str_to_line_array.cpp						\
				src/gui/lib/my_str_to_word_array.cpp						\
				src/gui/lib/split.cpp										\
				src/gui/Entity/Tile.cpp										\
				src/gui/Entity/Inventory.cpp								\
				src/gui/Entity/AInventory.cpp								\
				src/gui/Entity/Player.cpp									\
				src/gui/Entity/Egg.cpp										\
				src/gui/ServerInfo/ServerInfo.cpp							\
				src/gui/ServerInfo/CommandFactory.cpp						\
				src/gui/ServerInfo/ACommand.cpp								\
				src/gui/ServerInfo/Command/MSZ.cpp							\
				src/gui/ServerInfo/Command/PNW.cpp							\
				src/gui/ServerInfo/Command/PPO.cpp							\
				src/gui/ServerInfo/Command/TNA.cpp							\
				src/gui/ServerInfo/Command/PLV.cpp							\
				src/gui/ServerInfo/Command/PIN.cpp							\
				src/gui/ServerInfo/Command/PEX.cpp							\
				src/gui/ServerInfo/Command/PBC.cpp							\
				src/gui/ServerInfo/Command/PIC.cpp							\
				src/gui/ServerInfo/Command/PIE.cpp							\
				src/gui/ServerInfo/Command/PFK.cpp							\
				src/gui/ServerInfo/Command/PDR.cpp							\
				src/gui/ServerInfo/Command/PGT.cpp							\
				src/gui/ServerInfo/Command/PDI.cpp							\
				src/gui/ServerInfo/Command/ENW.cpp							\
				src/gui/ServerInfo/Command/EBO.cpp							\
				src/gui/ServerInfo/Command/EDI.cpp							\
				src/gui/ServerInfo/Command/SGT.cpp							\
				src/gui/ServerInfo/Command/SST.cpp							\
				src/gui/ServerInfo/Command/SEG.cpp							\
				src/gui/ServerInfo/Command/SMG.cpp							\
				src/gui/ServerInfo/Command/SUC.cpp							\
				src/gui/ServerInfo/Command/SBP.cpp							\
				src/gui/ServerInfo/Command/BCT.cpp							\
				src/gui/ServerInfo/Command/MCT.cpp							\
				src/gui/DataManagement/egg_management.cpp					\
				src/gui/DataManagement/player_management.cpp				\
				src/gui/DataManagement/tile_management.cpp					\
				src/gui/DataManagement/server_info_management.cpp			\

TEST 		=	tests/server/test_arguments.c					\
				tests/server/test_command_look.c				\
				tests/server/test_player_function.c				\
				tests/server/test_init_map.c					\
				tests/server/test_init_players.c				\
				tests/server/test_find_tiles.c					\
				tests/server/test_map_put.c						\
				tests/server/test_map_remove.c					\
				tests/server/test_check_win_game.c				\
				tests/server/test_command_GUI.c					\
				tests/server/test_command_move_player.c			\
				tests/server/test_command_interact_player.c		\
				tests/server/test_command_fork.c				\
				tests/server/test_command_inventory.c			\
				tests/server/test_command_eject.c				\
				tests/server/test_command_broadcast.c			\
				tests/server/test_command_incantation.c			\
				tests/server/test_event_pnw.c					\
				tests/server/test_event_pex.c					\
				tests/server/test_event_pbc.c					\
				tests/server/test_event_pic.c					\
				tests/server/test_event_pie.c					\
				tests/server/test_event_pfk.c					\
				tests/server/test_event_pdr.c					\
				tests/server/test_event_pgt.c					\
				tests/server/test_event_pdi.c					\
				tests/server/test_event_enw.c					\
				tests/server/test_event_ebo.c					\
				tests/server/test_event_edi.c					\
				tests/server/test_event_seg.c					\
				tests/server/test_event_smg.c					\

TEST_GUI    =   tests/gui/command/test_bct.cpp					\
				tests/gui/command/test_msz.cpp					\
				tests/gui/command/test_pnw.cpp					\
				tests/gui/command/test_ppo.cpp					\
				tests/gui/command/test_plv.cpp					\
				tests/gui/command/test_pin.cpp					\
				tests/gui/command/test_pie.cpp					\
				tests/gui/command/test_pbc.cpp					\
				tests/gui/command/test_pic.cpp					\
				tests/gui/command/test_pfk.cpp					\
				tests/gui/command/test_pdr.cpp					\
				tests/gui/command/test_pgt.cpp					\
				tests/gui/command/test_pdi.cpp					\
				tests/gui/command/test_enw.cpp					\
				tests/gui/command/test_smg.cpp					\
				tests/gui/command/test_suc.cpp					\
				tests/gui/command/test_sbp.cpp					\
				tests/gui/command/test_pex.cpp					\
				tests/gui/command/test_ebo.cpp					\
				tests/gui/command/test_edi.cpp					\
				tests/gui/command/test_mct.cpp					\
				tests/gui/command/test_seg.cpp					\
				tests/gui/command/test_sgt.cpp					\
				tests/gui/command/test_sst.cpp					\
				tests/gui/command/test_tna.cpp					\

Name		=	zappy

NAME_BINARY_SERVER	=	zappy_server

NAME_BINARY_GUI		=	zappy_gui

NAME_BINARY_AI		=	zappy_ai

NAMETEST 	=	unit_tests

CFLAGS		= 	-Wall -Wextra -Wshadow

SFML		=	-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

all:    $(Name)

$(Name): zappy_server

zappy_server:
	gcc -o $(NAME_BINARY_SERVER) $(SRC_SEVER) $(CFLAGS) -Iinclude/server -lm

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

tests_gui_run:
	g++ -o $(NAMETEST) $(SRC_TEST_GUI) \
	$(TEST_GUI) $(CFLAGS) -lcriterion --coverage $(SFML)
	./$(NAMETEST)

tests_run:
	gcc -o $(NAMETEST) $(SRC_TEST_SERVER) \
	$(TEST) $(CFLAGS) -Iinclude/server -lcriterion --coverage -lm
	./$(NAMETEST)

coverage:
	gcovr --exclude tests/

.PHONY: all clean fclean re zappy_gui

run_epitest: re
	sudo docker build -t epitest:lastest .
	sudo docker run -it epitest:lastest
