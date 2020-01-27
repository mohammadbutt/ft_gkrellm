/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GraphicDisplay.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiang- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 15:37:48 by jchiang-          #+#    #+#             */
/*   Updated: 2020/01/26 22:24:42 by sko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src_include/GraphicDisplay.hpp"

GraphicDisplay::GraphicDisplay(void) {

	_font.loadFromFile("fonts/arial.ttf");

}

GraphicDisplay::GraphicDisplay(const GraphicDisplay & copy) { *this = copy; }
GraphicDisplay &GraphicDisplay::operator = (const GraphicDisplay & inputClass) {

	(void)inputClass;
	return *this;
}
GraphicDisplay::~GraphicDisplay(void) { }

void GraphicDisplay::render(ManagerModule * mn) {

	sf::RenderWindow window(sf::VideoMode(600, 1640), "SFML window");
	// Set Font
	sf::Font	font1;
	font1.loadFromFile("./fonts/lucon.ttf");

	sf::Texture	tt;
	tt.loadFromFile("./img/title.png");
	tt.setSmooth(true);
	// set title sprite
	sf::Sprite	s0;
	s0.setTexture(tt);

	sf::Texture	body;
	body.loadFromFile("./img/body.png");
	body.setSmooth(true);
	// set body sprite
	sf::Sprite	s1;
	s1.setTexture(body);

	sf::Texture	body1;
	body1.loadFromFile("./img/body1.png");
	body1.setSmooth(true);
	// set body1 sprite
	sf::Sprite	s2;
	s2.setTexture(body1);

	sf::Texture	body2;
	body2.loadFromFile("./img/body2.png");
	body2.setSmooth(true);
	// set body2 sprite
	sf::Sprite	s3;
	s3.setTexture(body2);

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
		s0.setPosition(0, 0);
		window.draw(s0);
		s1.setPosition(0, 60);
		window.draw(s1);
		for (std::vector<std::string>::iterator it = mn->tmInfo.begin(); it != mn->tmInfo.end(); ++it) {
			sf::Text	title;
			sf::Text	text;
			title.setString("Activity Monitor");
			title.setFont(_font);
			title.setCharacterSize(40);
			title.setFillColor(sf::Color::Black);
			title.setPosition(180, 5);
			if (it == mn->tmInfo.begin())
				continue;
			else {
				text.setString(*it + "\n");
				text.setFont(_font);
				text.setCharacterSize(25);
				text.setFillColor(sf::Color::Black);
				text.setPosition(40, 100 + i);
				i += 30;
			}
			window.draw(title);
			window.draw(text);
		}
		s0.setPosition(0, 200);
		window.draw(s0);
		s2.setPosition(0, 260);
		window.draw(s2);
		for (std::vector<std::string>::iterator it = mn->cpuInfo.begin(); it != mn->cpuInfo.end(); ++it) {
			sf::Text	title;
			sf::Text	text;
			title.setString("CPU Info");
			title.setFont(_font);
			title.setCharacterSize(40);
			title.setFillColor(sf::Color::Black);
			title.setPosition(210, 208);
			if (it == mn->cpuInfo.begin())
				continue;
			else {
				text.setString(*it + "\n");
				text.setFont(_font);
				text.setFillColor(sf::Color::Black);
				text.setCharacterSize(25);
				text.setPosition(40, 232 + i);
				i += 30;
			}
			window.draw(title);
			window.draw(text);
		}
		s0.setPosition(0, 480);
		window.draw(s0);
		s3.setPosition(0, 540);
		window.draw(s3);
		for (std::vector<std::string>::iterator it = mn->osInfo.begin(); it != mn->osInfo.end(); ++it) {
			sf::Text	title;
			sf::Text	text;
			title.setString("OS Info");
			title.setFont(_font);
			title.setCharacterSize(40);
			title.setFillColor(sf::Color::Black);
			title.setPosition(215, 485);
			if (it == mn->osInfo.begin())
				continue;
			else {
				text.setString(*it + "\n");
				text.setFont(_font);
				text.setFillColor(sf::Color::Black);
				text.setCharacterSize(25);
				text.setPosition(40, 365 + i);
				i += 30;
			}
			window.draw(title);
			window.draw(text);
		}
		s0.setPosition(0, 820);
		window.draw(s0);
		s1.setPosition(0, 880);
		window.draw(s1);
		for (std::vector<std::string>::iterator it = mn->nwInfo.begin(); it != mn->nwInfo.end(); ++it) {
			sf::Text	title;
			sf::Text	text;
			title.setString("Network Info");
			title.setFont(_font);
			title.setCharacterSize(40);
			title.setFillColor(sf::Color::Black);
			title.setPosition(195, 828);
			if (it == mn->nwInfo.begin())
				continue;
			else {
				text.setString(*it + "\n");
				text.setFont(_font);
				text.setFillColor(sf::Color::Black);
				text.setCharacterSize(25);
				text.setPosition(40, 500 + i);
				i += 30;
			}
			window.draw(title);
			window.draw(text);
		}
		s0.setPosition(0, 1020);
		window.draw(s0);
		s2.setPosition(0, 1080);
		window.draw(s2);
		for (std::vector<std::string>::iterator it = mn->rmInfo.begin(); it != mn->rmInfo.end(); ++it) {
			sf::Text	title;
			sf::Text	text;
			title.setString("RAM Info");
			title.setFont(_font);
			title.setCharacterSize(40);
			title.setFillColor(sf::Color::Black);
			title.setPosition(200, 1028);
			if (it == mn->rmInfo.begin())
				continue;
			else {
				text.setString(*it + "\n");
				text.setFont(_font);
				text.setFillColor(sf::Color::Black);
				text.setCharacterSize(25);
				text.setPosition(40, 635 + i);
				i += 30;
			}
			window.draw(title);
			window.draw(text);
		}
		s0.setPosition(0, 1300);
		window.draw(s0);
		s3.setPosition(0, 1360);
		window.draw(s3);
		for (std::vector<std::string>::iterator it = mn->ponyInfo.begin(); it != mn->ponyInfo.end(); ++it) {
			sf::Text	title;
			title.setString("Pony Info");
			title.setFont(_font);
			title.setCharacterSize(40);
			title.setFillColor(sf::Color::Black);
			title.setPosition(200, 1300);
			sf::Text text(*it + "\n", _font, 25);
			text.setFillColor(sf::Color::Black);
			text.setPosition(40, 735  + i);
			i += 30;
			window.draw(title);
			window.draw(text);
		}
		// Draw the sprite
//        window.draw(sprite);
		// Draw the string
		// Update the window
		window.display();
	}
}
