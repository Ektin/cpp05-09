/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EktinOpUrims <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:33:52 by EktinOpUrims      #+#    #+#             */
/*   Updated: 2025/03/24 14:15:11 by EktinOpUrims     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

int	main(int argc,  char * argv[])
{
	if (argc != 2)
	{
		std::cerr << "Error: wrong number of arguments" << std::endl;
		return (1);
	}

	RPN	rpn(argv[1]);
	if (0 == rpn.get_is_ok())
	{
		std::cerr << "Error: the input contains "
				"illegal characters" << std::endl;
		return (2);
	}
	return (0);
}
