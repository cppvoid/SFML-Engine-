#ifndef STATEMANAGER_CPP
#define STATEMANAGER_CPP

#include "StateManager.h"

template< class T >
StateManager<T>::StateManager( T ptr )
{
    stateStack.push_back( std::move( ptr ) );
}

template< class T >
void StateManager<T>::change( T Ptr )
{
    pop();
    push( std::move( Ptr ) );
}

template < class T >
void StateManager<T>::push( T ptr )
{
    stateStack.push_back( std::move( ptr ) );
}

template < class T >
void StateManager<T>::pop()
{
    stateStack.pop_back();
}

template < class T >
void StateManager<T>::clear()
{
    stateStack.back()->clear();
}

template < class T >
void StateManager<T>::draw()
{
    for(auto& i : boost::adaptors::reverse( stateStack ) )
    {
        bool backward = i->draw();
        if(!backward)
            break;
    }
}

template< class T >
void StateManager<T>::handleEvents( const sf::Event& event )
{
    stateStack.back()->handleEvents( event );
}

template < class T >
void StateManager<T>::update()
{
    stateStack.back()->update();
}

template< class T >
void StateManager<T>::display()
{
    stateStack.back()->display();
}

template< class T >
void StateManager<T>::manageAction()
{
    stateStack.back()->manageAction(*this);
}

template< class T >
bool StateManager<T>::empty()
{
    return stateStack.empty();
}

#endif //STATEMANAGER_CPP
