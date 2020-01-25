/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OsInfoModule.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:05:14 by mbutt             #+#    #+#             */
/*   Updated: 2020/01/24 20:04:27 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OSINFOMODULE_HPP
# define OSINFOMODULE_HPP

/*
** References and resources:
** stackoverflow.com/questions/6315666/c-get-linux-distribution-name-version
*/

#include <iostream>
#include <sys/utsname.h>

class OsInfoModule
{
	public:
		OsInfoModule(void);
		~OsInfoModule(void);
		std::string getUserName(void);
		std::string getSysName(void);
		std::string getNodeName(void);
		std::string getRelease(void);
		std::string getVersion(void);
		std::string getMachine(void);
		std::string getDomainName(void);
	private:
		struct utsname _info;
//		std::string userName;
//		std::string sysName;
//		std::string nodeName;
//		std::string release;
//		std::string version;
//		std::string machine;
//		std::string domainName;
//		void setSystemInfo(void);
};


#endif
