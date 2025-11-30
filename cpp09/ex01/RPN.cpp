/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EktinOpUrims <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:32:16 by EktinOpUrims      #+#    #+#             */
/*   Updated: 2025/03/24 14:17:19 by EktinOpUrims     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iomanip>

RPN::RPN()
{
}

RPN::~RPN()
{
}

RPN::RPN(RPN const & src)
{
	*this = src;
}

RPN&	RPN::operator=(RPN const & src)
{
	if (this != &src)
	{
	}
	return (*this);
}

RPN::RPN(std::string const & str): _cmd_line(str), _is_ok(0), _res(0)
{
	_is_ok = is_str_legal(_cmd_line);
	if (0 == _is_ok)
		return ;
	try
	{
		fill_stack();
		std::cout << std::setprecision(16) << _res << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
}

std::string const &	RPN::get_cmd_line() const
{
	return (_cmd_line);
}

int	RPN::get_is_ok() const
{
	return (_is_ok);
}

std::ostream&	operator<<(std::ostream & os, RPN const & src)
{
	os << src.get_cmd_line() << " : " << src.get_is_ok();
	return (os);
}

int	RPN::is_str_legal(std::string const & str)
{
	for (unsigned int i = 0; i < str.length(); ++i)
	{
		if (!is_digit(str[i]) && !is_operation(str[i]) \
					&& !is_ws(str[i]))
		{
			return (0);
		}
	}
	return (1);
}

int	RPN::is_digit(char ch)
{
	if ('0' <= ch && ch <= '9')
		return (1);
	return (0);
}

int	RPN::is_operation(char ch)
{
	if ('+' == ch || '-' == ch || '*' == ch || '/' == ch)
		return (1);
	return (0);
}

int	RPN::is_operation(std::string const & str)
{
	if (1 == str.length() and (1 == is_operation(str[0])))
		return (1);
	return (0);
}

int	RPN::is_ws(char ch)
{
	if (' ' == ch || '\t' == ch)
		return (1);
	return (0);
}

int	RPN::is_number(std::string const & str)
{
	int	start;

	start = 0;
	if (str.empty())
		return (0);
	if ('+' == str[0] || '-' == str[0])
		start = 1;
	if (1 == start && 1 == str.length())
		return (0);
	for (unsigned int i = start; i < str.length(); ++i)
	{
		if (!is_digit(str[i]))
			return (0);
	}
	return (1);
}

int	RPN::get_num(std::string const & str)
{
	std::istringstream	is;
	int	num;

	is.clear();
	is.str(str);
	is >> num;
	return (num);	
}

void	RPN::fill_stack()
{
	std::string	token;
	std::istringstream	is;
	double	curr_num;

	is.clear();
	is.str(_cmd_line);
	_stack.empty();
	while (std::getline(is >> std::ws, token, ' '))
	{
		if (is_number(token))
		{
			curr_num = (double)get_num(token);
			_stack.push(curr_num);
		}
		else if (is_operation(token))
		{
			perform_operation_on_stack(token);
		}
		else
		{
			throw (WrongInputException());
		}
	}
	if (1 != _stack.size())	
	{
		throw (StackCorruptedException());
	}
	_res = _stack.top();
	_stack.pop();
}

void	RPN::perform_operation_on_stack(std::string const & action)
{
	double	second_num;
	double	first_num;

	if (_stack.empty())
		throw (StackCorruptedException());
	second_num = _stack.top();
	_stack.pop();
	if (_stack.empty())
		throw (StackCorruptedException());
	first_num = _stack.top();
	_stack.pop();

	switch (action[0])
	{
		case '+':
			_stack.push(first_num + second_num);
			break ;
		case '*':
			_stack.push(first_num * second_num);
			break ;
		case '-':
			_stack.push(first_num - second_num);
			break ;
		case '/':
			if (0 == second_num)
				throw (ZeroDivisionException());
			_stack.push(first_num / second_num);
			break ;
	}
}

char const *	RPN::StackCorruptedException::what() const throw()
{
	return ("Error: stack is corrupted");
}

char const *	RPN::ZeroDivisionException::what() const throw()
{
	return ("Error: zero division is detected");
}

char const *	RPN::WrongInputException::what() const throw()
{
	return ("Error: the input is wrong");
}
