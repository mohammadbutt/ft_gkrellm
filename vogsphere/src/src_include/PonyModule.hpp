/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PonyModule.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiang- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 17:29:28 by jchiang-          #+#    #+#             */
/*   Updated: 2020/01/26 17:59:10 by jchiang-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONYMODULE_HPP
# define PONYMODULE_HPP

#include "IMonitorModule.hpp"

#include <random>

class PonyModule : public IMonitorModule
{
	public:
		PonyModule(void);
		PonyModule(const PonyModule & copy);
		PonyModule &operator = (const PonyModule &);
		~PonyModule(void);

		void update(void);
		std::vector<std::string> getInfo(void);
	private:
		std::string _color;

};

#endif
