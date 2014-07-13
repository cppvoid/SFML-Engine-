#ifndef MENUSTATE_H
#define MENUSTATE_H

#include <SFML/Graphics.hpp>
#include "State.h"

class MenuState : public State
{
    public:
        explicit MenuState();

        void clear( sf::RenderWindow& window );

        void display( sf::RenderWindow& window );

        bool draw( sf::RenderWindow& window );

        void handleEvents( const sf::Event& event );

        void update();

        void manageAction( StateManager< State::Ptr >& sm );

        virtual ~MenuState();
};

#endif // MENUSTATE_H
