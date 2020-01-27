/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RamModule.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:55:27 by mbutt             #+#    #+#             */
/*   Updated: 2020/01/25 17:07:55 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAMMODULE_HPP
# define RAMMODULE_HPP

//#include "ParentModule.hpp"
#include <sys/sysctl.h>
#include <iostream>


class RamModule //: public ParentModule
{
	public:
		RamModule(void);
		~RamModule(void);
//		std::string		getRamUsed(void);
//		std::string		getRamUnUsed(void);
		int64_t			getPhysicalMemoryBytes(void);
		int				getPhysicalMemoryMbytes(void);
		int				getPhysicalMemoryGbytes(void);
	private:
};

# endif
