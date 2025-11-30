/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EktinOpUrims <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 16:51:19 by EktinOpUrims      #+#    #+#             */
/*   Updated: 2025/01/25 18:12:17 by EktinOpUrims     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <string>

class Data
{
	public:
		Data();
		~Data();
		Data(Data const & src);
		Data&	operator=(Data const & src);
		Data(int num, std::string const & msg);

	private:
		int		_num;
		std::string	_msg;

	public:
		int			get_num(void) const;
		std::string const &	get_msg(void) const;
};

std::ostream & operator<<(std::ostream & os, Data const & src);

#endif // DATA_HPP
