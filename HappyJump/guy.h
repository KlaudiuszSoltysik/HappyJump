#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <platform.h>
#include <bee.h>
#ifndef GUY_H
#define GUY_H

class Guy : public sf::Sprite
{
private:
    const float s=10;         
    const float g=10;          
    float sy=45;             
    float sy2=1;              
    int points=-1;           
    const int platform_x=384;   
    const int platform_y=60;  

    sf::Texture grass_texture;
    sf::Texture brick_texture;
    sf::Texture cloud_texture;

    vector<unique_ptr<object>> platforms;
    vector<unique_ptr<Bee>> bees;

    void new_map(sf::RenderWindow &window); 

public:
    Guy(sf::Texture &texture, sf::RenderWindow &window);

    void animate(sf::RenderWindow &window, sf::Text &text, int elapsed_frames);

    bool left=0;   
    bool right=0;   
    bool lock=1;   
};

#endif 
