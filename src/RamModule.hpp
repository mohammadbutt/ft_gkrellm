/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RamModule.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:55:27 by mbutt             #+#    #+#             */
/*   Updated: 2020/01/26 12:54:01 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAMMODULE_HPP
# define RAMMODULE_HPP

#include <sys/sysctl.h>
#include <iostream>
#include <vector>
#include "IMonitorModule.hpp"

class RamModule : public IMonitorModule
{
	public:
		RamModule(void);
		~RamModule(void);
		std::string					getPhysicalMemoryBytes(void);
		std::string					getPhysicalMemoryMbytes(void);
		std::string					getPhysicalMemoryGbytes(void);	
		std::string					getPhysicalMemoryUsed(std::string topInfo);
		std::string					getPhysicalMemoryUnUsed(std::string topInfo);
//		std::vector<std::string>	getInfo(std::string topInfo[]);	
		std::vector<std::string>	getInfo(void); // Added by mbutt - Done
		void						update(void);
		void	setInfo(std::vector<std::string> Info); // Added by mbutt - Done
	private:
		std::vector<std::string>	_topInfo;

};

# endif
