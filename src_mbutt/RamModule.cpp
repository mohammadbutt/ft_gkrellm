/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RamModule.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:57:35 by mbutt             #+#    #+#             */
/*   Updated: 2020/01/25 22:26:54 by mbutt            ###   ########.fr       */
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

int64_t RamModule::getPhysicalMemoryBytes(void)
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

int RamModule::getPhysicalMemoryMbytes(void)
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

int RamModule::getPhysicalMemoryGbytes(void)
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

std::string RamModule::getPhysicalMemoryUsed(std::string topInfo)
{
	std::cout << topInfo.substr(9, 5) << std::endl;
	return("PhysicalMemoryUsed");
}

void RamModule::update(void)
{
	std::cout << topinfo.substr(35, 5) << std::endl;
	return("This");

}

std::vector<std::string> RamModule::updateRamModule(std::string topInfo)
{

}


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
