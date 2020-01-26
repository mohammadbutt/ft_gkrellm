/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetworkModule.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:18:49 by mbutt             #+#    #+#             */
/*   Updated: 2020/01/25 15:52:10 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NetworkModule.hpp"

NetworkModule::NetworkModule(void)
{
	std::cout << "NetworkModule constructor" << std::endl;
	return;
}

NetworkModule::~NetworkModule(void)
{
	std::cout << "NetworkModule destructor" << std::endl;
}

std::string NetworkModule::getNetworkPacketIn(void)
{
//	char  substr[20];
	std::string networkIn  = getTopInfo().substr(414, 13);
//	networkIn = getTopInfo().substr(414, 13);
	return(networkIn);
}

std::string NetworkModule::getNetworkPacketOut(void)
{
//	char substr[20];
	std::string networkOut =  getTopInfo().substr(432, 13);
//	networkOut =  getTopInfo().substr(432, 13);
	return(networkOut);
}

/*
int main(void)
{
	NetworkModule nm;
	std::cout << nm.getTopInfo() << std::endl << std::endl;
//	std::cout << nm.getNetworkPacketIn()  << "|" << std::endl;
//	std::cout << nm.getNetworkPacketOut() << "|" << std::endl;
}
*/
