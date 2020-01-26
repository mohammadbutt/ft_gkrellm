/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NcursesDisplay.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiang- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:17:19 by jchiang-          #+#    #+#             */
/*   Updated: 2020/01/26 12:02:40 by jchiang-         ###   ########.fr       */
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
		timeInfoDisplay(mn->tmInfo);
		cpuInfoDisplay(mn->cpuInfo);
		osInfoDisplay(mn->osInfo);
		networkInfoDisplay(mn->nwInfo);
		refresh();
		while (!waitForOneSec(t1));
	}
}

void NcursesDisplay::timeInfoDisplay(std::vector<std::string> & timeInfo) {
	int i = 0;
	for (std::vector<std::string>::iterator it = timeInfo.begin(); it != timeInfo.end(); ++it) {
		if (i == 1)
			mvprintw(TMPOSITION_Y + i , TMPOSITION_X,"%s", CLERA_LINE);	
		mvprintw(TMPOSITION_Y + i, TMPOSITION_X,"%s", (*it).c_str());
		i++;
	}
	mvprintw(TMPOSITION_Y + i , TMPOSITION_X,"%s", SEPERATE_LINE);	
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

void NcursesDisplay::osInfoDisplay(std::vector<std::string> & osInfo) {
	int i = 0;

	for (std::vector<std::string>::iterator it = osInfo.begin(); it != osInfo.end(); ++it) {
		mvprintw(OSPOSITION_Y + i , OSPOSITION_X,"%s", (*it).c_str());	
		i++;
	}
	mvprintw(OSPOSITION_Y + i , OSPOSITION_X,"%s", SEPERATE_LINE);	
}

void NcursesDisplay::networkInfoDisplay(std::vector<std::string> &nwInfo) {
	int i = 0;
	for (std::vector<std::string>::iterator it = nwInfo.begin(); it != nwInfo.end(); ++it) {
		mvprintw(NWPOSITION_Y + i , NWPOSITION_X,"%s", CLERA_LINE);	
		mvprintw(NWPOSITION_Y + i, NWPOSITION_X,"%s", (*it).c_str());
		i++;
	}
	mvprintw(NWPOSITION_Y + i , NWPOSITION_X,"%s", SEPERATE_LINE);	
}
