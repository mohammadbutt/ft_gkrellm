/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NcursesDisplay.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiang- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:17:19 by jchiang-          #+#    #+#             */
/*   Updated: 2020/01/25 22:27:46 by jchiang-         ###   ########.fr       */
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
	getmaxyx(stdscr, _yMax, _xMax);
//	_win = newwin(0, 0, 0, 0);
///	box(_win, 0, 0);
//	refresh();
//	wrefresh(_win);
}
NcursesDisplay::NcursesDisplay(const NcursesDisplay & copy) { *this = copy; }
NcursesDisplay &NcursesDisplay::operator = (const NcursesDisplay & inputClass) {
	if (this == &inputClass)
		return *this;
	this->_win = inputClass._win;
	return *this;
}

NcursesDisplay::~NcursesDisplay(void) { endwin(); }

void NcursesDisplay::render(ManagerModule * mn) { 
	// do something
	while(true)
	{
		char mesg[]="Enter a string: ";
		mvprintw(_yMax/2,(_xMax-strlen(mesg))/2,"%s",mesg);
		if (wgetch(_win) == ESCAPE_KEY)
			break;
		(void)mn;
	//	mn->update();
	//	mn->allModuleInfo();
	//	cpuInfoDisplay(mn->cpuInfo);
		getch();
		//wrefresh(_win);
	}
}

void NcursesDisplay::cpuInfoDisplay(std::vector<std::string> & cpuInfo) {
	int i = 0;
	for (std::vector<std::string>::iterator it = cpuInfo.begin(); it != cpuInfo.end(); ++it) {
		//std::cout << *it << std::endl;
		mvprintw(_yMax + i , _xMax,"%s", (*it).c_str());
		i++;
	}
}
