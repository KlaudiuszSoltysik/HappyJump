#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#ifndef OBJECT_H
#define OBJECT_H


class object : public sf::Sprite
{
public:
    int velocity=0;                 
    int window_x;                  
    const int platform_x=384;     
    const int platform_y=60;      

    object(sf::Texture &texture);

    object();   

    void move();   

    virtual void bump();
};

#endif
