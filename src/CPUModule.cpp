/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUModule.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiang- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 09:21:11 by jchiang-          #+#    #+#             */
/*   Updated: 2020/01/25 20:59:15 by jchiang-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CPUModule.hpp"

CPUModule::CPUModule(void) { 

	size_t intSize = 32;
	char stringTmp[256];
	size_t stringSize = sizeof(stringTmp);
	
	sysctlbyname("machdep.cpu.core_count", &_cpuCoreCount, &intSize, NULL, 0);
	sysctlbyname("machdep.cpu.cache.size", &_cpuCasheSize, &intSize, NULL, 0);
	sysctlbyname("machdep.cpu.thread_count", &_cpuThreadCount, &intSize, NULL, 0);
	sysctlbyname("machdep.cpu.extfeatures", &stringTmp, &stringSize, NULL, 0);
	_cpuExFeatures = stringTmp;
	sysctlbyname("machdep.cpu.brand_string", &stringTmp, &stringSize, NULL, 0);
	_cpuBrandString = stringTmp;
	_cpuUsage = 0.0f;
}
CPUModule::CPUModule(const CPUModule & copy) { *this = copy; }
CPUModule &CPUModule::operator = (const CPUModule & inputClass) {
	if (this == &inputClass)
		return *this;
	this->_cpuCoreCount   = inputClass._cpuCoreCount; 
	this->_cpuCasheSize   = inputClass._cpuCasheSize;
	this->_cpuThreadCount = inputClass._cpuThreadCount;
	this->_cpuBrandString = inputClass._cpuBrandString;  
	this->_cpuExFeatures  = inputClass._cpuExFeatures;
	this->_cpuUsage       = inputClass._cpuUsage;
	return *this;
}

CPUModule::~CPUModule(void) { }

int CPUModule::getCpuCoreCount(void) const { return _cpuCoreCount; }
int CPUModule::getCpuCasheSize(void) const { return _cpuCasheSize; }
int CPUModule::getCpuThreadCount(void) const { return _cpuThreadCount; }
std::string CPUModule::getCpuBrandString(void) const { return _cpuBrandString; }
std::string CPUModule::getCpuExFeatures(void) const { return _cpuExFeatures; }
std::string CPUModule::getCpuUsage(void) const { return _cpuUsage; }
float CPUModule::getCpuUsageFloat(void) const { return _cpuUsageFloat; }


static float catchFloat(std::string &s) {
	std::stringstream ss(s);
	std::string tmp;
	float value;
	ss >> tmp >> tmp >> value;
	return value;
}

void CPUModule::update(void) {
	system("top -l1 | grep \'CPU usage\' > /tmp/cpu_usage.txt");
	std::ifstream cpuUsageFile("/tmp/cpu_usage.txt");
	if (cpuUsageFile.is_open()){
		getline(cpuUsageFile, _cpuUsage);
		cpuUsageFile.close();
	}
	_cpuUsageFloat = catchFloat(_cpuUsage);
};

std::vector<std::string> CPUModule::getInfo(void) {
	std::vector<std::string> cpuInfo;
	cpuInfo.push_back(convertIntToChar(_cpuCoreCount));
	cpuInfo.push_back(convertIntToChar(_cpuCasheSize));
	cpuInfo.push_back(convertIntToChar(_cpuThreadCount));
	cpuInfo.push_back(convertIntToChar(_cpuUsageFloat));
	cpuInfo.push_back(_cpuBrandString);
	cpuInfo.push_back(_cpuExFeatures);
	cpuInfo.push_back(_cpuUsage);
	return cpuInfo;
}

std::string convertIntToChar(float number) {
	char numberString[(((sizeof number) * CHAR_BIT) + 2)/3 + 2];
	sprintf(numberString, "%f", number);
	std::string tmp = numberString;
	return tmp;
}
