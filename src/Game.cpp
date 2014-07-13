#include "Game.h"

const sf::Time Game::timePerFrame = sf::seconds(1.f/60.f);

Game::Game()
    :
    window( sf::VideoMode( 800, 640 ), "SF::GameEngine 1.0" ),
    sm( State::Ptr( new MenuState() ) )
{
    std::srand( static_cast<unsigned> ( time(nullptr) ) );
}

void Game::run()
{
    sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	window.setKeyRepeatEnabled(false);

    while( !sm.empty() and window.isOpen() )
    {
        sf::Time elapsedTime = clock.restart();
		timeSinceLastUpdate += elapsedTime;

        while (timeSinceLastUpdate > timePerFrame)
        {
            timeSinceLastUpdate -= timePerFrame;

            sf::Event event;
            while( window.pollEvent( event ) )
            {
                if( event.type == sf::Event::Closed )
                    window.close();

                sm.handleEvents( event );
            }

            sm.clear( window );
            sm.update();
            sm.draw( window );
            sm.display( window );
            sm.manageAction();
        }
    }

}
