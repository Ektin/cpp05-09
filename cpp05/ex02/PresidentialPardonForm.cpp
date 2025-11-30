/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EktinOpUrims <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:04:31 by EktinOpUrims      #+#    #+#             */
/*   Updated: 2024/10/17 21:41:17 by EktinOpUrims     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("", 0, 0),
						_target("")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string const & target) : 
		AForm("PresidentialForm", 25, 5),
		_target(target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& src) :
				AForm(src)
{
	*this = src;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(PresidentialPardonForm const& src)
{
	AForm::operator=(src);
	return (*this);
}

std::string const&	PresidentialPardonForm::getTarget() const
{
	return _target;
}

void	PresidentialPardonForm::do_stuff() const
{
	std::cout << getTarget()
		<< " has been pardoned by Zaphod Beeblebrox.\n" << std::endl;
}

void	PresidentialPardonForm::execute(Bureaucrat & bur) const
{
	if (false == this->getSigned()) 
	{
		throw AForm::FormNotYetSignedException();
	}
	if (bur.getGrade() > this->getGradeExec())
		throw Bureaucrat::GradeTooLowException();

	do_stuff();
}

void	PresidentialPardonForm::print(std::ostream & os) const
{
	os << this->getName() << ", president form <target: "
			<< this->getTarget()
			<< ", signed: "
			<< this->getSigned()
			<< ", grade to sign " 
			<< this->getGradeSign()
			<< ", grade to execute " 
			<< this->getGradeExec() << ">";

}
