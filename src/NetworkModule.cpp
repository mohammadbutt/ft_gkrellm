/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetworkModule.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:18:49 by mbutt             #+#    #+#             */
/*   Updated: 2020/01/26 16:48:21 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NetworkModule.hpp"

NetworkModule::NetworkModule(void)
{
	return;
}

NetworkModule::~NetworkModule(void)
{
}

std::string NetworkModule::getNetworkPacketIn(std::string topInfo)
{
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
	return(token);
}

std::string NetworkModule::getNetworkPacketOut(std::string topInfo)
{
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
}

std::vector<std::string> NetworkModule::getInfo(void)
{
	std::vector<std::string> trimmedVector;
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
