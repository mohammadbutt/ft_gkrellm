/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetworkModule.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:18:49 by mbutt             #+#    #+#             */
/*   Updated: 2020/01/26 16:27:59 by mbutt            ###   ########.fr       */
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

std::string NetworkModule::getNetworkPacketIn(std::string topInfo)
{

//	std::string networkIn  = getTopInfo().substr(414, 13);
//	std::string networkIn  = getTopInfo.substr(414, 13);
//	return(networkIn);
	std::string delimiter = " ";
	std::string token;
	int i = 0;
	size_t position = 0;
	while(i < 3)
	{
		position = topInfo.find(delimiter);
		token = topInfo.substr(0, position);
		topInfo.erase(0, position + delimiter.length());
		i++;
	}
//	return("this is a test");
	return(token);
//	return(getTopInfo.substr(19, 13));

}

std::string NetworkModule::getNetworkPacketOut(std::string topInfo)
//std::string NetworkModule::getNetworkPacketOut(void)
{
//	std::string networkOut =  getTopInfo.substr(432, 13);
//	std::string networkOut =  getTopInfo().substr(432, 13);	
//	return(networkOut);
	std::string delimiter = " ";
	std::string token;
	int i = 0;
	size_t position = 0;
	while(i < 5)
	{
		position = topInfo.find(delimiter);
		token = topInfo.substr(0, position);
		topInfo.erase(0, position + delimiter.length());
		i++;
	}
	return(token);
//	return("potato");
//	return(getTopInfo.substr(37, 13));
}


//std::vector<std::string> NetworkModule::getInfo(std::string Info[])
std::vector<std::string> NetworkModule::getInfo(void)
{
//	std::cout << "Comes here succefully" << std::endl;
//	std::cout << getTopInfo[8] << std::endl;
//	std::cout << getNetworkPacketIn(getTopInfo[8]) << std::endl;
//	std::cout << "Does it come here1" << std::endl;
	std::vector<std::string> trimmedVector;
//	trimmedVector.push_back(getNetworkPacketIn(Info[8]));
//	trimmedVector.push_back(getNetworkPacketOut(Info[8]));
	if (!_topInfo.empty())
	{
		trimmedVector.push_back("Network In: " + getNetworkPacketIn(_topInfo[8]));
		trimmedVector.push_back("Network Out: " + getNetworkPacketOut(_topInfo[8]));
	}
	return(trimmedVector);

}

void NetworkModule::setInfo(std::vector<std::string> topInfo)
{
	_topInfo = topInfo;
}

void NetworkModule::update(void)
{
}

/*
int main(void)
{
//	NetworkModule nm;
//	std::cout << nm.getTopInfo << std::endl << std::endl;
//	std::cout << nm.getNetworkPacketIn()  << "|" << std::endl;
//	std::cout << nm.getNetworkPacketOut() << "|" << std::endl;
}
*/
