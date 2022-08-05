#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "platform.h"
#include "bee.h"
#include "object.h"

Bee::Bee(sf::RenderWindow &window) {
    bee_texture.loadFromFile("bee.png");
    setScale((200/bee_texture.getSize().x), (140/bee_texture.getSize().y));
    setPosition(rand()%(window.getSize().x-50), (rand()%3)*270+50);
    setTexture(bee_texture);
    setTextureRect(sf::IntRect(0, 0, W+43, 50));
    do {
        velocity=rand()%8-4;
    } while (velocity==0);  
    window_x=window.getSize().x;
};

void Bee::move() {
    if(velocity>0) {
        setTextureRect(sf::IntRect(W+43, 0, -43, 50));
    }
    if(velocity<0) {
        setTextureRect(sf::IntRect(W, 0, 43, 50));
    }
    object::move();
}

void Bee::flip() {
    if(W==0) {
        W+=43;
    }
    else {
        W-=43;
    }
}
