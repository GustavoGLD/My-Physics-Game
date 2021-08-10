#include <bits/stdc++.h>
#include <TGUI/TGUI.hpp>
#include "Main.hpp"
#include "GLD/GLD.hpp"

typedef std::chrono::high_resolution_clock::time_point pintao;

int main() {
    sf::RenderWindow window{{854, 480}, "TGUI window with SFML", sf::Style::Titlebar | sf::Style::Close };
    tgui::GuiSFML gui(window);

    std::vector<sf::Shape*> objList;
    GLD::Time time;

    phys::start(objList, gui, time);

    while (window.isOpen())
    {
        time.getFrameInit();
        sf::Event event;
        while (window.pollEvent(event))
        {
            gui.handleEvent(event);

            if (event.type == sf::Event::Closed)
                window.close();
        }

        phys::update(time);

        window.clear();
        for (auto obj : objList)
            window.draw(*obj);
        gui.draw();
        window.display();
    }

}