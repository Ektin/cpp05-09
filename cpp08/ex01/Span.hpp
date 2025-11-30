/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EktinOpUrims <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 15:34:07 by EktinOpUrims      #+#    #+#             */
/*   Updated: 2025/03/17 14:20:44 by EktinOpUrims     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <set>
# include <iostream>
# include <cstdlib>
# include <iterator>

class Span
{
	private:
		std::multiset<int>	_set;
		unsigned int	 	_capacity;
		int			_min;
		int			_max;

	private:
		Span();
	public:
		Span(unsigned int capacity);
		~Span();
		Span(Span const & src);
		Span &	operator=(Span const & src);

	public:
		void	addNumber(int n);
		int	shortestSpan() const;
		int	longestSpan() const;

	public:
		std::multiset<int> const & get_set() const {return _set;};
		int	get_max() const {return _max;};
		int	get_min() const {return _min;};
		int	get_size() const {return _set.size();}

	public:
		template <typename T>
		void    add_range_numbers(T start, T end)
		{
		        T       it;
		
			if (_set.size() + std::distance(start, end) > _capacity)
				throw(NotEnoughSpaceException());
			_set.insert(start, end);
		}
	public:
		class NotEnoughSpaceException : public std::exception
		{
			public:
				char const * what() const throw();
		};

		class NotEnoughElementsException : public std::exception
		{
			public:
				char const * what() const throw();
		};
};

std::ostream &	operator<<(std::ostream & os, Span const & src);

#endif // SPAN_HPP
