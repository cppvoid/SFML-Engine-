#ifndef STATEMANAGER_CPP
#define STATEMANAGER_CPP

#include "StateManager.h"

template<typename T>
StateManager<T>::StateManager(T ptr)
{
    m_stateStack.push_back(std::move(ptr));
}

template<typename T>
void StateManager<T>::change(T Ptr)
{
    pop();
    push(std::move(Ptr));
}

template<typename T>
void StateManager<T>::push(T ptr)
{
    m_stateStack.push_back(std::move(ptr));
}

template<typename T>
void StateManager<T>::pop()
{
    m_stateStack.pop_back();
}

template<typename T>
void StateManager<T>::clear()
{
    m_stateStack.back()->clear();
}

template<typename T>
void StateManager<T>::draw()
{
    for(auto& i : boost::adaptors::reverse(m_stateStack))
    {
        bool backward = i->draw();
        if(!backward)
		{
			break;
		}
    }
}

template<typename T>
void StateManager<T>::handleEvents(const sf::Event& event)
{
    m_stateStack.back()->handleEvents(event);
}

template<typename T>
void StateManager<T>::update()
{
    m_stateStack.back()->update();
}

template<typename T>
void StateManager<T>::display()
{
    m_stateStack.back()->display();
}

template<typename T>
void StateManager<T>::manageAction()
{
    m_stateStack.back()->manageAction(*this);
}

template<typename T>
bool StateManager<T>::empty()
{
    return m_stateStack.empty();
}

#endif //STATEMANAGER_CPP
