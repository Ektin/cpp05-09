/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EktinOpUrims <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 19:18:10 by EktinOpUrims      #+#    #+#             */
/*   Updated: 2025/03/17 13:06:04 by EktinOpUrims     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include "MutantStack.hpp"
#include "MutantStack.cpp"

int	main()
{
	if (0 == 1)
	{	
		MutantStack<int>	mstack;

		MutantStack<int>	mut2 = mstack;
	
		mstack.push(5);

		MutantStack<int>::iterator	iter = mstack.begin();

		for (iter = mstack.begin(); iter < mstack.end(); ++iter)
		{
			std::cout << "    mstack : " << *iter << std::endl;
		}

		std::stack<int>		mystack;

		mstack.pop();

		MutantStack<int>::iterator	it;
		mstack.begin();

		std::stack<int>	stack(mstack);
	}

	if (1 == 1)
	{
		MutantStack<int>	mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << mstack.top() << std::endl;

		mstack.pop();

		std::cout << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
	
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);

		std::cout << "\n" << std::endl;
		int const * iter;
		for (iter = &mstack.top() - mstack.size() + 1; \
				iter <= &mstack.top(); ++iter)
		{
			std::cout << ":" << *iter << std::endl;
		}

	}

	if (2 == 2)
	{
		std::cout << "\n\n" << std::endl;
		std::list<int>	mstack;

		mstack.push_back(5);
		mstack.push_back(17);

		std::cout << mstack.back() << std::endl;

		mstack.pop_back();

		std::cout << mstack.size() << std::endl;

		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
	
		mstack.push_back(0);

		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::list<int>	s(mstack);
	}
	if (3 == 3)
	{
		std::stack<int>	st;
		std::list<int>	li;

		std::list<int> lis(li);
	}

	return (0);
}
