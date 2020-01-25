/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OsInfoModule.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:05:42 by mbutt             #+#    #+#             */
/*   Updated: 2020/01/24 21:47:06 by mbutt            ###   ########.fr       */
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
//	std::cout << "cores: " << std::thread::hardware_concurrency() << std::endl;
	return(cpuInfo);
}

unsigned int OsInfoModule::getCpuCores(void)
{
	unsigned int numberOfCores;

	numberOfCores = std::thread::hardware_concurrency();
	return(numberOfCores);
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
	std::cout << "CPU: " << info.getCpuInfo() << std::endl;
	std::cout << "Cores: " << info.getCpuCores() << std::endl;

	    int mib[2];
    int64_t physical_memory;
    size_t length;

    // Get the Physical memory size
    mib[0] = CTL_HW;
    mib[1] = HW_MEMSIZE;
    length = sizeof(int64_t);
   
	std::cout << "mib[0]: " << mib[0] << std::endl;
	std::cout << "mib[1]: " << mib[1] << std::endl;
   	sysctl(mib, 2, &physical_memory, &length, NULL, 0);
	std::cout << "mib[0]: " << mib[0] << std::endl;
	std::cout << "mib[1]: " << mib[1] << std::endl;
	std::cout << "physical_memory: " << physical_memory << std::endl;
	std::cout << "length: " << length << std::endl;
}

