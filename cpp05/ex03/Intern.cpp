/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EktinOpUrims <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:36:06 by EktinOpUrims      #+#    #+#             */
/*   Updated: 2024/10/18 16:18:52 by EktinOpUrims     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::~Intern()
{
}

Intern::Intern(Intern const& src)
{
	*this = src;
}

Intern&	Intern::operator=(Intern const& src)
{
	if (this != &src)
	{
	}
	return (*this);
}

static AForm*	makeShrubbery(std::string const& target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm*	makeRobotomy(std::string const& target)
{
	return (new RobotomyRequestForm(target));
}

static AForm*	makePresident(std::string const& target)
{
	return (new PresidentialPardonForm(target));
}

AForm*	Intern::makeForm(std::string const& form, std::string const& target)
{
	std::string forms[] = {"shrubbery creation", \
				"robotomy request", "president pardon"};

	AForm*	(*ptr[])(std::string const&) =\
		{&makeShrubbery, &makeRobotomy, &makePresident};

	for (int i = 0; i < (int)(sizeof(forms) / sizeof(forms[0])); ++i)
	{
		if (form == forms[i])
		{
			return (ptr[i](target));
		};
	}

	return (NULL);
}
