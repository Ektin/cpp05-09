/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EktinOpUrims <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:27:27 by EktinOpUrims      #+#    #+#             */
/*   Updated: 2025/03/23 14:35:34 by EktinOpUrims     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iomanip>

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & src)
{
	*this = src;
}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & src)
{
	if (this != &src)
	{
		_dict = src._dict;
		_read_ok = src._read_ok;
	}
	return (*this);
}

BitcoinExchange::BitcoinExchange(char const * const database): _read_ok(1)
{
	std::string 	line;
	std::string	date;
	std::string	value;
	double		value_num;

	std::ifstream	data(database, std::ios::in);
	if (0 == data.is_open())
	{
		_read_ok = 0;
		return ;
	}
	getline(data, line); // skip the first line
	std::istringstream	is;
	std::ostringstream	os;
	while (getline(data, line))
	{
		is.clear();
		is.str(line.c_str());
		std::getline(is, date, ',');
		std::getline(is, value, ',');
		is.clear();
		is.str(value.c_str());
		is >> value_num;
		os.clear();
		os.str("");
		os << std::setprecision(10) << value_num;
		if (os.str() != value)
		{
			std::cout << "values do not coincide" << std::endl;
			std::cout << "    [" << os.str() << "] : [" 
				<< value << "]" << std::endl;
			_read_ok = 0;
			data.close();
			return ;
		}
		if (value_num < 0)
		{
			std::cout << "number is negative" << std::endl;
			std::cout << line << std::endl;
			_read_ok = 0;
			data.close();
			return ;
		}
		if (0 == is_date_in_good_writing(date))
		{
			_read_ok = 0;
			std::cout << "data corrupted : [" << date << "]" 
				<< std::endl;
			data.close();
		}
		_dict[date] = value_num;
	}
	data.close();
}

std::map<std::string, double>::const_iterator	BitcoinExchange::get_begin() const
{
	return (this->_dict.begin());
}

std::map<std::string, double>::const_iterator	BitcoinExchange::get_end() const
{
	return (this->_dict.end());
}

int	BitcoinExchange::is_read_ok() const
{
	return (_read_ok);
}

std::ostream &	operator<<(std::ostream & os, BitcoinExchange const & btc)
{
	std::map<std::string, double>::const_iterator	it;
	int	count;

	for (count = 2, it = btc.get_end(); it != btc.get_begin(); ++count)
	{
		--it;
		std::cout << std::setw(4) << count << "; " 
			<< it->first << "; " 
			<< std::setprecision(10) << it->second << std::endl;
	}
	return (os);
}

////////////////////////////////////////////////////////////

int	BitcoinExchange::is_ws(char ch)
{
	if (' ' == ch || '\t' == ch || '\v' == ch || '\r' == ch)
	{
		return (1);
	}
	return (0);
}

void	BitcoinExchange::remove_ws_beg_end(std::string & str)
{
	unsigned int	beg;
	unsigned int	end;

	for (beg = 0; beg < str.length() && is_ws(str[beg]); ++beg);
	for (end = str.length(); end > beg && is_ws(str[end - 1]); --end);
	if (beg > end)
	{
		std::cerr << "    something wrong happened while deleting ws"
			<< "[" << str << "] (" << beg << "," << end << ")" 
			<< std::endl;
	}
	str = str.substr(beg, end - beg);
	return ;
}

int	BitcoinExchange::is_digit(char ch)
{
	if (ch >= '0' && ch <= '9')
		return (1);
	return (0);
}

// [beg, end)
int	BitcoinExchange::only_digits(std::string const & str, 
							int beg, int end)
{
	if (beg > end || beg < 0 || (unsigned int)end > str.length())
		return (-1);
	for (int i = beg; i < end; ++i)
	{
		if (0 == is_digit(str[i]))
			return (0);
	}
	return (1);
}

int	BitcoinExchange::is_date(std::string const & date)
{
	unsigned int	pos1;
	unsigned int	pos2;
	std::string	year_str;
	std::string	month_str;
	std::string	day_str;
	int	year_num;
	int	month_num;
	int	day_num;

	pos1 = date.find('-');
	pos2 = date.find('-', pos1 + 1);
	if ( 0 == pos1 + 1 or 0 == pos2 + 1)
		return (0);
	if (pos2 < pos1 + 2 || pos2 > pos1 + 3 || date.length() > pos2 + 3 \
			|| pos1 != 4)
		return (0);
	if (!only_digits(date, 0, pos1) || !only_digits(date, pos1 + 1, pos2)\
			|| !only_digits(date, pos2 + 1, date.length()))
		return (0);
	year_str = date.substr(0, pos1);
	month_str = date.substr(pos1 + 1, pos2 - pos1 - 1);
	day_str = date.substr(pos2 + 1, date.length() - pos2 - 1);
	std::istringstream	is;
	is.clear();
	is.str(year_str);
	is >> year_num;
	is.clear();
	is.str(month_str);
	is >> month_num;
	is.clear();
	is.str(day_str);
	is >> day_num;
	return (is_date_correct(year_num, month_num, day_num));
}

int	BitcoinExchange::is_date_correct(int year, int month, int day)
{
	if (year < 0 || year > 9999)
		return (0);
	if (month > 12 || month < 0)
		return (0);
	if (day > 31 || day < 0)
		return (0);
	if ((month <= 7) && (0 == (month & 1)) && (day > 30))
		return (0);
	if (month >= 8 && (1 == (month & 1)) && day > 30)
		return (0);
	if (2 == month && day > 29)
		return (0);
	if (2 == month)
	{
		if ((0 == (year % 100)) && (0 != (year % 400)) \
					&& day > 28)
			return (0);
		if (0 != (year % 4) && day > 28)
			return (0);
	}
	return (1);
}

int	BitcoinExchange::is_date_in_good_writing(std::string const & date)
{
	if (0 == is_date(date))
		return (0);
	if (date.length() != std::string("2024-11-02").length())
		return (0);
	return (1);
}

int	BitcoinExchange::is_num(std::string const & str)
{
	int	start_pos;
	int	dot_pos;

	if (str.empty())
		return (0);
	if (!is_digit(str[0]) && '-' != str[0] && '+' != str[0] && '.' != str[0])
		return (0);
	start_pos = 0;
	if ('-' == str[0] || '+' == str[0])
		start_pos = 1;
	dot_pos = str.find('.');
	if (dot_pos == -1)
		dot_pos = str.length();
	if (1 != only_digits(str, start_pos, dot_pos))
	{
		std::cout << "not a number1 " << str << std::endl;
		return (0);
	}
	if (dot_pos != (int)str.length() && 1 != only_digits(str, dot_pos + 1, str.length()))
	{
		std::cout << "not a number2 " << str << std::endl;
		return (0);
	}
	return (1);
}

double	BitcoinExchange::get_number(std::string const & str)
{
	std::istringstream	is;
	double	res;

	is.clear();
	is.str(str);
	is >> res;
	return (res);
}

void	BitcoinExchange::respond_set_of_requests(
			 char const * const request_filename) const
{
	std::ifstream	input_file(request_filename, std::ios::in);
	std::string	input_line;

	if (0 == input_file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
	}
	getline(input_file, input_line); // skip first line
	while (getline(input_file, input_line))
	{
		respond_single_request(input_line);
	}
	input_file.close();
}

int	BitcoinExchange::is_request_correct(std::string const & input_line, \
		std::string & date_str, double & quantity_num)
{
	std::string	quantity_str;
	int	delim_pos;

	delim_pos = input_line.find("|");
	if (-1 == delim_pos)
	{
		std::cout << "Error: bad input => " << input_line << std::endl;
		return (0);
	}
	date_str = input_line.substr(0, delim_pos);
	remove_ws_beg_end(date_str);
	quantity_str = input_line.substr(delim_pos + 1, \
			input_line.length() - delim_pos - 1);
	remove_ws_beg_end(quantity_str);
	if (0 == is_date(date_str))
	{
		std::cout << "Error: bad input : not a date => " \
			<< input_line << std::endl;
		return (0);
	}
	if (0 == is_num(quantity_str))
	{
		std::cout << "Error: bad input: not a number => " \
			<< input_line << std::endl;
		return (0);
	}
	quantity_num = get_number(quantity_str);
	if (quantity_num < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return (0);
	}
	if (quantity_num > 100)
	{
		std::cout << "Error: too large a number." << std::endl;
		return (0);
	}
	return (1);
}

void	BitcoinExchange::respond_single_request(
		std::string	const & input_line) const
{
	double		quantity_num;
	std::string	date_str;
	std::map<std::string, double>::const_iterator	iterator;

	if (input_line.empty() || !is_request_correct(input_line, date_str, \
				 quantity_num))
		return ;
	//std::cout << "Processing ... " ;
	//std::cout << "(" << date_str << ", " << quantity_num << ") ";
	iterator = _dict.lower_bound(date_str);
	if (iterator == get_end())
	{
		std::cout << "Error: the date of request is too early : " 
			<< date_str << std::endl;
		return ;
	}
	std::cout << date_str << " => " << quantity_num << " = ";
	std::cout << quantity_num * iterator->second << std::endl;
}
