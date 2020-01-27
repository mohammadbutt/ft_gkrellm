/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DateTimeModule.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiang- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 20:23:54 by jchiang-          #+#    #+#             */
/*   Updated: 2020/01/26 21:03:39 by mbutt            ###   ########.fr       */
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
	std::string months[] = { "Jan", "Feb", "Mar", "Apr", "May", "June",
		"July", "Aug", "Sept", "Oct", "Nov", "Dec" };
	return months[_currentTime->tm_mon]; 
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

std::string convertIntToChar(int number) {
	char numberString[(((sizeof number) * CHAR_BIT) + 2)/3 + 2];
	sprintf(numberString, "%d", number);
	std::string tmp = numberString;
	return tmp;
}

void DateTimeModule::update(void) { 
	_now = time(0);
	_currentTime = localtime(&_now); 
}

std::vector<std::string> DateTimeModule::getInfo(void) { 

	std::vector<std::string> timeInfo;
	timeInfo.push_back("Activity Monitor:");
	timeInfo.push_back("Date: " + getCurrentYear() + 
			" " + getCurrentMonth() + " " + getCurrentDay());
	timeInfo.push_back("Time: " + getCurrentHour() + ":" + 
			getCurrentMin() + ":" + getCurrentSec());
	return timeInfo;
}
