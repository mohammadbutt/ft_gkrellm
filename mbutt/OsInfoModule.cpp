/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OsInfoModule.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:05:42 by mbutt             #+#    #+#             */
/*   Updated: 2020/01/24 20:04:30 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OsInfoModule.hpp"

OsInfoModule::OsInfoModule(void)
{
	// default constructor;
	std::cout << "Calling constructor" << std::endl;
	uname(&_info);
	//	getSystemInfo();
}


OsInfoModule::~OsInfoModule(void)
{
	//defualt destructor;
	std::cout << "Calling destructor" << std::endl;
}

/*
void OsInfoModule::setSystemInfo(void)
{
//	struct utsname info;
//	uname(&info);
	
	uname(&_info);
	userName = getenv("USER");

//	sysName = info.sysname;
//	nodeName = info.nodename;
//	release = info.release;
//	version = info.version;
//	machine = info.machine;


#ifdef _GUN_SOURCE
//	domainName = info.domainname;
#endif
}
*/

std::string OsInfoModule::getUserName(void)
{
	return(getenv("USER"));
}

std::string OsInfoModule::getSysName(void)
{
	return(_info.sysname);
}

std::string OsInfoModule::getNodeName(void)
{
	return(_info.nodename);
}

std::string OsInfoModule::getRelease(void)
{
	return(_info.release);
}

std::string OsInfoModule::getVersion(void)
{
	return(_info.version);
}

std::string OsInfoModule::getMachine(void)


int main(void)
{
	OsInfoModule info;
	info.getSystemInfo();

	std::cout << info.userName << std::endl;
	std::cout << info.sysName << std::endl;

	std::cout << info.nodeName << std::endl;
	std::cout << info.release << std::endl;
	std::cout << "version: " << info.version << std::endl;
	std::cout << info.machine << std::endl;
//	std::cout << info.domainName << std::endl;
//	osInfo();
//	osInfo();

}

