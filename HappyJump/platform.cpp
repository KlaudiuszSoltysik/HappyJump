#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "platform.h"
#include "object.h"

Platform::Platform(sf::Texture &texture, sf::RenderWindow &window, int &H) : object(texture) {
    setTextureRect(sf::IntRect(0, 0, platform_x, platform_y));
    setPosition(rand()%(window.getSize().x-platform_x), window.getSize().y-H);
    window_x=window.getSize().x;
}
