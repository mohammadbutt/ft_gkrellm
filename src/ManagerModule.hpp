/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ManagerModule.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 16:38:02 by mbutt             #+#    #+#             */
/*   Updated: 2020/01/26 11:34:40 by jchiang-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANAGERMODULE_HPP
# define MANAGERMODULE_HPP

#include "DateTimeModule.hpp"
#include "OsInfoModule.hpp"
#include "NetworkModule.hpp"
#include "CPUModule.hpp"
//#include "RamModule.hpp"

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
		std::string getTopInfo(int index);
		std::string topInfo[10];
		void setUpdateTopInfo(void);
		std::string getterForNetworkModuleIn(void);
		std::string getterForNetworkModuleOut(void);

		void update(void);
		
		/* ------------------------------------ */
		/* ------------ Display Section ------- */
		/* ------------------------------------ */
		std::vector<std::string> cpuInfo;
		std::vector<std::string> osInfo;
		std::vector<std::string> tmInfo;
		std::vector<std::string> nwInfo;
		void allModuleInfo(void);
	private:
		std::vector<std::string> _topInfo;
		NetworkModule _networkMode;
		CPUModule _cpuModule;
		OsInfoModule _osModule;
		DateTimeModule _tmModule;
};

# endif
