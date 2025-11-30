/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EktinOpUrims <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:38:21 by EktinOpUrims      #+#    #+#             */
/*   Updated: 2025/02/24 14:09:58 by EktinOpUrims     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void	iter(T * ptr, long unsigned int size, void (*funptr)(T & t))
{
	if (NULL == ptr || 0 == size)
		return ;
	for (unsigned int i = 0; i < size; ++i)
	{
		try
		{
			funptr(ptr[i]);
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;	
		}
	}
}

template <typename T>
void	my_fun(T & t)
{
	std::cout << "General call for my_fun " 
		<< t << std::endl;
}

template <>
void	my_fun<int>(int & n)
{
	std::cout << "Call for my_fun<int> " << n << std::endl;
}

#endif //ITER_HPP
