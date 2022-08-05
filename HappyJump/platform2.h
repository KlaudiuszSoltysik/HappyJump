#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <object.h>
#ifndef PLATFORM2_H
#define PLATFORM2_H

using namespace std;

class Platform2 : public object {
public:
    Platform2(sf::Texture &texture, sf::RenderWindow &window, int &H); 

    void bump();
};

#endif
