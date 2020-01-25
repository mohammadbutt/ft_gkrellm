/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DateTimeModule.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiang- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 20:23:54 by jchiang-          #+#    #+#             */
/*   Updated: 2020/01/24 21:15:00 by jchiang-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DateTimeModule.hpp"

DateTimeModule::DateTimeModule(void) {
	_now = time(0);
	_currentTime = localtime(&_now);
}

DateTimeModule::DateTimeModule(const DateTimeModule & copy) { *this = copy; }
DateTimeModule &DateTimeModule::operator = (const DateTimeModule & inputClass) {
	if (this == &inputClass)
		return *this;
	this->_now = inputClass._now;
	this->_currentTime = inputClass._currentTime;
	return *this;
}
DateTimeModule::~DateTimeModule(void) { }

int DateTimeModule::getCurrentYear(void) const { return (1900 + _currentTime->tm_year); }
int DateTimeModule::getCurrentMonth(void) const { return (1 + _currentTime->tm_mon); }
int DateTimeModule::getCurrentDay(void) const { return _currentTime->tm_mday; }
int DateTimeModule::getCurrentHour(void) const { return _currentTime->tm_hour; }
int DateTimeModule::getCurrentMin(void) const { return _currentTime->tm_min; }
int DateTimeModule::getCurrentSec(void) const { return (1 + _currentTime->tm_sec); }

void DateTimeModule::refreshCurrentTime(void) { 
	_now = time(0);
	_currentTime = localtime(&_now); 
}
