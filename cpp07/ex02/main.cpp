/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EktinOpUrims <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 22:01:33 by EktinOpUrims      #+#    #+#             */
/*   Updated: 2025/02/27 22:14:45 by EktinOpUrims     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "Array.hpp"

#define MAX_VAL 750

int main(int, char**)
{
	if (0 == 1)
	{
		Array<float> arr2 = Array<float>(-1);
		Array<float> * ptr = new Array<float>(arr2);
		Array<float> arr1 = Array<float>(arr2);

		for (unsigned int i = 0; i < arr2.size() + 4; ++i)
		{
			try
			{
				std::cout << arr2[i] << std::endl;
			}
			catch(std::exception const &e)
			{
				std::cout << e.what() << std::endl;
			}
			try
			{
				arr2[i] = 1.0f;
			}
			catch(std::exception const &e)
			{
				std::cout << e.what() << std::endl;
			}
		}

		delete ptr;
		return (0);
	}

	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	try
	{
		for (int i = 0; i < MAX_VAL; ++i)
		{
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}
	}
	catch (std::exception const & e)
	{
		std::cout << e.what() << std::endl;
	}

	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);

		test[0] = 4321;
		if (test[0] == numbers[0])
		{
			std::cerr << "unlikely to be the same!!!" << std::endl;
		}
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			delete [] mirror;
			std::cerr << "didn't save the same value!!" << std::endl;
			return (1);
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << "!!!" << std::endl;
	}

	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << "!!!" << std::endl;
	}

	Array<int> test(numbers);
	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	int	coincidence = 0;
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (test[i] == numbers[i])
		{
			++coincidence;
			std::cerr << "still have the same value!!" << std::endl;
		}
	}
	if (coincidence > 0)
	{
		std::cout << "Number of coincidences was " << coincidence << std::endl;
	}
	delete [] mirror;
	mirror = NULL;
	return (0);
}
