#ifndef GAME_H
#define GAME_H

#include "MenuState.h"
#include "StateManager.h"

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>

class Game
{
    public:
        Game();

        void run();

        static const sf::Time timePerFrame;

    private:
        sf::RenderWindow m_window;

        StateManager<State::Ptr> m_sm;
};

#endif // GAME_H
