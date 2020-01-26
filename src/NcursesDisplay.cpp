/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NcursesDisplay.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiang- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:17:19 by jchiang-          #+#    #+#             */
/*   Updated: 2020/01/26 10:09:47 by jchiang-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NcursesDisplay.hpp"

NcursesDisplay::NcursesDisplay(void) { 

	initscr();
	raw();
	noecho();
	cbreak();
	curs_set(0);
	nodelay(stdscr, true);
	keypad(stdscr, TRUE);
	getmaxyx(stdscr, _ptMax.y, _ptMax.x);
	box(stdscr, 0, 0);
	refresh();
}
NcursesDisplay::NcursesDisplay(const NcursesDisplay & copy) { *this = copy; }
NcursesDisplay &NcursesDisplay::operator = (const NcursesDisplay & inputClass) {
	if (this == &inputClass)
		return *this;
	this->_win = inputClass._win;
	return *this;
}

NcursesDisplay::~NcursesDisplay(void) {
	endwin(); 
}

static bool waitForOneSec(std::chrono::high_resolution_clock::time_point t1) {
	return (
			std::chrono::duration<double>(
				std::chrono::high_resolution_clock::now() - t1
			).count() > 1.0
	);
}

void NcursesDisplay::render(ManagerModule * mn) { 
	// do something
	std::chrono::high_resolution_clock::time_point t1;
	while(true)
	{
		t1 = std::chrono::high_resolution_clock::now();
		if (wgetch(stdscr) == ESCAPE_KEY)
			break;
		mn->update();
		mn->allModuleInfo();
		cpuInfoDisplay(mn->cpuInfo);
		refresh();
		while (!waitForOneSec(t1));
	}
}

void NcursesDisplay::cpuInfoDisplay(std::vector<std::string> & cpuInfo) {
	int i = 0;

	for (std::vector<std::string>::iterator it = cpuInfo.begin(); it != cpuInfo.end(); ++it) {
		if (i == 3)
			mvprintw(CPUPOSITION_Y + i , CPUPOSITION_X,"%s", CLERA_LINE);	
		mvprintw(CPUPOSITION_Y + i , CPUPOSITION_X,"%s", (*it).c_str());	
		i++;
	}
	mvprintw(CPUPOSITION_Y + i , CPUPOSITION_X,"%s", SEPERATE_LINE);	
}
