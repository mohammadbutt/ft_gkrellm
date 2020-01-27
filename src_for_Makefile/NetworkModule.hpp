/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetworkModule.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:16:41 by mbutt             #+#    #+#             */
/*   Updated: 2020/01/26 16:49:03 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NETWORKMODULE_HPP
# define NETWORKMODULE_HPP

#include <iostream>
#include <vector>
#include "IMonitorModule.hpp"

class NetworkModule : public IMonitorModule
{
	public:
		NetworkModule(void);
		~NetworkModule(void);
		std::string					getNetworkPacketIn(std::string topInfo);
		std::string					getNetworkPacketOut(std::string topInfo);
		std::vector<std::string> 	getInfo(void);
		void						update(void);
		void						setInfo(std::vector<std::string> topInfo);
	private:
		std::vector<std::string> 	_topInfo;
};

# endif
