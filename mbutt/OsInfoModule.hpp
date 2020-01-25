/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OsInfoModule.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:05:14 by mbutt             #+#    #+#             */
/*   Updated: 2020/01/24 20:46:33 by mbutt            ###   ########.fr       */
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

class OsInfoModule
{
	public:
		OsInfoModule(void);
		~OsInfoModule(void);
		std::string getUserName(void);
		std::string getSysName(void);
		std::string getNodeName(void);
		std::string getReleaseVersion(void);
		std::string getVersionDate(void);
		std::string getMachine(void);
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
