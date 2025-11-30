/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EktinOpUrims <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:04:31 by EktinOpUrims      #+#    #+#             */
/*   Updated: 2024/10/17 18:38:14 by EktinOpUrims     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name(""),
		_signed(false),
		_grade_to_sign(0),
		_grade_to_exec(0)
{
}

Form::~Form()
{
}

Form::Form(std::string const & name, int grade_sign, int grade_exec) : 
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

Form::Form(Form const& src) : 
				_name(src._name),
				_signed(src._signed),
				_grade_to_sign(src._grade_to_sign),
				_grade_to_exec(src._grade_to_exec)
{
	*this = src;
}

Form&	Form::operator=(Form const& src)
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

std::string const&	Form::getName() const
{
	return (_name);
}

bool	Form::getSigned() const
{
	return (_signed);
}

int	Form::getGradeSign() const
{
	return (_grade_to_sign);
}

int	Form::getGradeExec() const
{
	return (_grade_to_exec);
}

void	Form::beSigned(Bureaucrat & bur)
{
	if (bur.getGrade() <= this->getGradeSign())
	{
		if (this->getSigned())
			throw Form::FormAlreadySignedException();
		else
			this->_signed = true;
	}
	else
		throw Bureaucrat::GradeTooLowException();
}

char const *	Form::FormAlreadySignedException::what() const throw()
{
	return ("Form Already Signed Exception");
}


std::ostream&	operator<<(std::ostream & os, Form const& form)
{
	os << form.getName() << ", form <signed: "
			<< form.getSigned()
			<< ", grade to sign " 
			<< form.getGradeSign()
			<< ", grade to execute " 
			<< form.getGradeExec() << ">";
	return (os);
}
