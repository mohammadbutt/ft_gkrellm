/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RamModule.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:57:35 by mbutt             #+#    #+#             */
/*   Updated: 2020/01/26 11:04:04 by mbutt            ###   ########.fr       */
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
}

std::string RamModule::getPhysicalMemoryUsed(std::string topInfo)
{
	return(topInfo.substr(9, 5));
}

std::string RamModule::getPhysicalMemoryUnUsed(std::string topInfo)
{
	return(topInfo.substr(35, 5));
}

void RamModule::update(void)
{

}

std::vector<std::string> RamModule::getInfo(std::string topInfo[])
{
	std::vector<std::string> ramVector;
	ramVector.push_back(getPhysicalMemoryUsed(topInfo[6]));
	ramVector.push_back(getPhysicalMemoryUnUsed(topInfo[6]));
	ramVector.push_back(getPhysicalMemoryGbytes());
	ramVector.push_back(getPhysicalMemoryMbytes());
	ramVector.push_back(getPhysicalMemoryBytes());
	return(ramVector);
}
