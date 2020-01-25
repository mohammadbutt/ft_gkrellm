/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:31:54 by mbutt             #+#    #+#             */
/*   Updated: 2020/01/24 16:03:19 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <windows.h>
#include <pwd.h>
#include <unistd.h>
#include <iostream>
#include <sys/utsname.h> // For utsname struct
#include <string>
int main(void)
{
//	std::cout << getenv("USER") << std::endl; 	// Gets username
//	std::cout << getlogin() << std::endl;		// Gets username

	struct utsname info;
	uname(&info);
	
	std::string systemName = info->nodename[]; 
//	int uname(struct utsname info);
	std::cout << uname.sysname << std::endl;

}
