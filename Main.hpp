#pragma once

#include <bits/stdc++.h>
#include <TGUI/TGUI.hpp>
#include "Ball.hpp"
#include "GLD/GLD.hpp"

namespace phys
{

phys::Ball ball;
bool buttonIsPressed;
void start(std::vector<sf::Shape*>& objList, tgui::GuiBase& gui, GLD::Time time)  {
    ball.start(objList);

    auto button = tgui::Button::create("Start!");
    button->setSize({"20%", "10%"});
    button->setPosition({"70%", "10%"});
    button->setTextSize(30);
    gui.add(button);

    button->onPress([&]{
        buttonIsPressed = true;
    });
}

void update(GLD::Time time){
    
    if (buttonIsPressed)
        ball.update(time);
}

}

