/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EktinOpUrims <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:04:31 by EktinOpUrims      #+#    #+#             */
/*   Updated: 2024/10/17 21:32:36 by EktinOpUrims     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("", 0, 0),
						_target("")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string const & target) : 
		AForm("RobotomyForm", 72, 45),
		_target(target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& src) :
				AForm(src)
{
	*this = src;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(RobotomyRequestForm const& src)
{
	AForm::operator=(src);
	return (*this);
}

std::string const&	RobotomyRequestForm::getTarget() const
{
	return _target;
}

void	RobotomyRequestForm::do_stuff() const
{
	std::cout << "drilllll" << std::endl;

	int	r;

	srand(time(NULL));
	r = rand() % 2;

	if (1 == r)
	{
		std::cout << getTarget()
			<< " has been successfully robotomized.\n" << std::endl;
	}
	else
	{
		std::cout << "Robotomy failed on " << getTarget()
			<< ".\n" << std::endl;
	}
}

void	RobotomyRequestForm::execute(Bureaucrat & bur) const
{
	if (false == this->getSigned()) 
	{
		throw AForm::FormNotYetSignedException();
	}
	if (bur.getGrade() > this->getGradeExec())
		throw Bureaucrat::GradeTooLowException();

	do_stuff();
}

void	RobotomyRequestForm::print(std::ostream & os) const
{
	os << this->getName() << ", robotomy form <target: "
			<< this->getTarget()
			<< ", signed: "
			<< this->getSigned()
			<< ", grade to sign " 
			<< this->getGradeSign()
			<< ", grade to execute " 
			<< this->getGradeExec() << ">";

}
