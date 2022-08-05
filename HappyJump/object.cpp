#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "object.h"

object::object(sf::Texture &texture) : sf::Sprite(texture) {

}
object::object() : sf::Sprite() {

}
void object::move() {
    sf::FloatRect bounds=getGlobalBounds();
    if(bounds.left<0) {
        velocity=-velocity;
    }
    else if(bounds.left+bounds.width>window_x) {
        velocity=-velocity;
    }
    sf::Sprite::move(velocity, 0);
}

void object::bump() {

}
