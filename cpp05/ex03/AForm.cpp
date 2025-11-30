/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EktinOpUrims <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:04:31 by EktinOpUrims      #+#    #+#             */
/*   Updated: 2024/10/17 20:20:06 by EktinOpUrims     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name(""),
		_signed(false),
		_grade_to_sign(0),
		_grade_to_exec(0)
{
}

AForm::~AForm()
{
}

AForm::AForm(std::string const & name, int grade_sign, int grade_exec) : 
		_name(name),
		_signed(false),
		_grade_to_sign(grade_sign),
		_grade_to_exec(grade_exec)
{
	if (_grade_to_sign > 150 || _grade_to_sign > 150)
		throw Bureaucrat::GradeTooLowException();	
	if (_grade_to_sign < 1 || _grade_to_exec < 1)
		throw Bureaucrat::GradeTooHighException();
}

AForm::AForm(AForm const& src) : 
				_name(src._name),
				_signed(src._signed),
				_grade_to_sign(src._grade_to_sign),
				_grade_to_exec(src._grade_to_exec)
{
	*this = src;
}

AForm&	AForm::operator=(AForm const& src)
{
	if (this != &src)
	{
		//_name = src.getName();
		_signed = src._signed;
		//_grade_to_sign = src._grade_to_sign;
		//_grade_to_exec = src._grade_to_exec;
	}
	return (*this);
}

std::string const&	AForm::getName() const
{
	return (_name);
}

bool	AForm::getSigned() const
{
	return (_signed);
}

int	AForm::getGradeSign() const
{
	return (_grade_to_sign);
}

int	AForm::getGradeExec() const
{
	return (_grade_to_exec);
}

void	AForm::beSigned(Bureaucrat & bur)
{
	if (bur.getGrade() > this->getGradeSign())
		throw Bureaucrat::GradeTooLowException();
	if (true == this->getSigned())
		throw AForm::FormAlreadySignedException();
	else
		this->_signed = true;
}

char const *	AForm::FormAlreadySignedException::what() const throw()
{
	return ("Form Already Signed Exception");
}

char const *	AForm::FormNotYetSignedException::what() const throw()
{
	return ("Form Not Yet Signed Exception");
}

void	AForm::print(std::ostream & os) const
{
	os << this->getName() << ", form signed: "
			<< this->getSigned()
			<< ", grade to sign " 
			<< this->getGradeSign()
			<< ", grade to execute " 
			<< this->getGradeExec();
}

std::ostream&	operator<<(std::ostream & os, AForm const& form)
{
	form.print(os);	

	return (os);
}
