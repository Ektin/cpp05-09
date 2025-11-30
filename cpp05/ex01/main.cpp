/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EktinOpUrims <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:54:49 by EktinOpUrims      #+#    #+#             */
/*   Updated: 2024/10/17 18:37:35 by EktinOpUrims     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	try
	{
		Bureaucrat	bur1("bob", 133);
		Bureaucrat	bur2("rhon", 123);


		bur2.promote();

		std:: cout << bur1 << std::endl;
		std:: cout << bur2 << std::endl;


		Form	form("coolform", 120, 20);

		std::cout << form << std::endl;

		//form.beSigned(bur1);
		bur1.signForm(form);
		bur1.signForm(form);
		for (int i = 0; i < 20; ++i)
			bur1.promote();
		bur1.signForm(form);
		bur1.signForm(form);
		//form.beSigned(bur2);
		//form.beSigned(bur2);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
