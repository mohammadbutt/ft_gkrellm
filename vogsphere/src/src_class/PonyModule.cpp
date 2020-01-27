/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PonyModule.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiang- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 17:35:10 by jchiang-          #+#    #+#             */
/*   Updated: 2020/01/26 21:26:13 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src_include/PonyModule.hpp"

PonyModule::PonyModule(void) { }
PonyModule::PonyModule(const PonyModule &copy) { *this = copy; }
PonyModule &PonyModule::operator = (const PonyModule & ) { return *this; }
PonyModule::~PonyModule(void) { }

void PonyModule::update(void) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> uid(0, 1000);
	int color = uid(gen) % 7;
	_color = std::to_string(color);
}

std::vector<std::string> PonyModule::getInfo(void) {

	std::vector<std::string> ponyInfo;
	ponyInfo.push_back(_color);
	ponyInfo.push_back("Art by Veronica Karlsson");
	ponyInfo.push_back("            .'' ");   
	ponyInfo.push_back("  ._.-.___.' (`\\ ");  
	ponyInfo.push_back(" //(        ( `'");   
	ponyInfo.push_back("'/ )\\ ).__. )   "); 
	ponyInfo.push_back("' <' `\\ ._/'\\   ");   
	ponyInfo.push_back("   `   \\     \\  ");
	return ponyInfo;
}
