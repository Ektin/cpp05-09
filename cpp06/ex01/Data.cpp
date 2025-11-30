/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EktinOpUrims <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 16:53:50 by EktinOpUrims      #+#    #+#             */
/*   Updated: 2025/01/25 18:24:37 by EktinOpUrims     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(): _num(0), _msg("")
{
}

Data::~Data()
{
}

Data::Data(Data const & src): _num(src.get_num()), _msg(src.get_msg())
{
	*this = src;
}

Data&	Data::operator=(Data const & src)
{
	if (this != &src)
	{
		this->_num = src.get_num();
		this->_msg = src.get_msg();
	}
	return (*this);
}

Data::Data(int num, std::string const & msg): _num(num), _msg(msg)
{
}

std::ostream&	operator<<(std::ostream & os, Data const & src)
{
	os << "[" << src.get_num() << ", " << src.get_msg() << "]";
	return (os);
}

int	Data::get_num(void) const
{
	return (this->_num);
}

std::string const & 	Data::get_msg(void) const
{
	return (this->_msg);
}
