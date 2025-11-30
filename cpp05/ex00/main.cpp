/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EktinOpUrims <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:54:49 by EktinOpUrims      #+#    #+#             */
/*   Updated: 2024/10/17 16:44:27 by EktinOpUrims     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat	bur1("hi", 153);
	Bureaucrat	bur2("hey", -153);


	bur2.promote();

	std:: cout << bur1 << std::endl;
	std:: cout << bur2 << std::endl;
	return (0);
}
