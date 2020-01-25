/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DateTimeModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiang- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 20:07:05 by jchiang-          #+#    #+#             */
/*   Updated: 2020/01/24 20:50:30 by jchiang-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATETIMEMODULE_HPP
# define DATETIMEMODULE_HPP

#include <ctime>
#include <iostream>

class DateTimeModule
{
	private:
		time_t _now;
		tm *_currentTime;
	public:
		DateTimeModule(void);
		DateTimeModule(const DateTimeModule & copy);
		DateTimeModule &operator = (const DateTimeModule & inputClass);
		~DateTimeModule(void);

		// Getter for each time
		int getCurrentYear(void) const;
		int getCurrentMonth(void) const;
		int getCurrentDay(void) const;
		int getCurrentHour(void) const;
		int getCurrentMin(void) const;
		int getCurrentSec(void) const;

		// Refresh Timer
		void refreshCurrentTime(void);
};

#endif
