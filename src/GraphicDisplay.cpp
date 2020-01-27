/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GraphicDisplay.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiang- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 15:37:48 by jchiang-          #+#    #+#             */
/*   Updated: 2020/01/26 16:37:11 by jchiang-         ###   ########.fr       */
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



int TestWindow(void) {
    sf::RenderWindow window(sf::VideoMode(800, 600), "ft_gkrellm");
    sf::Font font;
    if (!font.loadFromFile("../fonts/arial.ttf"))
        return EXIT_FAILURE;
    sf::Text text("Hello SFML", font, 50);
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // Clear screen
        window.clear();
        // Draw the sprite
//        window.draw(sprite);
        // Draw the string
        window.draw(text);
        // Update the window
        window.display();
    }
    return EXIT_SUCCESS;
}

void GraphicDisplay::render(ManagerModule * mn) {
	
    sf::RenderWindow window(sf::VideoMode(800, 1600), "SFML window");
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
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
      	 	window.draw(text);
		}
        // Draw the sprite
//        window.draw(sprite);
        // Draw the string
        // Update the window
        window.display();
    }
	//TestWindow();
}
