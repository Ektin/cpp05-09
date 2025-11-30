/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EktinOpUrims <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 14:38:24 by EktinOpUrims      #+#    #+#             */
/*   Updated: 2025/03/17 13:28:45 by EktinOpUrims     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <vector>
#include <map>
#include "easyfind.hpp"

int	main()
{
	if (1 == 1)
	{
		std::list<int>	lst;
		lst.push_back(234);
		lst.push_back(2);
		lst.push_back(3);
		lst.push_back(4);
		lst.push_back(24);
		try
		{
			//manualfind< std::list<int> >(lst, 42);
			easyfind< std::list<int> >(lst, 42);
		}
		catch(std::exception const & e)
		{
			std::cerr << "ERROR: Element not found" << std::endl;
		}
	}
	if (1 == 1)
	{
		std::vector<int>	vct;
		vct.push_back(234);
		vct.push_back(2);
		vct.push_back(3);
		vct.push_back(4);
		vct.push_back(24);
		try
		{
			//manualfind< std::vector<int> >(vct, 4);
			easyfind< std::vector<int> >(vct, 4);
		}
		catch (std::exception const & e)
		{
			std::cerr << "ERROR: Element not found" << std::endl;
		}
	}

	return (0);
}
