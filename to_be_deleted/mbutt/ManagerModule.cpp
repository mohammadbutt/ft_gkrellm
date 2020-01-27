/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ManagerModule.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 16:47:39 by mbutt             #+#    #+#             */
/*   Updated: 2020/01/25 19:16:42 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ManagerModule.hpp"


ManagerModule::ManagerModule(void)
{
	std::cout << "ManagerModule constructor" << std::endl;
	setUpdateTopInfo();

	networkMode = NetworkModule();
	return;
}

ManagerModule::~ManagerModule(void)
{
	std::cout << "ManagerModule desctructor" << std::endl;
	return;
}


void ManagerModule::setUpdateTopInfo(void)
{
	int i = 0;
	system("top -l1 | head -10 > /tmp/topGrepFile.txt");	
	std::ifstream file("/tmp/topGrepFile.txt");
	if(file.is_open() == false)
		while(i < 10)
			topInfo[i++] = "0";
	else
		while(i < 10)
			std::getline(file, topInfo[i++]);
	return;
}

void 		ManagerModule::update(void)
{
	setUpdateTopInfo();
	networkMode.getNetworkPacketIn(topInfo[8]);
}
std::string  ManagerModule::getterForNetworkModuleIn(void)
{
//	std::cout << "Printing top info:" << std::endl << std::endl;
	std::cout << topInfo[8] << std::endl;
	return(networkMode.getNetworkPacketIn(topInfo[8]));
//	std::cout << std::endl;
}

std::string  ManagerModule::getterForNetworkModuleOut(void)
{
//	std::cout << "Printing top info:" << std::endl << std::endl;
	std::cout << topInfo[8] << std::endl;
	return(networkMode.getNetworkPacketOut(topInfo[8]));
//	std::cout << std::endl;
}

std::string ManagerModule::getTopInfo(int index)
{
//	_setTopInfo();
	
	return(topInfo[index]);
}


int main(void)
{
	ManagerModule pr;
	std::cout << pr.getTopInfo(0) << std::endl;
	
	std::cout << "Printing top info:" << std::endl << std::endl;
	std::cout << pr.getterForNetworkModuleIn() << std::endl;
	std::cout << "Done printing top info:" << std::endl;

	std::cout << "Printing top info:" << std::endl << std::endl;
	std::cout << pr.getterForNetworkModuleOut() << std::endl;
	std::cout << "Done printing top info:" << std::endl;
//	std::cout << pr.getTopInfo() << std::endl;
//	std::cout << pr.
}

