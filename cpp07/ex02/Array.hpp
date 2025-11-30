/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EktinOpUrims <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:35:16 by EktinOpUrims      #+#    #+#             */
/*   Updated: 2025/02/27 22:07:00 by EktinOpUrims     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>

template <typename T>
class Array
{
	private:
		T		_elem;
		T *	 	_arr;
		unsigned int	_length;

	public:
		Array<T>(): _arr(NULL), _length(0)
		{
			T	*ptr = new T();
			_elem = *ptr;
			delete ptr;
			ptr = NULL;
		};

		Array<T>(unsigned int length): 
			_arr(NULL),
			_length(0)
		{
			T	*ptr = new T();
			_elem = *ptr;
			delete ptr;
			ptr = NULL;
			if ((int)length < 0)
			{
				std::cerr << "WARNING : negative size of array. Setting to 0" << std::endl;
				_length = 0;
				_arr = NULL;
				return ;
			}	
			if (0 == length)
			{
				delete [] _arr;
				_arr = NULL;
				return ;
			}
			_length = length;
			_arr = new T [_length];
			if (NULL == _arr)
			{
				std::cerr << "Failed to allocate " << std::endl;
				_length = 0;
				_arr = NULL;
				return ;
			}
			
			for (unsigned int i = 0; i < _length; ++i)
			{
				_arr[i] = _elem;
			}
		}

		virtual	~Array<T>()
		{
			delete [] _arr;
			_arr = NULL;
			_length = 0;
		}

		Array<T>(Array<T> const & src): 
			_arr(NULL), _length(0)
		{
			*this = src;
		}

		Array<T> &	operator=(Array<T> const & src)
		{
			if (this != &src)
			{
				_elem = src._elem;
				delete [] this->_arr;	
				this->_length = src._length;
				this->_arr = new T[_length];	
				for (unsigned int i = 0; i < _length; ++i)
				{
					_arr[i] = src._arr[i];
				}
			}
			return (*this);
		}

		unsigned int	size() const
		{
			return (_length);
		}

		T &	operator[](int i)
		{
			if (i < 0 || ((unsigned int)i >= _length))
			{
				throw std::invalid_argument("ERROR : Index out of range");
				return (_elem);
			}
			return (_arr[i]);
		}
};

#endif // ARRAY_HPP
