/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EktinOpUrims <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 15:51:52 by EktinOpUrims      #+#    #+#             */
/*   Updated: 2025/03/17 14:23:25 by EktinOpUrims     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <list>
#include "Span.tpp"
#include "Span.hpp"

int	main()
{
	if (0 == 0)
	{
		Span	sp1(1);

		try
		{
			sp1.addNumber(534);
			sp1.addNumber(1234);
			sp1.addNumber(436);
			sp1.addNumber(2824);
			sp1.addNumber(177);
		}
		catch(std::exception const & e)
		{
			std::cout << e.what() << std::endl;
		}
		Span	sp2 = sp1;
		
		try
		{
			sp1.addNumber(17437);
		}
		catch (std::exception const & e)
		{
			std::cout << e.what() << std::endl;
		}
	
		std::cout << sp1 << std::endl;
		std::cout << sp2 << std::endl;

		try
		{
			std::cout << sp1.shortestSpan();
			std::cout << sp1.longestSpan();
		}
		catch (std::exception const & e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	if (1 == 1)
	{
		Span sp3(100000);
		srand(time(NULL));
		for (int i = 0; i < 10010; ++i)
		{
			try
			{
				sp3.addNumber(rand());
			}
			catch (std::exception const & e)
			{
				std::cerr << e.what(); 
			}
		}
		try
		{
			std::cout << sp3 << std::endl;
		}
		catch (std::exception const & e) {}
		std::cout << std::endl;
	}

	if (2 == 2)
	{
		Span	sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		std::cout << std::endl;
	}
	if (3 == 3)
	{
		std::list<int>	lst;

		lst.push_back(12);
		lst.push_back(1312);
		lst.push_back(142);
		lst.push_back(563712);
		lst.push_back(87612);

		Span sp(4);
		try
		{
			sp.add_range_numbers<std::list<int>::iterator>(lst.begin(), lst.end());
		}
		catch (std::exception const & e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << sp << std::endl;
	}
	return (0);
}
