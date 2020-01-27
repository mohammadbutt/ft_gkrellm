/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ManagerModule.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 16:47:39 by mbutt             #+#    #+#             */
/*   Updated: 2020/01/26 21:26:52 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src_include/ManagerModule.hpp"


ManagerModule::ManagerModule(void)
{
	setUpdateTopInfo();
	_networkMode = NetworkModule();
	_cpuModule = CPUModule();
	_osModule = OsInfoModule();
	_tmModule = DateTimeModule();
	_ramModule = RamModule();
	_ponyModule = PonyModule();
	return;
}

ManagerModule::~ManagerModule(void)
{
	return;
}

/* ---------------------------------------------------------------------------- */
/* ----------------------     Module Section   -------------------------------- */
/* ---------------------------------------------------------------------------- */

void 		ManagerModule::update(void)
{
	setUpdateTopInfo();
	_cpuModule.update();
	_tmModule.update();
	_networkMode.setInfo(_topInfo);
	_ramModule.setInfo(_topInfo);
}

void ManagerModule::setUpdateTopInfo(void)
{
	int i = 0;
	system("top -l1 | head -10 > /tmp/topGrepFile.txt");	
	std::ifstream file("/tmp/topGrepFile.txt");

	std::string tmp;
	_topInfo.clear();
	if(file.is_open() == false)
		while(i < 10)
			_topInfo[i++] = "0";
	else {
		while(i < 10) {
			std::getline(file, tmp);
			_topInfo.push_back(tmp);
			i++;
		}
		file.close();
	}
}

/* ---------------------------------------------------------------------------- */
/* ---------------------     Display Section    ------------------------------- */
/* ---------------------------------------------------------------------------- */

void ManagerModule::allModuleInfo(void)
{
	cpuInfo = _cpuModule.getInfo();
	osInfo = _osModule.getInfo();
	tmInfo = _tmModule.getInfo();
	nwInfo = _networkMode.getInfo();
	rmInfo = _ramModule.getInfo();
	ponyInfo = _ponyModule.getInfo();
}	
