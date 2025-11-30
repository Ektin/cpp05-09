/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EktinOpUrims <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 14:43:16 by EktinOpUrims      #+#    #+#             */
/*   Updated: 2025/01/25 17:47:37 by EktinOpUrims     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter::ScalarConverter(ScalarConverter const& src)
{
	*this = src;
}

ScalarConverter &	ScalarConverter::operator=(ScalarConverter const& src)
{
	if (this != &src)
	{
	}
	return (*this);
}

void	ScalarConverter::convert(std::string const& str)
{
	e_type	type;

	type = get_type(str);
	/*std::cout << "You entered: " << str << "\nlength "
		<< str.length() << " = " << str.size() \
		<< "\ntype: " << (print_type(type)) << std::endl;
	for (unsigned int i = 0; i < str.length(); ++i)
		std::cout << str[i] << "|";
	std::cout << std::endl << std::endl;
	*/
	switch (type)
	{
		case CHAR:
			convert_char(str);
			break ;
		case INT:
			convert_int(str);
			break ;
		case FLOAT:
			convert_float(str);
			break ;
		case DOUBLE:
			convert_double(str);
			break ;
		case SPECIAL:
			convert_special(str);
			break ;
		case INVALID:
			std::cout << "wrong input or not supported" 
					<< std::endl;
		default:
			break ;
	}
}
