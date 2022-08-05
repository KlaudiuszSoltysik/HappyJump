#include "guy.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <ctime>
#include <vector>
#include <memory>

using namespace std;

int main() {
    sf::RenderWindow window(sf::VideoMode(1280, 960), "Pawel Jumper", sf::Style::Close);
    window.setPosition(sf::Vector2i(320, 0));
    window.setFramerateLimit(60);
    sf::Texture menu_texture;
    menu_texture.loadFromFile("menu.png");
    menu_texture.setRepeated(true);
    sf::Texture background_texture;
    background_texture.loadFromFile("background.png");
    background_texture.setRepeated(true);
    sf::Texture guy_texture;
    guy_texture.loadFromFile("guy.png");

    sf::Sprite menu(menu_texture);
    menu.setTextureRect(sf::IntRect(0, 0, window.getSize().x, window.getSize().y));
    Guy guy(guy_texture, window);

    sf::Music music;
    music.openFromFile("enter_the_east.wav");
    music.setLoop(true);
    music.play();

    sf::Font font;
    font.loadFromFile("font.ttf");
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(150);
    text.setFillColor(sf::Color::Black);

    sf::Vector2f size(200, 75);
    sf::RectangleShape button(size);
    button.setPosition((window.getSize().x-size.x)/2, (window.getSize().y-size.y)/2);
    button.setFillColor(sf::Color(0, 0, 255));
    sf::Text text2;
    text2.setFont(font);
    text2.setCharacterSize(50);
    text2.setPosition((window.getSize().x-size.x)/2, (window.getSize().y-size.y)/2);
    text2.setString("nowa gra");
    text2.setFillColor(sf::Color::Black);

    int elapsed_frames=0;
    while(window.isOpen()) {
        elapsed_frames+=1;
        sf::Event event;
        while(window.pollEvent(event)) {
            if (event.type==sf::Event::Closed) {
                window.close();
            }
            if(event.type==sf::Event::KeyPressed) {
                if(event.key.code==sf::Keyboard::Escape) {
                    window.close();
                }
                if(event.key.code==sf::Keyboard::Space) {
                    guy.lock=0;
                    menu.setTexture(background_texture);
                }
                if(event.key.code==sf::Keyboard::Left) {
                    guy.left=1;
                }
                if(event.key.code==sf::Keyboard::Right) {
                    guy.right=1;
                }
                if(event.key.code==sf::Keyboard::R) {
                    window.close();
                    main();
                }
            }
            if(event.type==sf::Event::KeyReleased) {
                if(event.key.code==sf::Keyboard::Left) {
                    guy.left=0;
                }
                if(event.key.code==sf::Keyboard::Right) {
                    guy.right=0;
                }
            }
            if(event.type==sf::Event::MouseButtonPressed) {
                if(event.mouseButton.button==sf::Mouse::Left) {
                    sf::Vector2i mouse_pos=sf::Mouse::getPosition(window);
                    sf::FloatRect rectangle_bounds = button.getGlobalBounds();
                    if(mouse_pos.x>=rectangle_bounds.left && mouse_pos.x<=rectangle_bounds.left+rectangle_bounds.width && mouse_pos.y>=rectangle_bounds.top && mouse_pos.y<=rectangle_bounds.top+rectangle_bounds.height) {
                        window.close();
                        main();
                    }
                }
            }
        }

        window.draw(menu);
        window.draw(guy);
        window.draw(text);             
        if(!guy.lock) {
            guy.animate(window, text, elapsed_frames%15); 
        }
        else
        {
            window.draw(button); 
            window.draw(text2); 
        }
        window.display();
    }
    return 0;
}
