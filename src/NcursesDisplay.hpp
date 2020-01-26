/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NcursesDisplay.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiang- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:02:33 by jchiang-          #+#    #+#             */
/*   Updated: 2020/01/26 11:02:53 by jchiang-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NCURSESDISPLAY_HPP
# define NCURSESDISPLAY_HPP

#include "ft_gkrellm.hpp"
#include "IMonitorDisplay.hpp"
#include "ManagerModule.hpp"

#include <ncurses.h>

class NcursesDisplay : public IMonitorDisplay
{
	private:
		t_point _ptMax;
		WINDOW *_win;
	
	public:
		NcursesDisplay(void);
		NcursesDisplay(const NcursesDisplay & copy);
		NcursesDisplay &operator = (const NcursesDisplay & inputClass);
		~NcursesDisplay(void);

		void render(ManagerModule * mn);
		void timeInfoDisplay(std::vector<std::string> & timeInfo);
		void cpuInfoDisplay(std::vector<std::string> & cpuInfo);
		void osInfoDisplay(std::vector<std::string> & osInfo);
};


#endif
