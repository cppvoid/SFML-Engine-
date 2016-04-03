#include "Game.h"

const sf::Time Game::timePerFrame = sf::seconds(1.f/60.f);

Game::Game()
    :
    m_window(sf::VideoMode( 800, 640 ), "SF::GameEngine 1.0" ),
    m_sm(State::Ptr(new MenuState(m_window)))
{
}

void Game::run()
{
    sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	m_window.setKeyRepeatEnabled(false);

    while( !m_sm.empty() and m_window.isOpen() )
    {
        sf::Time elapsedTime = clock.restart();
		timeSinceLastUpdate += elapsedTime;

        while (timeSinceLastUpdate > timePerFrame)
        {
            timeSinceLastUpdate -= timePerFrame;

            sf::Event event;
            while(m_window.pollEvent(event))
            {
                if(event.type == sf::Event::Closed)
				{
					m_window.close();

					return;
				}

                m_sm.handleEvents( event );
            }

            m_sm.clear();
            m_sm.update();
            m_sm.draw();
            m_sm.display();
            m_sm.manageAction();
        }
    }
}
