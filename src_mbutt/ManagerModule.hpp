/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ManagerModule.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 16:38:02 by mbutt             #+#    #+#             */
/*   Updated: 2020/01/25 22:00:44 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANAGERMODULE_HPP
# define MANAGERMODULE_HPP

#include "NetworkModule.hpp"
#include "OsInfoModule.hpp"
#include <vector>
//#include "NcursesDisplay.hpp"
//#include "RamModule.hpp"

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

class ManagerModule 
{
	public:
//		RamModule		ramModule;
		
		ManagerModule(void);
		~ManagerModule(void);
		
		/* ------------------------------------ */
		/* ------------- Module Section ------- */
		/* ------------------------------------ */
		std::string getTopInfo(int index);
		std::string topInfo[10];
		void setUpdateTopInfo(void);
//		std::string getterForNetworkModuleIn(void);
//		std::string getterForNetworkModuleOut(void);

		void update(void);
		
		/* ------------------------------------ */
		/* ------------ Display Section ------- */
		/* ------------------------------------ */
	//	void render(void);
	private:
		NetworkModule _networkMode;
		OsInfoModule _osInfoMode;
//		NcursesDisplay _ncursesDisplay;
};

# endif
