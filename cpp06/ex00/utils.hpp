/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EktinOpUrims <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:06:22 by EktinOpUrims      #+#    #+#             */
/*   Updated: 2025/01/21 21:14:07 by EktinOpUrims     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <iomanip>

enum	e_type
{
	CHAR, INT, FLOAT, DOUBLE, SPECIAL, INVALID
};

std::string	print_type(e_type	type);
int		is_digit(char ch);
int		is_displayable(char ch);
int		is_char(std::string const & str);
int		only_digits(std::string const& str, int start, int end);
std::string	int_to_str(int i);

int		is_int(std::string const & str);
int		is_float(std::string const & str);
int		is_double(std::string const & str);
int		is_special(std::string const & str);
e_type		get_type(std::string const & str);

void	convert_char(std::string const & str);
void	display_as_char(int i);
void	convert_int(std::string const & str);
void	convert_float(std::string const & str);
void	convert_double(std::string const & str);
void	convert_special(std::string const & str);

#endif // UTILS_HPP
