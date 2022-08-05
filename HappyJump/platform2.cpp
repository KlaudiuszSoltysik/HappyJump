#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "platform2.h"
#include "object.h"

Platform2::Platform2(sf::Texture &texture, sf::RenderWindow &window, int &H) : object(texture) {
    setTextureRect(sf::IntRect(0, 0, platform_x, platform_y));
    setPosition(rand()%(window.getSize().x-platform_x), window.getSize().y-H);
    window_x=window.getSize().x;
}

void Platform2::bump() {
    setPosition(-1000, -1000);
}

