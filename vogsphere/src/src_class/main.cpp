/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiang- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 16:33:09 by jchiang-          #+#    #+#             */
/*   Updated: 2020/01/26 21:27:39 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src_include/ManagerModule.hpp"
#include "../src_include/NcursesDisplay.hpp"
#include "../src_include/GraphicDisplay.hpp"


int main(int argc, char **argv)
{
	if (argc == 2) {
		std::string text = "Text";
		std::string graph = "Graph";
		ManagerModule mn = ManagerModule();
		if (!text.compare(argv[1])) {
			NcursesDisplay nc = NcursesDisplay();
			nc.render(&mn);
			return 0;
		} else if (!graph.compare(argv[1])) {
			GraphicDisplay gh = GraphicDisplay();
			gh.render(&mn);
		}
	}
	std::cout << "Usage: ./ft_gkrellm [Text / Graph]" << std::endl;
	return -1;
}
