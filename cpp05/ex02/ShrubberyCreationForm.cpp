/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EktinOpUrims <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:04:31 by EktinOpUrims      #+#    #+#             */
/*   Updated: 2024/10/17 21:22:27 by EktinOpUrims     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("", 0, 0),
						_target("")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target) : 
		AForm("ShrubberyForm", 145, 137),
		_target(target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& src) :
				AForm(src)
{
	*this = src;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(ShrubberyCreationForm const& src)
{
	AForm::operator=(src);
	return (*this);
}

std::string const&	ShrubberyCreationForm::getTarget() const
{
	return _target;
}

void	ShrubberyCreationForm::do_stuff() const
{
	std::ofstream	myfile((getTarget() + "_shrubbery").c_str());

	int	m, i, j;

	m = 10;
	for (i = 1; i < m; ++i)
	{
		for (j = 0; j < m - i; ++j)
			myfile << " ";
		for (j = 0; j < 2 * i - 1; ++j)
			myfile << "x";
		for (j = 0; j < m - i; ++j)
			myfile << " ";
		myfile << "\n";
	}
	myfile.close();
}

void	ShrubberyCreationForm::execute(Bureaucrat & bur) const
{
	if (false == this->getSigned()) 
	{
		throw AForm::FormNotYetSignedException();
	}
	if (bur.getGrade() > this->getGradeExec())
		throw Bureaucrat::GradeTooLowException();

	do_stuff();
}

void	ShrubberyCreationForm::print(std::ostream & os) const
{
	os << this->getName() << ", shrubbery form <target: "
			<< this->getTarget()
			<< ", signed: "
			<< this->getSigned()
			<< ", grade to sign " 
			<< this->getGradeSign()
			<< ", grade to execute " 
			<< this->getGradeExec() << ">";

}
