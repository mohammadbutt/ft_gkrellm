/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiang- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 19:37:34 by jchiang-          #+#    #+#             */
/*   Updated: 2020/01/25 20:36:13 by jchiang-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ManagerModule.hpp"
#include "NcursesDisplay.hpp"

int main(void)
{
	ManagerModule mn = ManagerModule();
	NcursesDisplay nc = NcursesDisplay();
	nc.render(&mn);
	return 0;
}
