/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EktinOpUrims <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 09:13:54 by EktinOpUrims      #+#    #+#             */
/*   Updated: 2025/02/24 12:08:54 by EktinOpUrims     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include <iostream>

template <typename T>
void	swap(T &a, T &b)
{
	T	c;

	c = a;
	a = b;
	b = c;
}

template <typename T>
T &	min(T & a, T & b)
{
	return (a < b ? a : b);
}

template <typename T>
T &	max(T & a, T & b)
{
	return (a > b ? a : b);
}

#endif // UTILS_HPP
