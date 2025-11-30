/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EktinOpUrims <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:06:13 by EktinOpUrims      #+#    #+#             */
/*   Updated: 2025/03/01 19:45:35 by EktinOpUrims     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span():_capacity(0), _min(0), _max(0)
{
}

Span::~Span()
{
}

Span::Span(unsigned int capacity):_capacity(capacity), _min(0), _max(0)
{
	if ((int)_capacity < 0)
	{
		std::cerr << "WARNING: required capacity is either negative"
			<< " or too large, "
			<< "setting to 128" << std::endl;
		_capacity = 128;
	}
}

Span::Span(Span const & src)
{
	*this = src;
}

Span & Span::operator=(Span const & src)
{
	if (this != &src)
	{
		_capacity = src._capacity;
		_set = src._set;
		_min = src._min;
		_max = src._max;
	}
	return (*this);
}

void	Span::addNumber(int n)
{
	if (_set.size() >= _capacity)
	{
		throw(NotEnoughSpaceException());
	}
	_set.insert(n);
	if (1 == _set.size())
	{
		_max = n;
		_min = n;
	}
	else
	{
		if (n > _max)
			_max = n;
		else if (n < _min)
			_min = n;
	}
}

std::ostream &  operator<<(std::ostream & os, Span const & src)
{
	std::multiset<int>::const_iterator	it;
	int	i;
	int	too_much = -1;
	if (src.get_size() > 10)
		too_much = 5;

	if (too_much > 0)
		os << "\n";
	for (i = 0, it = src.get_set().begin(); 
		it != src.get_set().end(); ++it, ++i)
	{
		if (too_much < 0 || (i < too_much) \
				|| (i > src.get_size() - too_much))
			os << *it << "; ";
		if (i == too_much)
			os << " ...... ; ";
	}
	if (too_much > 0)
	{
		os << "\nsize : " << src.get_size();
		os << ", {min-max}, [short, long] : ";
	}
	os << " [" << src.get_min() << " -- " << src.get_max() << "]";
	try
	{
		int tmp = src.shortestSpan();
		os << " {" << tmp << ", " 
			<< src.longestSpan() << "}";
	}
	catch (std::exception const & e)
	{
	}
	return (os);
}

int	Span::longestSpan() const
{
	if (get_size() < 2)
	{
		throw (NotEnoughElementsException());
	}
	return (_max - _min);
}

int	Span::shortestSpan() const
{
	int	span = longestSpan();
	int	prev;

	std::multiset<int>::const_iterator	it = _set.begin();

	prev = *it;
	++it;

	for (; it != _set.end(); ++it)
	{
		if (*it - prev < span)
			span = *it - prev;
		if (0 == span)
			return (0);
		prev = *it;
	}
	return (span);
}

/*template <typename T>
void	Span::add_range_numbers(T start, T end)
{
	T	it;

	for (it = start; it != end; ++it)
	{
		try
		{
			addNumber(*it);
		}
		catch(std::exception const & e)
		{
			break ;
		}
	}
}*/

char const * Span::NotEnoughSpaceException::what() const throw()
{
	return "Error: Not enough space";
}

char const *	Span::NotEnoughElementsException::what() const throw()
{
	return "Error: Not enough elements";
}
