#include "MenuState.h"

MenuState::MenuState()
{
}

void MenuState::clear( sf::RenderWindow& window )
{
    window.clear( sf::Color::Black );
}

void MenuState::display( sf::RenderWindow& window )
{
    window.display();
}

bool MenuState::draw( sf::RenderWindow& window )
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
