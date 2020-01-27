/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DateTimeModule.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiang- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 20:23:54 by jchiang-          #+#    #+#             */
/*   Updated: 2020/01/25 18:55:49 by jchiang-         ###   ########.fr       */
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

std::string DateTimeModule::getCurrentYear(void) const { 
	return convertIntToChar((1900 + _currentTime->tm_year)); 
}
std::string DateTimeModule::getCurrentMonth(void) const { 
	return convertIntToChar((1 + _currentTime->tm_mon)); 
}
std::string DateTimeModule::getCurrentDay(void) const { 
	return convertIntToChar(_currentTime->tm_mday); 
}
std::string DateTimeModule::getCurrentHour(void) const { 
	return convertIntToChar(_currentTime->tm_hour); 
}
std::string DateTimeModule::getCurrentMin(void) const { 
	return convertIntToChar(_currentTime->tm_min); 
}
std::string DateTimeModule::getCurrentSec(void) const { 
	return convertIntToChar(1 + _currentTime->tm_sec); 
}

void DateTimeModule::refreshCurrentTime(void) { 
	_now = time(0);
	_currentTime = localtime(&_now); 
}

std::string convertIntToChar(int number) {
	char numberString[(((sizeof number) * CHAR_BIT) + 2)/3 + 2];
	sprintf(numberString, "%d", number);
	std::string tmp = numberString;
	return tmp;
}
