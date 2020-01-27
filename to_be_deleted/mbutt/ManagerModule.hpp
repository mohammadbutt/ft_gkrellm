/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ManagerModule.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 16:38:02 by mbutt             #+#    #+#             */
/*   Updated: 2020/01/25 19:16:52 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANAGERMODULE_HPP
# define MANAGERMODULE_HPP

#include "NetworkModule.hpp"
//#include "RamModule.hpp"

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

class NetworkModule;
class ManagerModule 
{
	public:
//		RamModule		ramModule;

		ManagerModule(void);
		~ManagerModule(void);
		std::string getTopInfo(int index);
		std::string topInfo[10];
		void setUpdateTopInfo(void);
		std::string getterForNetworkModuleIn(void);
		std::string getterForNetworkModuleOut(void);
//	protected:
	private:
		NetworkModule networkMode;
};

# endif
