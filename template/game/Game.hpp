#ifndef _GAME_GAME_H_
#define _GAME_GAME_H_

#include "Assets.hpp"
#include "../z_framework/zf_sfml/Mouse.hpp"
#include <SFML/Graphics.hpp>

#include <string>
#include <iostream>
class Screen;
class Game
{
    public:
        Game();
        ~Game();
        void run(); 




        const sf::Int32 _width;
        const sf::Int32 _height;
        std::string _title;
        sf::RenderWindow _window; 
        zf::Mouse _mouse;
        Assets _assets;
        void loadAssets();
    private:
        void update(sf::Time delta);
        void draw(sf::Time delta);
        
        Screen* _currentScreen;        
};


#endif

