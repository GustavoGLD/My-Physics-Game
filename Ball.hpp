#pragma once

#include <bits/stdc++.h>
#include <TGUI/TGUI.hpp>
#include "GLD/GLD.hpp"

namespace phys
{

class Ball {
private:
    sf::CircleShape* ball;
    sf::Texture* texture;

    sf::Vector2f   veloc = {0.0f, 0.0f};
    sf::Vector2f gravity = {0.0f, 1000.0f};
    float elasticity = 0.75;

public:
    void start(std::vector<sf::Shape*>& objList){
        
        ball = new sf::CircleShape(25);
        ball->setOrigin(ball->getRadius(), ball->getRadius());
        ball->move({427.0f, 10.0f});
        ball->setFillColor(sf::Color::Green);

        texture = new sf::Texture();
        texture->loadFromFile("basketball.png");
        ball->setTexture(texture);

        objList.push_back(ball);
    }

    void update(GLD::Time time){
        //sf::CircleShape new_pos = sf::CircleShape(*ball);
        sf::Vector2f dSpace, new_pos;

        //  v = v0 + a * dt 
        veloc += gravity * (float)time.getDeltaTime();

        // dS = v * dt
        dSpace = veloc * (float)time.getDeltaTime();

        new_pos = ball->getPosition() + dSpace;

        if (480 - new_pos.y <= ball->getRadius()){

            veloc *= -elasticity;
            dSpace = veloc * (float)time.getDeltaTime();
            ball->move(dSpace);
            return;
        }

        ball->move(dSpace);

    }
};

}
