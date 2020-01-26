/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiang- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 14:54:01 by jchiang-          #+#    #+#             */
/*   Updated: 2020/01/26 10:17:26 by jchiang-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORMODULE_HPP
# define IMONITORMODULE_HPP

#include "ft_gkrellm.hpp"

class IMonitorModule
{
	public:
		virtual ~IMonitorModule(void) { };
		virtual void update(void) = 0;
		virtual std::vector<std::string> getInfo(void) = 0;
};

#endif
