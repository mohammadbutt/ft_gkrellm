/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiang- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 20:35:26 by jchiang-          #+#    #+#             */
/*   Updated: 2020/01/25 15:31:33 by jchiang-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DateTimeModule.hpp"
#include <time.h>
#include "CPUModule.hpp"
#include "NcursesDisplay.hpp"

/* --------------------------------------------------------------------------------------- */

void testNcursesDisplay(void)
{
	NcursesDisplay n = NcursesDisplay();
	n.render();
}

/* --------------------------------------------------------------------------------------- */
// CPU testing
void testCPUModule(void) 
{
	CPUModule cpu = CPUModule();
	std::cout << "Core: " <<  cpu.getCpuCoreCount() << std::endl;
	std::cout << "Cache size: " <<  cpu.getCpuCasheSize() << std::endl;
	std::cout << "Thread count: " <<  cpu.getCpuThreadCount() << std::endl;
	std::cout << cpu.getCpuBrandString() << std::endl;
	std::cout << cpu.getCpuExFeatures() << std::endl;
	cpu.update();
	std::cout << "CPU Usage: " << cpu.getCpuUsageFloat() << std::endl;
	std::cout << cpu.getCpuUsage() << std::endl;
}

/* --------------------------------------------------------------------------------------- */
// Timer Testing
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
//	testTimerModule();
//	testCPUModule();
	testNcursesDisplay();  
	return 0;
}
