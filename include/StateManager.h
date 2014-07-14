#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include <boost/range/adaptor/reversed.hpp>
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include <iostream>
#include <algorithm>

template< class T >
class StateManager
{
    public:
        explicit StateManager( T ptr );

        void change( T ptr );

        void push( T ptr );

        void pop();

		void clear();

        void draw();

        void handleEvents( const sf::Event& event );

        void update();

        void display();

        void manageAction();

        bool empty();

    private:
        std::vector< T > stateStack;
};

#include "StateManager.cpp"

#endif // STATEMANAGER_H
