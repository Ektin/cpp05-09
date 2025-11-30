/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EktinOpUrims <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:50:42 by EktinOpUrims      #+#    #+#             */
/*   Updated: 2025/01/28 17:59:14 by EktinOpUrims     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include <cstdlib>
#include <iostream>

Base*	generate(void)
{
	char	ch;

	srand(time(NULL));
	ch = (char)(rand() % 3);

	switch (ch)
	{
		case (0):
			return (new A());
			break ;
		case (1):
			return (new B());
			break ;
		case (2):
			return (new C());
			break ;
		default:
			return (NULL);
			break ;
	}
	return (NULL);
}

void	identify(Base *p)
{
	std::cout << "identify by pointer : ";
	if (p == dynamic_cast<A*>(p))
	{
		std::cout << "A" << std::endl;
		return ;
	}
	else if (p == dynamic_cast<B*>(p))
	{
		std::cout << "B" << std::endl;
		return ;
	}
	if (p == dynamic_cast<C*>(p))
	{
		std::cout << "C" << std::endl;
		return ;
	}
	return ;	
}

void	identify(Base &p)
{
	std::cout << "identify by reference : ";
	try
	{
		dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;	
	}
	catch (std::exception &e)
	{
		// std::cout << e.what() << std::endl;
	}

	try
	{
		dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
	}
	catch (std::exception &e)
	{
		// std::cout << e.what() << std::endl;
	}

	try
	{
		dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
	}
	catch (std::exception &e)
	{
		// std::cout << e.what() << std::endl;
	}
	return ;
}
