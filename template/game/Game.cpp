#include "Game.hpp"

#include "screens/Screen.hpp"
#include <SFML/Graphics.hpp>


#define CLEAR_COLOR sf::Color(20,20,20,255)
#define GAME_TITLE "Game Name"
#define GAME_WIDTH 640
#define GAME_HEIGHT 640

Game::Game()
    :width(GAME_WIDTH), height(GAME_HEIGHT), title(GAME_TITLE),mouse(),
    _window(sf::VideoMode(width,height),title)
{
}

Game::~Game()
{

}

void Game::run()
{
    sf::Clock clock; // set up the clock for delta

    bool quit = false;

    while(!quit && _window.isOpen())
    {
        // update clock 
        sf::Time delta = clock.restart();
        // update mouse.
        _mouse.update(delta);
        

        // check for events, especially mousewheel
        sf::Event event;
        while(_window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                _window.close();
                quit = true;
            }
            else if(event.type == sf::Event::MouseWheelMoved)
            {
                _mouse.wheelDelta = event.mouseWheel.delta;
            }
        }

        // if not quit , update then draw.
        if(!quit)
        {
            update(delta);
            draw(delta);
        }
    }
}

void Game::update(sf::Time delta)
{

}

void Game::draw(sf::Time delta)
{
    _window.clear(CLEAR_COLOR);
    if(_currentScreen != 0)
    {
        _currentScreen->draw(_window,delta);   
    }
    _window.display();
}
