#include "MenuState.h"

MenuState::MenuState( sf::RenderWindow& window )
    : State( window )
{
}

void MenuState::clear()
{
    window.clear( sf::Color::Black );
}

void MenuState::display()
{
    window.display();
}

bool MenuState::draw()
{
    return true;
}

void MenuState::handleEvents( const sf::Event& event )
{
}

void MenuState::update()
{
}

void MenuState::manageAction( StateManager< State::Ptr >& sm )
{
}

MenuState::~MenuState()
{
}
