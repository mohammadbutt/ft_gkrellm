/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GraphicDisplay.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiang- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 15:31:46 by jchiang-          #+#    #+#             */
/*   Updated: 2020/01/26 16:19:41 by jchiang-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICDISPLAY_HPP
# define GRAPHICDISPLAY_HPP

#include "ManagerModule.hpp"
#include "IMonitorDisplay.hpp"

#include <SFML/Graphics.hpp>

class GraphicDisplay : public IMonitorDisplay
{
	public:
		GraphicDisplay(void);
		GraphicDisplay(const GraphicDisplay & copy);
		GraphicDisplay & operator = (const GraphicDisplay & inputClass);
		~GraphicDisplay(void);

		void render(ManagerModule *mn);

	private:
		sf::Font _font;

};

#endif
