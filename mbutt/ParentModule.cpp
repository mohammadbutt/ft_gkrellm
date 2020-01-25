/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParentModule.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 14:40:25 by mbutt             #+#    #+#             */
/*   Updated: 2020/01/25 15:01:28 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ParentModule.hpp"

ParentModule::ParentModule(void)
{
	std::cout << "Calling constructor" << std::endl;
	_setTopInfo();
	return;
}

ParentModule::~ParentModule(void)
{
	std::cout << "Calling desctructor" << std::endl;
	return;
}

void ParentModule::_setTopInfo(void)
{
	system("top -l1 | head -10 > topGrepFile.txt");
	std::ifstream file("/tmp/topGrepFile.txt");
	std::stringstream topInfoBuffer;
	topInfoBuffer << file.rdbuf();

	_topInfo = topInfoBuffer.str();
	return;
}

std::string ParentModule::getTopInfo(void)
{
	return(_topInfo);
}

/*
int main(void)
{
	ParentModule pr;
	std::cout << pr.getTopInfo() << std::endl;
}
*/
