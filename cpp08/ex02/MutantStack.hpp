/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EktinOpUrims <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 19:29:51 by EktinOpUrims      #+#    #+#             */
/*   Updated: 2025/03/17 12:37:18 by EktinOpUrims     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* https://stackoverflow.com/questions/73440733/how-can-i-implement-my-own-stack-iterator-in-c */

/* https://stackoverflow.com/questions/36621225/get-container-behind-stdstack */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <iterator>

template <typename T>
//class MutantStack : public std::stack< T, std::deque<T> >
class MutantStack : public std::stack< T>//, std::deque<T> >
{
	private:
	public:
		typedef	typename
		std::stack<T>::container_type::iterator	iterator;
		//typedef typename std::deque<T>::iterator	iterator;

	public:
		MutantStack();
		virtual ~MutantStack();
		MutantStack(MutantStack const & src);
		MutantStack & operator=(MutantStack const & src);

	public:
		typename MutantStack::iterator	begin();
		typename MutantStack::iterator	end();

};

#endif // MUTANTSTACK_HPP
