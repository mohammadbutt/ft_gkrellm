/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUModule.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiang- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 09:21:11 by jchiang-          #+#    #+#             */
/*   Updated: 2020/01/25 10:34:08 by jchiang-         ###   ########.fr       */
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
	return *this;
}

CPUModule::~CPUModule(void) { }

int CPUModule::getCpuCoreCount(void) const { return _cpuCoreCount; }
int CPUModule::getCpuCasheSize(void) const { return _cpuCasheSize; }
int CPUModule::getCpuThreadCount(void) const { return _cpuThreadCount; }
std::string CPUModule::getCpuBrandString(void) const { return _cpuBrandString; }
std::string CPUModule::getCpuExFeatures(void) const { return _cpuExFeatures; }
