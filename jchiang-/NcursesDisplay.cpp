/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NcursesDisplay.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiang- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:17:19 by jchiang-          #+#    #+#             */
/*   Updated: 2020/01/25 16:10:19 by jchiang-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NcursesDisplay.hpp"

NcursesDisplay::NcursesDisplay(void) { 
	initscr();
	_dtimer = DateTimeModule();
}
NcursesDisplay::NcursesDisplay(const NcursesDisplay & copy) { *this = copy; }
NcursesDisplay &NcursesDisplay::operator = (const NcursesDisplay & inputClass) {
	if (this == &inputClass)
		return *this;
	this->_win = inputClass._win;
	return *this;
}

NcursesDisplay::~NcursesDisplay(void) { endwin(); }

void NcursesDisplay::render(void) { 
	// do something
	runTimer(DateTimeModule & _dtimer);
	
}

void runTimer(DateTimeModule *dtimer) 
{
//	char mesg[]="Just a string";		/* message to be appeared on the screen */
	int row,col;				/* to store the number of rows and *
	   				 * the number of colums of the screen */
	initscr();				/* start the curses mode */
	getmaxyx(stdscr,row,col);		/* get the number of rows and columns */

	char msg[10];
	sprintf(msg, "%d", dtimer->getCurrentYear());
	mvprintw(row/2, (col - strlen(msg)) / 2,"%s", msg);
	                               	/* print the message at the center of the screen */
	mvprintw(row-2,0,"This screen has %d rows and %d columns\n",row,col);
	printw("Try resizing your window(if possible) and then run this program again");
	refresh();
	getch();
}
