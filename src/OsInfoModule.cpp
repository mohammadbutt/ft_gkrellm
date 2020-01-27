/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OsInfoModule.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:05:42 by mbutt             #+#    #+#             */
/*   Updated: 2020/01/26 16:51:10 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OsInfoModule.hpp"

OsInfoModule::OsInfoModule(void)
{
	uname(&_info);
}


OsInfoModule::~OsInfoModule(void)
{
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

std::string OsInfoModule::getDarwinReleaseVersion(void)
{
	return(_info.release);
}

std::string OsInfoModule::getVersionDate(void)
{
	std::string fullString = _info.version;
	std::string newString = fullString.substr(30, 28);
	return(newString);
}

std::string OsInfoModule::getMachine(void)
{
	return(_info.machine);
}

std::string OsInfoModule::getCpuInfo(void)
{
	char cpuInfo[64];
	size_t size = sizeof(cpuInfo);
	if(sysctlbyname("machdep.cpu.brand_string", &cpuInfo, &size, NULL, 0) < 0)
	{
		perror("sysctl");
	}
	return(cpuInfo);
}

void OsInfoModule::update(void)
{

}

std::vector<std::string> OsInfoModule::getInfo(void)
{
	std::vector<std::string> vectorString;
	vectorString.push_back("User Name: " + getUserName());
	vectorString.push_back("System Name: " + getSysName());
	vectorString.push_back("Computer Name: " + getNodeName());
	vectorString.push_back("Darwin Version: " + getDarwinReleaseVersion());
	vectorString.push_back("Version Date: " + getVersionDate());
	vectorString.push_back("Machine: " + getMachine());
	vectorString.push_back("Mac Os Name: " + getMacOs());
	return(vectorString);
}

std::string OsInfoModule::getMacOs(void)
{
	std::string macOsVersion;
	int darwinReleaseVersionNumber = atoi(_info.release);
	const char *macOsName[] = {	"X", "X", "X", "Beta: Kodia", "Cheetah", "Puma",
								"Jaguar", "Panther", "Tiger", "Leopard",
								"Snow Leopard", "Lion", "Mountain Lion",
								"Mavericks", "Yosemite", "El Capitan", "Sierra",
								"High Sierra", "Mojave", "Catalina"};
	macOsVersion = macOsName[darwinReleaseVersionNumber];
	return(macOsVersion);
}
