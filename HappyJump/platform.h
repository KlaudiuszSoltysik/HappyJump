#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <object.h>
#ifndef PLATFORM_H
#define PLATFORM_H

using namespace std;

class Platform : public object {
public:
    Platform(sf::Texture &texture, sf::RenderWindow &window, int &H);  
};

#endif 
