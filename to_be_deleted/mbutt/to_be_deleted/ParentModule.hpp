/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParentModule.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 14:38:19 by mbutt             #+#    #+#             */
/*   Updated: 2020/01/25 16:37:55 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARENTMODULE_HPP
# define PARENTMODULE_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

class ParentModule
{
	public:
		ParentModule(void);
		~ParentModule(void);
		std::string getTopInfo(void);
	
	protected:
		std::string[10] _topInfo;
		void _setUpdateTopInfo(void);
};

#endif
