#ifndef MENUSTATE_H
#define MENUSTATE_H

#include <SFML/Graphics.hpp>
#include "State.h"

class MenuState : public State
{
    public:
        explicit MenuState( sf::RenderWindow& window );

        void clear();

        void display();

        bool draw();

        void handleEvents( const sf::Event& event );

        void update();

        void manageAction( StateManager< State::Ptr >& sm );

        virtual ~MenuState();
};

#endif // MENUSTATE_H
