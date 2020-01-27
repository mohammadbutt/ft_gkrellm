/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiang- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 14:57:17 by jchiang-          #+#    #+#             */
/*   Updated: 2020/01/25 21:05:24 by jchiang-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORDISPLAY_HPP
# define IMONITORDISPLAY_HPP

#include "ManagerModule.hpp"

class IMonitorDisplay
{
	public:
		virtual ~IMonitorDisplay(void) { };
		virtual void render(ManagerModule * mn) = 0;
};

#endif
