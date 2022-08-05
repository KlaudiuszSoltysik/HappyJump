#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <object.h>
#ifndef BEE_H
#define BEE_H

class Bee : public object {
private:
    sf::Texture bee_texture;        

    int W=0;    
public:

    Bee(sf::RenderWindow &window);  

    void move();

    void flip();
};

#endif 
