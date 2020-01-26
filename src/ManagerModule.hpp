/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ManagerModule.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 16:38:02 by mbutt             #+#    #+#             */
/*   Updated: 2020/01/26 12:38:54 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANAGERMODULE_HPP
# define MANAGERMODULE_HPP

#include "DateTimeModule.hpp"
#include "OsInfoModule.hpp"
#include "NetworkModule.hpp"
#include "CPUModule.hpp"
#include "RamModule.hpp" // Added by mbutt

#include <vector>
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
//		std::string getTopInfo(int index);				Not needed
//		std::string topInfo[10];						Not needed
		void setUpdateTopInfo(void);
//		std::string getterForNetworkModuleIn(void);		Not needed
//		std::string getterForNetworkModuleOut(void);	Not needed

		void update(void);
		
		/* ------------------------------------ */
		/* ------------ Display Section ------- */
		/* ------------------------------------ */
		std::vector<std::string> cpuInfo;
		std::vector<std::string> osInfo;
		std::vector<std::string> tmInfo;
		std::vector<std::string> nwInfo;
		std::vector<std::string> rmInfo; 	// Added by mbutt
		void allModuleInfo(void);
	private:
		std::vector<std::string>	_topInfo;
		NetworkModule				_networkMode;
		CPUModule					_cpuModule;
		OsInfoModule				_osModule;
		DateTimeModule				_tmModule;
		RamModule					_ramModule; // Added by mbutt
};

# endif
