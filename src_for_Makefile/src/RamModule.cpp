/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RamModule.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:57:35 by mbutt             #+#    #+#             */
/*   Updated: 2020/01/26 17:22:32 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RamModule.hpp"

RamModule::RamModule(void)
{
	return;
}

RamModule::~RamModule(void)
{
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
	std::string delimiter = " ";
	std::string token;
	int i = 0;
	size_t position = 0;

	while(i < 2)
	{
		position = topInfo.find(delimiter);
		token = topInfo.substr(0, position);
		topInfo.erase(0, position + delimiter.length());
		i++;
	}
	return(token);
}

std::string RamModule::getPhysicalMemoryUnUsed(std::string topInfo)
{

	std::string delimiter = " ";
	std::string token;
	int i = 0;
	size_t position = 0;

	while(i < 6)
	{
		position = topInfo.find(delimiter);
		token = topInfo.substr(0, position);
		topInfo.erase(0, position + delimiter.length());
		i++;
	}
	return(token);
}


std::vector<std::string> RamModule::getInfo(void)
{
	std::vector<std::string> ramVector;
	ramVector.push_back("RAM Info");
	if(_topInfo.empty() == false)
	{
		ramVector.push_back("RAM Unused: " + getPhysicalMemoryUsed(_topInfo[6]));
		ramVector.push_back("RAM Used: " + getPhysicalMemoryUnUsed(_topInfo[6]));
	}
	ramVector.push_back("Total RAM in Gigabytes: " + getPhysicalMemoryGbytes());
	ramVector.push_back("Total RAM in Megabytes: " + getPhysicalMemoryMbytes());
	ramVector.push_back("Total RAM in     Bytes: " + getPhysicalMemoryBytes());
	return(ramVector);
}

void RamModule::setInfo(std::vector<std::string> Info)
{
	_topInfo = Info;
}

void RamModule::update(void)
{
}
