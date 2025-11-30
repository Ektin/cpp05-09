/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EktinOpUrims <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 15:11:59 by EktinOpUrims      #+#    #+#             */
/*   Updated: 2025/01/25 19:00:25 by EktinOpUrims     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"
#include <iomanip>

int	main(int argc, char * argv[])
{
	(void)argc;
	(void)argv;

	Data	*a_ptr;

	a_ptr = new Data(5, "hi");

	long unsigned 	int	int_ptr;

	int_ptr = Serializer::serialize(a_ptr);
	std::cout << std::left<< std::setw(10) << "a_ptr: " << a_ptr << std::endl;
	std::cout << std::left << std::setw(10) << "int_ptr: " << int_ptr << std::endl;

	Data	*ptr = Serializer::deserialize(int_ptr);
	std::cout << std::left << std::setw(10) << "ptr: " << ptr << std::endl;


	std::cout << "object pointed to by ptr: " << *ptr << std::endl;

	delete a_ptr;

	return (0);
}
