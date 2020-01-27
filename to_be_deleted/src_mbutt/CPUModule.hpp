/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUModule.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiang- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 09:09:18 by jchiang-          #+#    #+#             */
/*   Updated: 2020/01/25 14:45:26 by jchiang-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPUMODULE_HPP
# define CPUMODULE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <sys/sysctl.h>
#include <mach/mach_init.h>
#include <mach/mach_error.h>
#include <mach/mach_host.h>
#include <mach/vm_map.h>

/*
 * sysctl -a | grep machdep.cpu
 * Read the info as needed 
 */
class CPUModule
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
};

#endif
