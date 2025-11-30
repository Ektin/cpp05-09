/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EktinOpUrims <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:54:49 by EktinOpUrims      #+#    #+#             */
/*   Updated: 2024/10/18 16:28:16 by EktinOpUrims     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main()
{
	try
	{
		Bureaucrat	bur1("bob", 45);
		AForm	*form_ptr;
		Intern	intern;

		std::string forms[] = {"shrubbery creation", \
				"robotomy request", "president pardon"};
		std::string targets[] = {"target", "Bender", "target"};

		for (int i = 0; i < (int)(sizeof(forms)/sizeof(forms[0])); ++i)
		{
			form_ptr = intern.makeForm(forms[i], targets[i]);
			if (form_ptr)
			{
				bur1.signForm(*form_ptr);
				bur1.executeForm(*form_ptr);
			}
			delete form_ptr;
			form_ptr = NULL;
		}
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
