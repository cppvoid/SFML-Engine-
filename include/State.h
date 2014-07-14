#ifndef STATE_H
#define STATE_H

#include "StateManager.h"
#include <SFML/Graphics.hpp>
#include <memory>

class State
{
    public:
        explicit State( sf::RenderWindow& window );

        typedef std::unique_ptr< State > Ptr;

        void changeState( StateManager< Ptr >& sm, Ptr p );

        void pushState( StateManager< Ptr >& sm, Ptr p );

        void popState( StateManager< Ptr >& sm );

		virtual void clear() = 0;

		virtual void display() = 0;

        virtual bool draw() = 0;

        virtual void handleEvents( const sf::Event& event ) = 0;

        virtual void update() = 0;

        virtual void manageAction( StateManager< Ptr >& sm ) = 0;

        virtual ~State();

    protected:
        sf::RenderWindow& window;

    private:
        State(State const&) = delete;

        State& operator=(State const&) = delete;
};

#endif // STATE_H
