/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ManagerModule.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 16:47:39 by mbutt             #+#    #+#             */
/*   Updated: 2020/01/25 22:26:03 by jchiang-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ManagerModule.hpp"


ManagerModule::ManagerModule(void)
{
	std::cout << "ManagerModule constructor" << std::endl;
	setUpdateTopInfo();

	_networkMode = NetworkModule();
	_cpuModule = CPUModule();
	//	_ncursesDisplay = NcursesDisplay();
	return;
}

ManagerModule::~ManagerModule(void)
{
	std::cout << "ManagerModule desctructor" << std::endl;
	return;
}


/* ---------------------------------------------------------------------------- */
/* ----------------------     Module Section   -------------------------------- */
/* ---------------------------------------------------------------------------- */

void ManagerModule::setUpdateTopInfo(void)
{
	int i = 0;
	system("top -l1 | head -10 > /tmp/topGrepFile.txt");	
	std::ifstream file("/tmp/topGrepFile.txt");
	if(file.is_open() == false)
		while(i < 10)
			topInfo[i++] = "0";
	else
		while(i < 10)
			std::getline(file, topInfo[i++]);
//	return;
}

void 		ManagerModule::update(void)
{
//	std::cout << "Manager Update" << std::endl;
//	setUpdateTopInfo();
//	_networkMode.getNetworkPacketIn(topInfo[8]);
	_cpuModule.update();
}
std::string  ManagerModule::getterForNetworkModuleIn(void)
{
//	std::cout << "Printing top info:" << std::endl << std::endl;
	std::cout << topInfo[8] << std::endl;
	return(_networkMode.getNetworkPacketIn(topInfo[8]));
//	std::cout << std::endl;
}

std::string  ManagerModule::getterForNetworkModuleOut(void)
{
//	std::cout << "Printing top info:" << std::endl << std::endl;
	std::cout << topInfo[8] << std::endl;
	return(_networkMode.getNetworkPacketOut(topInfo[8]));
//	std::cout << std::endl;
}

std::string ManagerModule::getTopInfo(int index)
{
//	_setTopInfo();
	
	return(topInfo[index]);
}

/* ---------------------------------------------------------------------------- */
/* ---------------------     Display Section    ------------------------------- */
/* ---------------------------------------------------------------------------- */

void ManagerModule::allModuleInfo(void)
{
	cpuInfo = _cpuModule.getInfo();
}


	
