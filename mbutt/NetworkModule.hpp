/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetworkModule.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:16:41 by mbutt             #+#    #+#             */
/*   Updated: 2020/01/25 15:52:16 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NETWORKMODULE_HPP
# define NETWORKMODULE_HPP

#include "ParentModule.hpp"
//#include <iostream>

class NetworkModule : public ParentModule
{
	public:
		NetworkModule(void);
		~NetworkModule(void);
		std::string getNetworkPacketIn(void);
		std::string getNetworkPacketOut(void);
//	private:

};

# endif
