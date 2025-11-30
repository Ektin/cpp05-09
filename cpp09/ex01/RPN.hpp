/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EktinOpUrims <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:30:23 by EktinOpUrims      #+#    #+#             */
/*   Updated: 2025/03/24 13:41:33 by EktinOpUrims     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>
# include <iostream>
# include <sstream>

class RPN
{
	private:
		std::stack<double>	_stack;
		std::string 		_cmd_line;
		int			_is_ok;
		double			_res;

	public:
		std::string const &	get_cmd_line() const;
		int			get_is_ok() const;

	public:
		~RPN();
	private:
		RPN();
		RPN(RPN const & src);
		RPN&	operator=(RPN const & src);
	public:
		RPN(std::string const & str);

	private:
		static int	is_str_legal(std::string const & str);
		static int	is_digit(char ch);
		static int	is_operation(char ch);
		static int	is_operation(std::string const & str);
		static int	is_number(std::string const & str);
		static int	is_ws(char ch);
		static int	get_num(std::string const & str);

	private:
		void	fill_stack();
		void	perform_operation_on_stack(std::string const & action);

	public:
		class StackCorruptedException : public std::exception
		{
			public:
				char const * what() const throw();
		};
		class ZeroDivisionException : public std::exception
		{
			public:
				char const * what() const throw();
		};
		class WrongInputException : public std::exception
		{
			public:
				char const * what() const throw();
		};
};

std::ostream&	operator<<(std::ostream & os, RPN const & src);

#endif // RPN_HPP
