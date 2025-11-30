/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EktinOpUrims <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 19:32:45 by EktinOpUrims      #+#    #+#             */
/*   Updated: 2025/03/17 12:45:41 by EktinOpUrims     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{
}

template <typename T>
MutantStack<T>::~MutantStack()
{
}

template <typename T>
MutantStack<T>::MutantStack(MutantStack const & src) : std::stack<T>(src)
{
}

template <typename T>
MutantStack<T> & MutantStack<T>::operator=(MutantStack const & src)
{
	if (this != &src)
	{
		std::stack<T>::operator=(src);
	}
	return (*this);
}

template <typename T>
typename MutantStack<T>::iterator 	MutantStack<T>::begin()
{
	return (this->c.begin());
	return (std::stack<T>::c.begin());
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end()
{
	return (this->c.end());
}
