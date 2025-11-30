/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EktinOpUrims <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:54:49 by EktinOpUrims      #+#    #+#             */
/*   Updated: 2024/10/17 21:45:54 by EktinOpUrims     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	try
	{
		Bureaucrat	bur1("hi", 146);
		Bureaucrat	bur2("hey", 123);


		bur2.promote();

		std:: cout << bur1 << std::endl;
		std:: cout << bur2 << std::endl;


		ShrubberyCreationForm	form("coolform");
		RobotomyRequestForm	roboform("robot");
		PresidentialPardonForm	presform("president");

		std::cout << form << std::endl;

		//form.beSigned(bur1);
		bur2.executeForm(form);
		bur1.signForm(form);
		bur1.signForm(form);
		for (int i = 0; i < 1; ++i)
			bur1.promote();
		bur1.signForm(form);
		bur1.signForm(form);
		bur1.executeForm(form);
		bur1.executeForm(form);
		for (int i = 0; i < 10; ++i)
			bur1.promote();
		bur1.executeForm(form);
		bur1.executeForm(form);
		//form.beSigned(bur2);
		//form.beSigned(bur2);

		for (int i = 0; i < 100; ++i)
			bur1.promote();
		bur1.signForm(roboform);
		bur1.executeForm(roboform);


		bur2.signForm(presform);
		bur2.executeForm(presform);
		for (int i = 0; i < 116; ++i)
			bur2.promote();
		bur2.signForm(presform);
		bur2.executeForm(presform);
		for (int i = 0; i < 1; ++i)
			bur2.promote();
		bur2.signForm(presform);
		bur2.executeForm(presform);


	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
