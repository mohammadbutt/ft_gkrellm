/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RamModule.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:57:35 by mbutt             #+#    #+#             */
/*   Updated: 2020/01/26 11:01:27 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RamModule.hpp"

RamModule::RamModule(void)
{
	std::cout << "RamModule constructor" << std::endl;
	return;
}

RamModule::~RamModule(void)
{
	std::cout << "RamModule destructor" << std::endl;
	return;
}

/*
std::string RamModule::getRamUsed(void)
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
	return("RamUsed");
}
*/

std::string RamModule::getPhysicalMemoryBytes(void)
{
	int mib[2];
	int64_t physicalMemory;
	size_t length;

	mib[0] = CTL_HW;
	mib[1] = HW_MEMSIZE;
	length = sizeof(int64_t);
	sysctl(mib, 2, &physicalMemory, &length, NULL, 0);
	return(std::to_string(physicalMemory));
}

std::string RamModule::getPhysicalMemoryMbytes(void)
{
	int mib[2];
	int64_t physicalMemory;
	int64_t	physicalMemoryInMbytes;
	size_t length;

	mib[0] = CTL_HW;
	mib[1] = HW_MEMSIZE;
	length = sizeof(int64_t);
	sysctl(mib, 2, &physicalMemory, &length, NULL, 0);
	physicalMemoryInMbytes = (physicalMemory / (1024 * 1024));
	
	return(std::to_string(physicalMemoryInMbytes));
//	return(physicalMemory / (1024 * 1024));
}

std::string RamModule::getPhysicalMemoryGbytes(void)
{
	int mib[2];
	int64_t physicalMemory;
	int64_t physicalMemoryInGbytes;
	size_t length;

	mib[0] = CTL_HW;
	mib[1] = HW_MEMSIZE;
	length = sizeof(int64_t);
	sysctl(mib, 2, &physicalMemory, &length, NULL, 0);
	physicalMemoryInGbytes = (physicalMemory / (1024 * 1024 * 1024));
	
	return(std::to_string(physicalMemoryInGbytes));
//	std::string memoryGbytesString;
//	memoryGbytesString = std::to_string((physicalMemory / (1024 * 1024 * 1024)));

//	std::cout << "Physical Memory String" << std::endl;
//	std::cout << memoryGbytesString << std::endl;
//	return(physicalMemory / (1024 * 1024 * 1024));
}

std::string RamModule::getPhysicalMemoryUsed(std::string topInfo)
{
//	std::cout << "Physical memory used" << std::endl;
//	std::cout << topInfo.substr(9, 5) << std::endl;
	return(topInfo.substr(9, 5));
}

std::string RamModule::getPhysicalMemoryUnUsed(std::string topInfo)
{
//	std::cout << "Physcial memory used" << std::endl;
//	std::cout << topInfo.substr(35, 5) << std::endl;
	return(topInfo.substr(35, 5));
}

void RamModule::update(void)
{
//	std::cout << topinfo.substr(35, 5) << std::endl;
//	return("This");
}

std::vector<std::string> RamModule::getInfo(std::string topInfo[])
{

//	std::cout << "Inside RamModule::getInfo" << std::endl;

	std::vector<std::string> ramVector;

	
	ramVector.push_back(getPhysicalMemoryUsed(topInfo[6]));
	ramVector.push_back(getPhysicalMemoryUnUsed(topInfo[6]));
	ramVector.push_back(getPhysicalMemoryGbytes());
	ramVector.push_back(getPhysicalMemoryMbytes());
	ramVector.push_back(getPhysicalMemoryBytes());

//	std::cout << getPhysicalMemoryGbytes() << std::endl;
//	std::cout << getPhysicalMemoryMbytes()[0] << std::endl;
//	std::cout << getPhysicalMemoryBytes()[0] << std::endl;
	return(ramVector);
}

/*
std::vector<std::string> RamModule::updateRamModule(std::string topInfo)
{

}
*/

/*
int main(void)
{
	RamModule ramMode;

	std::cout << "Ram in bytes: " << ramMode.getPhysicalMemoryBytes();
	std::cout << std::endl;
	std::cout << "Ram in Mbytes: " << ramMode.getPhysicalMemoryMbytes();
	std::cout << std::endl;
	std::cout << "Ram in Gigabyte: " << ramMode.getPhysicalMemoryGbytes();
	std::cout << std::endl;
}
*/
