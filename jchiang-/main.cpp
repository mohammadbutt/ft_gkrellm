/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiang- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 20:35:26 by jchiang-          #+#    #+#             */
/*   Updated: 2020/01/24 21:09:47 by jchiang-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DateTimeModule.hpp"

#include <stdio.h>
#include <time.h>
void doTimer(DateTimeModule dtime)
{
	dtime.refreshCurrentTime();
	std::cout << "Year: " << dtime.getCurrentYear() << std::endl;
	std::cout << "Month: "<< dtime.getCurrentMonth() << std::endl;
	std::cout << "Day: "  << dtime.getCurrentDay() << std::endl;
	std::cout << "Time: " << dtime.getCurrentHour() << ": ";
	std::cout << dtime.getCurrentMin() << ": ";
	std::cout << dtime.getCurrentSec() << std::endl;
}

void testTimerModule(void)
{
	const int NUM_SECONDS = 1;
    int count = 1;

    double time_counter = 0;

    clock_t this_time = clock();
    clock_t last_time = this_time;

	DateTimeModule dtime = DateTimeModule();
    while(true)
    {
        this_time = clock();

        time_counter += (double)(this_time - last_time);

        last_time = this_time;

        if (time_counter > (double)(NUM_SECONDS * CLOCKS_PER_SEC))
        {
			doTimer(dtime);
            time_counter -= (double)(NUM_SECONDS * CLOCKS_PER_SEC);
			std::cout << "==========================================" << std::endl;
            count++;
        }

    }
}

int main()
{
	testTimerModule();
    return 0;
}
