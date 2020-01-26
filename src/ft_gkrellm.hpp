/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gkrellm.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiang- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 07:51:16 by jchiang-          #+#    #+#             */
/*   Updated: 2020/01/26 10:08:59 by jchiang-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* --------------------------------------------------------------------------- */
/* -----------------------     General Header    ----------------------------- */
/* --------------------------------------------------------------------------- */

#ifndef FT_GKRELLM_HPP
# define FT_GKRELLM_HPP

#include <vector>
#include <string>
#include <iostream>


# define ESCAPE_KEY 27
# define CLERA_LINE "                                      "
# define SEPERATE_LINE "=============================================================== "

# define CPUPOSITION_Y 2
# define CPUPOSITION_X 2

typedef struct s_point {
	int x;
	int y;
}t_point;

#endif
