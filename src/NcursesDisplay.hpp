/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NcursesDisplay.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiang- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:02:33 by jchiang-          #+#    #+#             */
/*   Updated: 2020/01/25 22:18:46 by jchiang-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NCURSESDISPLAY_HPP
# define NCURSESDISPLAY_HPP

#include "IMonitorDisplay.hpp"
#include "ManagerModule.hpp"

#include <vector>
#include <ncurses.h>
#include <string.h>

# define ESCAPE_KEY 27

//class DateTimeModule;

class NcursesDisplay : public IMonitorDisplay
{
	private:
		int _xMax;
		int _yMax;
		WINDOW *_win;
//		DateTimeModule _dtimer;
	
	public:
		NcursesDisplay(void);
		NcursesDisplay(const NcursesDisplay & copy);
		NcursesDisplay &operator = (const NcursesDisplay & inputClass);
		~NcursesDisplay(void);

		void render(ManagerModule * mn);
		void cpuInfoDisplay(std::vector<std::string> & cpuInfo);
};

// Testing
//void runTimer(DateTimeModule *dtimer);

#endif
