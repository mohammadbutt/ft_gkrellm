/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RamModule.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:57:35 by mbutt             #+#    #+#             */
/*   Updated: 2020/01/26 16:17:20 by mbutt            ###   ########.fr       */
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
//	std::cout << "token: " << token << std::endl;
//	return(topInfo.substr(9, 5));
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
//	std::cout << "token: " << token << std::endl;
//	return(topInfo.substr(35, 5));
}


std::vector<std::string> RamModule::getInfo(void)
{
	std::vector<std::string> ramVector;
	if(_topInfo.empty() == false)
	{
		ramVector.push_back("RAM Unused: " + getPhysicalMemoryUsed(_topInfo[6]));
		ramVector.push_back("RAM Used: " + getPhysicalMemoryUnUsed(_topInfo[6]));
	}
	ramVector.push_back("Total RAM in Gigabytes: " + getPhysicalMemoryGbytes());
	ramVector.push_back("Total RAM in Megabytes: " + getPhysicalMemoryMbytes());
	ramVector.push_back("Total RAM in     Bytes: " + getPhysicalMemoryBytes());

//	const char *str;
//	str = ramVector[0].c_str();
//	std::cout << "Printing vector through string" << str << std::endl;
//	std::cout << ramVector[0] 
//	std::cout << ramVector[0] << std::endl;
	return(ramVector);
}
/*
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
*/
void RamModule::setInfo(std::vector<std::string> Info)
{
	_topInfo = Info;
}

void RamModule::update(void)
{
}
