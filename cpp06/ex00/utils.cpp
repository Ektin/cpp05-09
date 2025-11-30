/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EktinOpUrims <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:08:59 by EktinOpUrims      #+#    #+#             */
/*   Updated: 2025/01/25 17:52:36 by EktinOpUrims     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

std::string	print_type(e_type type)
{
	switch (type)
	{
		case CHAR:
			return ("char");
			break;
		case INT:
			return ("int");
			break;
		case FLOAT:
			return ("float");
			break;
		case DOUBLE:
			return ("double");
			break;
		case SPECIAL:
			return ("special");
			break;
		case INVALID:
			return ("invalid");
			break;
		default:
			return ("how is that possible?");
	}
	return ("");
}

int	is_digit(char ch)
{
	if (ch >= '0' && ch <= '9')
		return (1);
	return (0);
}

int	is_displayable(char ch)
{
	if (ch >= ' ' && ch <= '~')
		return (1);
	return (0);
}

int	is_char(std::string const & str)
{
	if (str.length() == 1 && is_displayable(str[0]) && !is_digit(str[0]))
		return (1);
	if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
		return (1);
	return (0);
}

int	only_digits(std::string const& str, int start, int end)
{
	if (start < 0 || end > (int)str.length())
		return (-1);
	for (int i = start; i < end; ++i)
	{
		if (str[i] > '9' || str[i] < '0')
			return (0);
	}
	return (1);
}

std::string	int_to_str(int i)
{
	std::ostringstream	ss;

	ss.str("");
	ss.clear();

	ss << i;
	return (ss.str());
}

int	is_int(std::string const& str)
{
	/*int	start;

	start = 0;
	if (str[0] == '+' || str[0] == '-')
		start = 1;
	if (!only_digits(str, start, str.length()))
		return (0);*/
	if (int_to_str(std::atoi(str.c_str())) != str)
	{
		return (-1);
	}
	return (1);
}

int	is_float(std::string const& str)
{
	int	start;
	int	dot;
	int	end;

	start = 0;
	if (str[0] == '+' || str[0] == '-')
		start = 1;
	dot = str.find('.');
	end = str.find('f');
	if (-1 == end)
		end = str.find('F');
	if (str.length() != (unsigned int)end + 1)
		return (0);
	if (!only_digits(str, start, dot) || !only_digits(str, dot + 1, end))
		return (0);
	return (1);
}

int	is_double(std::string const& str)
{
	int	start;
	int	dot;

	start = 0;
	if (str[0] == '+' || str[0] == '-')
		start = 1;
	dot = str.find('.');
	if (!only_digits(str, start, dot) || \
				!only_digits(str, dot + 1, str.length()))
		return (0);
	return (1);
}

int	is_special(std::string const& str)
{
	std::string	special_str = "-inff +inff inff nanf -inf +inf inf nan";

	if ( 1 + str.find(' ') == 0 && 0 != 1 + special_str.find(str) )
		return (1);
	return (0);
}

e_type	get_type(std::string const& str)
{
	if (1 == is_char(str))
		return (CHAR);
	if (1 == is_int(str))
		return (INT);
	if (1 == is_float(str))
		return (FLOAT);
	if (1 == is_double(str))
		return (DOUBLE);
	if (1 == is_special(str))
		return (SPECIAL);
	if (-1 == is_int(str))
		return (INVALID);
	return (INVALID);
}

/* /////////////////////////////////// */

void	convert_char(std::string const & str)
{
	char	ch;

	ch = (1 == str.length()) ? str[0] : str[1];
	std::cout << "char: " << ch << std::endl;
	std::cout << "int: " << static_cast<int>(ch) << std::endl;
	std::cout << "float: " << static_cast<float>(ch) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(ch) << ".0" << std::endl;
}

void	display_as_char(int n)
{
	if (n < 0 || n > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!is_displayable(n))
		std::cout << "char: Non displayable" << std::endl;
	else if (n == '\'')
		std::cout << "char: \"" << static_cast<char>(n) \
				<< "\"" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(n) \
				<< "'" << std::endl;
}

void	convert_int(std::string const & str)
{
	int	n;

	n = std::atoi(str.c_str());

	display_as_char(n);
	std::cout << "int: " << n << std::endl;
	std::cout << "float: " << static_cast<float>(n) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(n) << ".0" << std::endl;
}

void	convert_float(std::string const & str)
{
	float			f;
	bool			add_dot;
	std::ostringstream	ss;


	f = std::atof(str.c_str());
	display_as_char(static_cast<int>(f));
	std::cout << "int: " << static_cast<int>(f) << std::endl;
	
	ss.str("");
	ss.clear();
	ss << f;
	add_dot = 0;
	if (only_digits(ss.str(), 0, ss.str().length()))
		add_dot = 1;
	std::cout << "float: " << ss.str() << (add_dot ? ".0f" : "f") << std::endl;

	ss.str("");
	ss.clear();
	ss << static_cast<double>(f);
	add_dot = 0;
	if (only_digits(ss.str(), 0, ss.str().length()))
		add_dot = 1;
	std::cout << "double: " << ss.str() \
			<< (add_dot ? ".0" : "")  << std::endl;
}

void	convert_double(std::string const & str)
{
	double			d;
	bool			add_dot;
	std::ostringstream	ss;

	d = std::atof(str.c_str());
	display_as_char(static_cast<int>(d));
	std::cout << "int: " << static_cast<int>(d) << std::endl;

	ss.str("");
	ss.clear();
	ss << static_cast<float>(d);
	add_dot = 0;
	if (only_digits(ss.str(), 0, ss.str().length()))
		add_dot = 1;
	std::cout << "float: " << ss.str() << (add_dot ? ".0f" : "f") << std::endl;

	ss.str("");
	ss.clear();
	ss << std::setprecision(15) << d;
	add_dot = 0;
	if (only_digits(ss.str(), 0, ss.str().length()))
		add_dot = 1;
	std::cout << "double: " << ss.str() << (add_dot ? ".0" : "")  << std::endl;
}

void	convert_special(std::string const & str)
{
	std::string	tmp_str = str.c_str();
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (str[str.length() - 2] == 'f' || "nanf" == str)
	{
		std::cout << "float: " << str  << std::endl;
		std::cout << "double: " << str.substr(0, str.length() - 1) \
			<< std::endl;
	}
	else
	{
		std::cout << "float: " << str << "f" << std::endl;
		std::cout << "double: " << str << std::endl;
	}
}
