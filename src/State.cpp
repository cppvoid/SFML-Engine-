#include "StateManager.h"
#include "State.h"

State::State(sf::RenderWindow& window)
    : m_window(window)
{
}

void State::changeState(StateManager<Ptr>& sm, Ptr p)
{
    sm.change(std::move(p));
}

void State::pushState(StateManager<Ptr>& sm, Ptr p)
{
    sm.push(std::move(p));
}

void State::popState(StateManager<Ptr>& sm)
{
    sm.pop();
}

State::~State()
{
}
