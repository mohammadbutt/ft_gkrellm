/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetworkModule.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:16:41 by mbutt             #+#    #+#             */
/*   Updated: 2020/01/25 19:16:45 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NETWORKMODULE_HPP
# define NETWORKMODULE_HPP

//#include "ParentModule.hpp"
//#include <sys/sysctl.h>
//#include "ManagerModule.hpp"
#include <iostream>

class NetworkModule //: public ParentModule
{
	public:
		NetworkModule(void);
		~NetworkModule(void);
//		std::string		getNetworkPacketIn(void);		
		std::string		getNetworkPacketIn(std::string getTopInfo);
//		std::string		getNetworkPacketOut(void);
		std::string		getNetworkPacketOut(std::string getTopInfo);
	private:
//		std::string 	_topInfo;
		std::string		_networkIn;
		std::string		_networkOut;

};

# endif
