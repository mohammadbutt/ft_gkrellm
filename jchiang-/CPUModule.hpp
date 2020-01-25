/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUModule.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiang- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 09:09:18 by jchiang-          #+#    #+#             */
/*   Updated: 2020/01/25 10:26:56 by jchiang-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPUMODULE_HPP
# define CPUMODULE_HPP

#include <iostream>
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
		std::string _cpuBrandString;
		std::string _cpuExFeatures;
	public:
		CPUModule(void);
		CPUModule(const CPUModule & copy);
		CPUModule &operator = (const CPUModule & inputClass);
		~CPUModule(void);

		float getCpuUsage(void) const;
		int getCpuCoreCount(void) const;
		int getCpuCasheSize(void) const;
		int getCpuThreadCount(void) const;
		std::string getCpuBrandString(void) const;
		std::string getCpuExFeatures(void) const;
};

#endif
