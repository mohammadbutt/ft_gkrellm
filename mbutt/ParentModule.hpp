/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParentModule.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 14:38:19 by mbutt             #+#    #+#             */
/*   Updated: 2020/01/25 15:01:31 by mbutt            ###   ########.fr       */
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
	
	private:
		std::string _topInfo;
		void _setTopInfo(void);
};

#endif
