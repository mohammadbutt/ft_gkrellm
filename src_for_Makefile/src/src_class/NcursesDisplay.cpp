/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NcursesDisplay.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiang- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:17:19 by jchiang-          #+#    #+#             */
/*   Updated: 2020/01/26 21:24:47 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src_include/NcursesDisplay.hpp"

NcursesDisplay::NcursesDisplay(void) { 

	initscr();
	if(has_colors() == FALSE)
	{	endwin();
		printf("Your terminal does not support color\n");
		exit(1);
	}
	start_color();
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
		ramInfoDisplay(mn->rmInfo);
		ponyInfoDisplay(mn->ponyInfo);
		refresh();
		while (!waitForOneSec(t1));
	}
}
void NcursesDisplay::timeInfoDisplay(std::vector<std::string> & timeInfo) {
	int i = 0;
	for (std::vector<std::string>::iterator it = timeInfo.begin(); it != timeInfo.end(); ++it) {
		if (i == 2)
			mvprintw(TMPOSITION_Y + i , TMPOSITION_X,"%s", CLERA_LINE);
		if(i == 0)
			mvprintw(TMPOSITION_Y + i , _ptMax.x / 3,"%s", (*it).c_str());
		else
			mvprintw(TMPOSITION_Y + i, TMPOSITION_X,"%s", (*it).c_str());
		i++;
	}
	mvprintw(TMPOSITION_Y + i , TMPOSITION_X,"%s", SEPERATE_LINE);	
}

void NcursesDisplay::cpuInfoDisplay(std::vector<std::string> & cpuInfo) {
	int i = 0;

	for (std::vector<std::string>::iterator it = cpuInfo.begin(); it != cpuInfo.end(); ++it) {
		if (i == 4)
			mvprintw(CPUPOSITION_Y + i , CPUPOSITION_X,"%s", CLERA_LINE);
		if(i == 0)
			mvprintw(CPUPOSITION_Y + i , _ptMax.x / 3,"%s", (*it).c_str());
		else
			mvprintw(CPUPOSITION_Y + i , CPUPOSITION_X,"%s", (*it).c_str());	
		i++;
	}
	mvprintw(CPUPOSITION_Y + i , CPUPOSITION_X,"%s", SEPERATE_LINE);	
}

void NcursesDisplay::osInfoDisplay(std::vector<std::string> & osInfo) {
	int i = 0;

	for (std::vector<std::string>::iterator it = osInfo.begin(); it != osInfo.end(); ++it) {
		if(i == 0)
			mvprintw(OSPOSITION_Y + i , _ptMax.x / 3,"%s", (*it).c_str());	
		else
			mvprintw(OSPOSITION_Y + i , OSPOSITION_X,"%s", (*it).c_str());	
		i++;
	}
	mvprintw(OSPOSITION_Y + i , OSPOSITION_X,"%s", SEPERATE_LINE);	
}

void NcursesDisplay::networkInfoDisplay(std::vector<std::string> &nwInfo) {
	int i = 0;
	for (std::vector<std::string>::iterator it = nwInfo.begin(); it != nwInfo.end(); ++it) {
		mvprintw(NWPOSITION_Y + i , NWPOSITION_X,"%s", CLERA_LINE);
		if(i == 0)
			mvprintw(NWPOSITION_Y + i, _ptMax.x / 3,"%s", (*it).c_str());
		else
			mvprintw(NWPOSITION_Y + i, NWPOSITION_X,"%s", (*it).c_str());
		i++;
	}
	mvprintw(NWPOSITION_Y + i , NWPOSITION_X,"%s", SEPERATE_LINE);	
}

void NcursesDisplay::ramInfoDisplay(std::vector<std::string> &ramInfo)
{
	int i = 0;
	while(i < static_cast<int>(ramInfo.size()))
	{
		mvprintw(RMPOSITION_Y + i, RMPOSITION_X,"%s", CLERA_LINE);		
		if(i == 0)
			mvprintw(RMPOSITION_Y + i, _ptMax.x / 3, "%s", ramInfo[i].c_str());
		else
			mvprintw(RMPOSITION_Y + i, RMPOSITION_X, "%s", ramInfo[i].c_str());
		i++;
	}
	mvprintw(RMPOSITION_Y + i, RMPOSITION_X, "%s", SEPERATE_LINE);
}

static short cursColor(int fg)
{
    switch (7 & fg) {
    case 0:
        return (COLOR_WHITE);
    case 1:
        return (COLOR_BLUE);
    case 2:
        return (COLOR_GREEN);
    case 3:
        return (COLOR_CYAN);
    case 4:
        return (COLOR_RED);
    case 5:
        return (COLOR_MAGENTA);
    case 6:
        return (COLOR_YELLOW);
    case 7:
        return (COLOR_WHITE);
	}
	return (COLOR_WHITE);
}

static int randomNumber(void) {
	
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> uid(0, 1000);
	int color = uid(gen) % 7;
	return color;
}

void NcursesDisplay::ponyInfoDisplay(std::vector<std::string> &ponyInfo)
{
	int i = 0;
	init_pair(1, cursColor(randomNumber()), COLOR_BLACK);
	attron(COLOR_PAIR(1));
	for (std::vector<std::string>::iterator it = ponyInfo.begin(); it != ponyInfo.end(); ++it) {
		mvprintw(PONYPOSITION_Y + i , PONYPOSITION_X,"%s", CLERA_LINE);	
		mvprintw(PONYPOSITION_Y + i, PONYPOSITION_X,"%s", (*it).c_str());
		i++;
	}
	mvprintw(PONYPOSITION_Y + i , PONYPOSITION_X,"%s", SEPERATE_LINE);
	attroff(COLOR_PAIR(1));
}
