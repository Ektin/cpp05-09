/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EktinOpUrims <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:37:40 by EktinOpUrims      #+#    #+#             */
/*   Updated: 2025/02/24 14:07:33 by EktinOpUrims     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int	main(void)
{
	void (*funptr)(int &);
	void (*funptr2)(std::string &);

	int	arr[5] = {11, 12, 13, 14, 15};
	std::string arr_str[] = {"Good", "morning", "to", "you"};

	funptr = &my_fun;
	try
	{
		iter((int *)arr, sizeof(arr) / sizeof(arr[0]), funptr);
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	funptr2 = &my_fun;
	iter(arr_str, sizeof(arr_str) / sizeof(arr_str[0]), funptr2);
	return (0);
}
