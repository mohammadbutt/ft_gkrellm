/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OsInfoModule.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:05:14 by mbutt             #+#    #+#             */
/*   Updated: 2020/01/25 14:36:26 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OSINFOMODULE_HPP
# define OSINFOMODULE_HPP

# define _GNUE_SOURCE

/*
** References and resources:
** stackoverflow.com/questions/6315666/c-get-linux-distribution-name-version
*/

//#include <abc.h>
#include <iostream>
#include <sys/utsname.h>
#include <sys/sysctl.h>
#include <thread>
#include <fstream>
#include <streambuf>
#include <string>
#include <sstream>


class OsInfoModule
{
	public:
		OsInfoModule(void);
		~OsInfoModule(void);
		std::string getUserName(void);
		std::string getSysName(void);
		std::string getNodeName(void);
		std::string getDarwinReleaseVersion(void);
		std::string getVersionDate(void);
		std::string getMachine(void);
		std::string getCpuInfo(void);
		std::string getMacOs(void);
//		std::string getNetworkPacketsIn(void);
//		std::string getNetworkPacketsOut(void);
//		std::string getRamUsed(void);
//		int64_t getPhysicalMemoryBytes(void);
//		int		getPhysicalMemoryMbytes(void);
//		int		getPhysicalMemoryGbytes(void);
//		unsigned int getCpuCores(void);
	private:
		struct	utsname _info;
//		void	setter(void);
//		unsigned int _physical_memory;
};

#endif
