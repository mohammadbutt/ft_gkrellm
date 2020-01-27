/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GraphicDisplay.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiang- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 15:37:48 by jchiang-          #+#    #+#             */
/*   Updated: 2020/01/26 16:55:04 by jchiang-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GraphicDisplay.hpp"

GraphicDisplay::GraphicDisplay(void) {

    _font.loadFromFile("../fonts/arial.ttf");

}

GraphicDisplay::GraphicDisplay(const GraphicDisplay & copy) { *this = copy; }
GraphicDisplay &GraphicDisplay::operator = (const GraphicDisplay & inputClass) {

	(void)inputClass;
	return *this;
}
GraphicDisplay::~GraphicDisplay(void) { }

void GraphicDisplay::render(ManagerModule * mn) {
	
    sf::RenderWindow window(sf::VideoMode(1000, 800), "SFML window");
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
		int i = 0;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
		mn->update();
		mn->allModuleInfo();
        // Clear screen
        window.clear();
		for (std::vector<std::string>::iterator it = mn->tmInfo.begin(); it != mn->tmInfo.end(); ++it) {
    		sf::Text text(*it + "\n", _font, 25);
			text.setPosition(20, 20 + i);
			i += 30;
      	 	window.draw(text);
		}
		for (std::vector<std::string>::iterator it = mn->cpuInfo.begin(); it != mn->cpuInfo.end(); ++it) {
    		sf::Text text(*it + "\n", _font, 25);
			text.setPosition(20, 20 + i);
			i += 30;
      	 	window.draw(text);
		}
		for (std::vector<std::string>::iterator it = mn->osInfo.begin(); it != mn->osInfo.end(); ++it) {
    		sf::Text text(*it + "\n", _font, 25);
			text.setPosition(20, 20 + i);
			i += 30;
      	 	window.draw(text);
		}
		for (std::vector<std::string>::iterator it = mn->nwInfo.begin(); it != mn->nwInfo.end(); ++it) {
    		sf::Text text(*it + "\n", _font, 25);
			text.setPosition(20, 20 + i);
			i += 30;
      	 	window.draw(text);
		}
		for (std::vector<std::string>::iterator it = mn->rmInfo.begin(); it != mn->rmInfo.end(); ++it) {
    		sf::Text text(*it + "\n", _font, 25);
			text.setPosition(20, 20 + i);
			i += 30;
      	 	window.draw(text);
		}
        // Draw the sprite
//        window.draw(sprite);
        // Draw the string
        // Update the window
        window.display();
    }
}
