/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** TNA
*/

#ifndef TNA_HPP_
#define TNA_HPP_

#include "../ACommand.hpp"

namespace Zappy {
    class TNA : public ACommand {
        public:
            TNA();
            ~TNA();

            std::vector<std::string> receiveData(std::string message, std::string commandName) override;
            void askCommand(int socket, std::vector<std::string> args);
            void applyChanges(std::vector<std::string> parsedData,
                                std::array<int, 2> &size_map,
                                std::vector<std::vector<std::shared_ptr<Zappy::Tile>>> &tiles,
                                std::vector<std::shared_ptr<Zappy::Player>> &players, 
                                std::vector<std::shared_ptr<Zappy::Egg>> &eggs,
                                std::vector<std::string> &teams,
                                int &timeUnit,
                                bool &isRunning);
        protected:
        private:
    };
}

#endif /* !TNA_HPP_ */
