/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EktinOpUrims <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 14:47:36 by EktinOpUrims      #+#    #+#             */
/*   Updated: 2025/01/25 14:56:41 by EktinOpUrims     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "utils.hpp"
#include <iomanip>

int	main(int argc, char * argv[])
{
	if (argc != 2)
	{
		std::cout << "Example of usage: convert 123" << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}
/*
	double d;
	double	c = 0;

	d = -0/c;
	d = -d;
	std::cout << "d: " << d << std::endl;
	if (d != d)
	{
		std::cout << "d is not a d\n" << std::endl;
	}
*/
	
