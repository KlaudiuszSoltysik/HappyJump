#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include "bee.h"
#include "guy.h"
#include "platform.h"
#include "platform2.h"
#include "platform3.h"

Guy::Guy(sf::Texture &texture, sf::RenderWindow &window) : sf::Sprite(texture) {
    setScale((100/texture.getSize().x), (140/texture.getSize().y));
    setPosition((window.getSize().x-100)/2, window.getSize().y-140);

    grass_texture.loadFromFile("grass.png");
    grass_texture.setRepeated(true);
    brick_texture.loadFromFile("brick.png");
    brick_texture.setRepeated(true);
    cloud_texture.loadFromFile("cloud.png");
    cloud_texture.setRepeated(true);

    new_map(window);
}

void Guy::animate(sf::RenderWindow &window, sf::Text &text, int elapsed_frames) {
    sf::FloatRect bounds=getGlobalBounds();

    if(left==1) {
        move(-s, 0);
    }
    if(right==1) {
        move(s, 0);
    }
    if(left && bounds.left+bounds.width<0) {
        setPosition(window.getSize().x, bounds.top);
    }
    if(right && bounds.left>window.getSize().x) {
        setPosition(-bounds.width, bounds.top);
    }

    vector<sf::Vector2f> platform_bounds;
    vector<sf::Vector2f> bee_bounds;

    for(auto &i:platforms) {
        platform_bounds.emplace_back(i->getPosition());
        i->move();
    }
    for(auto &i:bees) {
        bee_bounds.emplace_back(i->getPosition());
        i->move();
        if(elapsed_frames==0) {
            i->flip();
        }
    }
    if(sy>2) {
        sy-=sy/g;
        move(0, -sy);
        sy2=1;
    }
    else {
        int it=0;
        for(auto &i:platform_bounds) {
            if(bounds.top+bounds.height>i.y && bounds.top+bounds.height-10<i.y && bounds.left+bounds.width>i.x && bounds.left+bounds.width<i.x+platform_x*1.25) {
                platforms[it]->bump();
                sy=45;
                sy2=0;
                break;
            }
            it++;
        }
        if(sy2<5) {
            sy2+=1.000001*sy2;
        }
        move(0, sy2);
    }

    if(bounds.top+bounds.height>0) {
        for(auto &i:platforms) {
            window.draw(*i);
        }
        for(auto &i:bees) {
            window.draw(*i);
        }
    }
    else {
        sy=60;
        int old_x=bounds.left;
        setPosition(old_x, window.getSize().y);
        new_map(window);
    }

    for(auto &i:bee_bounds) {
        if(bounds.top>window.getSize().y || (bounds.top+bounds.height>i.y && bounds.top<i.y+70 && bounds.left+bounds.width>i.x && bounds.left<i.x+50)) {
            std::stringstream p;
            p << points;
            text.setString("Wynik: "+p.str());
            lock=1;
            break;
        }
    }
}

void Guy::new_map(sf::RenderWindow &window) {
    int H=0;            
    int dice;          
    int ran=rand()%2+1; 

    platforms.clear();
    bees.clear();
    points++; 

    for(int i=0; i<ran; i++) {
        bees.emplace_back(make_unique<Bee>(window));
    }
    for(int i=0; i<3; i++) {
        dice=rand()%3;
        H+=4.5*platform_y;
        if(dice==0) {
            platforms.emplace_back(make_unique<Platform>(grass_texture, window, H));
        }
        else if(dice==1) {
            platforms.emplace_back(make_unique<Platform2>(brick_texture, window, H));
        }
        else {
            platforms.emplace_back(make_unique<Platform3>(cloud_texture, window, H));
        }
    }
}
