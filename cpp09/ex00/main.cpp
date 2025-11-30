/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EktinOpUrims <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:24:49 by EktinOpUrims      #+#    #+#             */
/*   Updated: 2025/03/23 14:33:27 by EktinOpUrims     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>

#include "BitcoinExchange.hpp"

int	main(int argc, char * argv[])
{
	if (argc != 2)
	{
		std::cerr << "Error: could not open file" << std::endl;
		return (1);
	}

	BitcoinExchange	btc(DATABASE);
	if (0 == btc.is_read_ok())
	{
		std::cerr << "Error : reading of the file was unsuccessful:"
			<<" possibly corrupted file" << std::endl;
		return (1);
	}
	if (0 == 1)
	{
		std::cout << btc << std::endl;
	}
	btc.respond_set_of_requests(argv[1]);
	return (0);
}
