#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <object.h>
#ifndef PLATFORM3_H
#define PLATFORM3_H

using namespace std;

class Platform3 : public object {
public:
    Platform3(sf::Texture &texture, sf::RenderWindow &window, int &H); 
};

#endif 
