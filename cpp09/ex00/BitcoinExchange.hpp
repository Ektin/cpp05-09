/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EktinOpUrims <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:26:25 by EktinOpUrims      #+#    #+#             */
/*   Updated: 2025/03/23 14:12:44 by EktinOpUrims     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <string>
# include <iostream>
# include <fstream>
# include <sstream>
# include <map>

# define DATABASE "data.csv"

class BitcoinExchange
{
	private:
		std::map < std::string, double, \
			std::greater<std::string> >	_dict;
		int	_read_ok;

	public:
		std::map<std::string, double>::const_iterator	get_begin() const;
		std::map<std::string, double>::const_iterator	get_end() const;
		int	is_read_ok() const;

	public:
		~BitcoinExchange();

	private:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const & src);
		BitcoinExchange &	operator=(BitcoinExchange const & src);

	public:
		BitcoinExchange(char const * const filename);

	public:
		void	respond_set_of_requests(
				char const * const request_filename) const;
		void	respond_single_request(
				std::string const & request) const;
	private:
		static	int	is_request_correct(std::string const & rqst, \
				std::string & date, double & quantity);
	private:
		static	int	is_digit(char ch);
		static	int	only_digits(std::string const & str, 
						int beg, int end);
		static	int	is_num(std::string const & str);
		static	double	get_number(std::string const & str);

		static	void	remove_ws_beg_end(std::string &str);
		static	int	is_ws(char ch);
		static 	int	is_date(std::string const & date);
	private:
		static	int	is_date_correct(int, int, int);
		static 	int	is_date_in_good_writing(std::string const & date);
};

std::ostream & 	operator<<(std::ostream & os, BitcoinExchange const & btc);

#endif // BITCOINEXCHANGE_HPP
