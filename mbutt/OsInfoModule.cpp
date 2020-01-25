/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OsInfoModule.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:05:42 by mbutt             #+#    #+#             */
/*   Updated: 2020/01/25 14:36:23 by mbutt            ###   ########.fr       */
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


std::string OsInfoModule::getMacOs(void)
{
	std::string macOsVersion;
	int darwinReleaseVersionNumber = atoi(_info.release);
	const char *macOsName[] = {"X", "X", "X", "Beta: Kodia", "Cheetah", "Puma",
							"Jaguar", "Panther", "Tiger", "Leopard", "Snow Leopard",
							"Lion", "Mountain Lion", "Mavericks", "Yosemite",
							"El Capitan", "Sierra", "High Sierra", "Mojave", "Catalina"};
	macOsVersion = macOsName[darwinReleaseVersionNumber];

/*
	if(darwinReleaseVersionNumber == 19)
		macOsVersion = "Catalina";
	else if(darwinReleaseVersionNumber == 18)
		macOsVersion = "Mojave";
	else if(darwinReleaseVersionNumber == 17)
		macOsVersion = "High Sierra";
	else if(darwinReleaseVersionNumber == 16)
		macOsVersion = "Sierra";
	else if(darwinReleaseVersionNumber == 15)
		macOsVersion = "El Capitan";
	else if(darwinReleaseVersionNumber == 14)
		macOsVersion = "Yosemite";
	else if(darwinReleaseVersionNumber == 13)
		macOsVersion = "Mavericks";
	else if(darwinReleaseVersionNumber == 12)
		macOsVersion = "Mountain Lion";
	else if(darwinReleaseVersionNumber == 11)
		macOsVersion = "Lion";
	else if(darwinReleaseVersionNumber == 10)
		macOsVersion = "Snow Leopard";
	else if(darwinReleaseVersionNumber == 9)
		macOsVersion = "Leopard";
	else if(darwinReleaseVersionNumber == 8)
		macOsVersion = "Tiger";
	else if(darwinReleaseVersionNumber == 7)
		macOsVersion = "Panther";
	else if(darwinReleaseVersionNumber == 6)
		macOsVersion = "Jaguar";
	else if(darwinReleaseVersionNumber == 5)
		macOsVersion = "Puma";
	else if(darwinReleaseVersionNumber == 4)
		macOsVersion = "Cheetah"i;
	else if(darwinReleaseVersionNumber == 3)
		macOsVersion = "Beta: Kodiak";
*/
	return(macOsVersion);
}

/*
std::string OsInfoModule::getNetworkPacketsIn(void)
{

// 	system("top -l 1| grep Networks > /tmp/topGrepFile.txt");

	system("top -l1 | head -10 > topGrepFile.txt");
	std::string networkPacketLine;
	std::string networkPacket;
	std::ifstream file("/tmp/topGrepFile.txt");
	std::stringstream buffer;
	buffer << file.rdbuf();
	
	networkPacket = buffer.str();
	std::cout << buffer << std::endl;
	std::cout << networkPacket << std::endl;
//	networkPacket = buffer;

//	if(file.is_open() == false)
//		networkPacket = "0";
//	else
//	{
//		while(std::getline(file, networkPacketLine))
//		{
//			std::getline(file, networkPacketLine);
			//file.close();
//		}
//		networkPacket = networkPacketLine.substr(19, 13);
//	}
//	return(networkPacket);
	return("String");
}
*/
/*
std::string OsInfoModule::getNetworkPacketsOut(void)
{
 //	system("top -l 1| grep Networks > /tmp/topGrepFile.txt");
	std::string networkPacketLine;
	std::string networkPacket;
	std::ifstream file("/tmp/topGrepFile.txt");
	if(file.is_open() == false)
		networkPacket = "0";
	else
	{
		std::getline(file, networkPacketLine);
		file.close();
		networkPacket = networkPacketLine.substr(37, 13);
	}
	return(networkPacket);
}
*/
/*
std::string OsInfoModule::getRamUsed(void)
{
	std::string ramUsedLine;
	std::string ramUsed;
	std::ifstream file("/tmp/topGrepFile.txt");
	if(file.is_open() == false)
		ramUsed = "0";
	else
	{
		std::getline(file, ramUsedLine);
		file.close();
		ramUsed = ramUsedLine.substr(37, 13);
	}
	return(ramUsed);

}
*/

/*
unsigned int OsInfoModule::getCpuCores(void)
{
	unsigned int numberOfCores;

	numberOfCores = std::thread::hardware_concurrency();
	return(numberOfCores);
}

int64_t OsInfoModule::getPhysicalMemoryBytes(void)
{
	int mib[2];
	int64_t physicalMemory;
	size_t length;

	mib[0] = CTL_HW;
	mib[1] = HW_MEMSIZE;
	length = sizeof(int64_t);
	sysctl(mib, 2, &physicalMemory, &length, NULL, 0);
	return(physicalMemory);
}

int OsInfoModule::getPhysicalMemoryMbytes(void)
{
	int mib[2];
	int64_t physicalMemory;
	size_t length;

	mib[0] = CTL_HW;
	mib[1] = HW_MEMSIZE;
	length = sizeof(int64_t);
	sysctl(mib, 2, &physicalMemory, &length, NULL, 0);

	return(physicalMemory / (1024 * 1024));
}


int OsInfoModule::getPhysicalMemoryGbytes(void)
{
	int mib[2];
	int64_t physicalMemory;
	size_t length;

	mib[0] = CTL_HW;
	mib[1] = HW_MEMSIZE;
	length = sizeof(int64_t);
	sysctl(mib, 2, &physicalMemory, &length, NULL, 0);

	return(physicalMemory / (1024 * 1024 * 1024));
}
*/


int main(void)
{
	OsInfoModule info;
//	info.getSystemInfo();

	std::cout << "username: " << info.getUserName() << std::endl;
	std::cout << "sysName: " << info.getSysName() << std::endl;

	std::cout << "nodeName: " << info.getNodeName() << std::endl;
	std::cout << "Darwin release version: " << info.getDarwinReleaseVersion() << std::endl;
	std::cout << "version release date: " << info.getVersionDate() << std::endl;
	std::cout << "Machine: " << info.getMachine() << std::endl;
	std::cout << "CPU: " << info.getCpuInfo() << std::endl;
//	std::cout << "Cores: " << info.getCpuCores() << std::endl;
//	std::cout << "RAM in bytes: " << info.getPhysicalMemoryBytes() << std::endl;
//	std::cout << "RAM in Megabytes: " << info.getPhysicalMemoryMbytes() << std::endl;
//	std::cout << "RAM in Gigabytes: " << info.getPhysicalMemoryGbytes() << std::endl;
	std::cout << "MacOs: " << info.getMacOs() << std::endl;
//	std::cout << "Network Packet in: " << info.getNetworkPacketsIn() << std::endl;
//	std::cout << "Network Packet out: " << info.getNetworkPacketsOut() << std::endl;
//	std::cout << info.getNetworkPackets() << std::endl;
//	int networkPackets =  system("top -l 1| grep Networks"); 
//	while(1)
//	{
//		std::cout << networkPackets << std::endl;
//		break;
//	}
}

