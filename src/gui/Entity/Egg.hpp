/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Egg
*/

#ifndef EGG_HPP_
#define EGG_HPP_

#include "APlayer.hpp"

namespace Zappy {
    class Egg : public APlayer {
        public:
            Egg();
            ~Egg();
            int getEggNb() const { return _eggNb; }
            void setEggNb(int eggNb) { _eggNb = eggNb; }

        int _eggNb;
        protected:
        private:
    };
}

#endif /* !EGG_HPP_ */
