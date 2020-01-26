/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RamModule.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:55:27 by mbutt             #+#    #+#             */
/*   Updated: 2020/01/25 22:26:57 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAMMODULE_HPP
# define RAMMODULE_HPP

//#include "ParentModule.hpp"
#include <sys/sysctl.h>
#include <iostream>
#include <vector>
#include "IMonitorModule.hpp"

class RamModule : public IMonitorModule//: public ParentModule
{
	public:
		RamModule(void);
		~RamModule(void);
//		std::string		getRamUsed(void);
//		std::string		getRamUnUsed(void);
		int64_t						getPhysicalMemoryBytes(void);
		int							getPhysicalMemoryMbytes(void);
		int							getPhysicalMemoryGbytes(void);
		
		std::string					getPhysicalMemoryUsed(std::string topInfo);
		std::string					getPhysciaMemoryUnused(std::string topInfo);
		void						update(void);
		std::vector<std::string>	updateRamModule(std::string topInfo);
	private:

};

# endif
