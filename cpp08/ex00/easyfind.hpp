/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EktinOpUrims <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 17:22:07 by EktinOpUrims      #+#    #+#             */
/*   Updated: 2025/03/17 13:29:28 by EktinOpUrims     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <exception>
# include <algorithm>

template <typename T>
void	easyfind(T const & t, int n)
{
	typename T::const_iterator	it;

	it = std::find(t.begin(), t.end(), n);
	if (it == t.end())
		throw (std::exception());
	std::cout << "The element " << *it << " was found" << std::endl;
}

template <typename T>
void	manualfind(T const & t, int n)
{
	typename T::const_iterator	it;

	int	found = 0;
	int	pos = 0;
	for (it = t.begin(); it != t.end() && 0 == found; ++it, ++pos)
	{
		if (*it == n)
		{
			found = 1;
			std::cout << "The element " << *it 
				<< " was found on the position " << pos << std::endl;
			break ;
		}
	}
	if (0 == found)
		throw (std::exception());
}

#endif // EASYFIND_HPP
