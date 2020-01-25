/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OsInfoModule.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:05:42 by mbutt             #+#    #+#             */
/*   Updated: 2020/01/24 20:46:30 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OsInfoModule.hpp"

OsInfoModule::OsInfoModule(void)
{
	// default constructor;
	std::cout << "Calling constructor" << std::endl;
	uname(&_info);
	//	getSystemInfo();
}


OsInfoModule::~OsInfoModule(void)
{
	//defualt destructor;
	std::cout << "Calling destructor" << std::endl;
}

std::string OsInfoModule::getUserName(void)
{
	return(getenv("USER"));
}

std::string OsInfoModule::getSysName(void)
{
	return(_info.sysname);
}

std::string OsInfoModule::getNodeName(void)
{
	return(_info.nodename);
}

std::string OsInfoModule::getReleaseVersion(void)
{
	return(_info.release);
}

std::string OsInfoModule::getVersionDate(void)
{
	std::string fullString = _info.version;
	std::string newString = fullString.substr(30, 28);
	
//	return(_info.version);
	return(newString);
}

std::string OsInfoModule::getMachine(void)
{
	return(_info.machine);
}

int main(void)
{
	OsInfoModule info;
//	info.getSystemInfo();

	std::cout << "username: " << info.getUserName() << std::endl;
	std::cout << "sysName: " << info.getSysName() << std::endl;

	std::cout << "nodeName: " << info.getNodeName() << std::endl;
	std::cout << "release version: " << info.getReleaseVersion() << std::endl;
	std::cout << "version: " << info.getVersionDate() << std::endl;
	std::cout << "Machine: " << info.getMachine() << std::endl;
}

