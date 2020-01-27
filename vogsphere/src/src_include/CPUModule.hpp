/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUModule.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiang- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 09:09:18 by jchiang-          #+#    #+#             */
/*   Updated: 2020/01/26 21:03:16 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPUMODULE_HPP
# define CPUMODULE_HPP

#include "IMonitorModule.hpp"

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <math.h>
#include <sys/sysctl.h>
#include <mach/mach_init.h>
#include <mach/mach_error.h>
#include <mach/mach_host.h>
#include <mach/vm_map.h>

/*
** sysctl -a | grep machdep.cpu
** Read the info as needed 
*/

class CPUModule : public IMonitorModule
{
	private:
		int _cpuCoreCount;
		int _cpuCasheSize;
		int _cpuThreadCount;
		float _cpuUsageFloat;
		std::string _cpuBrandString;
		std::string _cpuExFeatures;
		std::string _cpuUsage;
	public:
		CPUModule(void);
		CPUModule(const CPUModule & copy);
		CPUModule &operator = (const CPUModule & inputClass);
		~CPUModule(void);

		float getCpuUsageFloat(void) const;
		int getCpuCoreCount(void) const;
		int getCpuCasheSize(void) const;
		int getCpuThreadCount(void) const;
		std::string getCpuBrandString(void) const;
		std::string getCpuExFeatures(void) const;
		std::string getCpuUsage(void) const;

		void update(void);
		std::vector<std::string> getInfo(void);
};
template <typename T>
std::string convertIntToChar(T & number) {
	char numberString[(((sizeof number) * CHAR_BIT) + 2)/3 + 2];
	if (ceilf(number) == number)
		sprintf(numberString, "%d", static_cast<int>(number));
	else
		sprintf(numberString, "%0.2f", static_cast<float>(number));
	std::string tmp = numberString;
	return tmp;
}

#endif
