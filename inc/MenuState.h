#ifndef MENUSTATE_H
#define MENUSTATE_H

#include <SFML/Graphics.hpp>
#include "State.h"

class MenuState final : public State
{
    public:
        explicit MenuState(sf::RenderWindow& window);

        void clear() override;

        void display() override;

        bool draw() override;

        void handleEvents(const sf::Event& event) override;

        void update() override;

        void manageAction(StateManager<State::Ptr>& sm) override;

        virtual ~MenuState() override;
};

#endif // MENUSTATE_H
