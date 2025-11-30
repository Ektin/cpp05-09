/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EktinOpUrims <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:00:27 by EktinOpUrims      #+#    #+#             */
/*   Updated: 2024/10/17 21:24:28 by EktinOpUrims     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name(""), _grade(150)
{
}

Bureaucrat::Bureaucrat(std::string const& name, int grade) : 
		_name(name), _grade(grade)
{
	if (_grade > 150)
	{
		_grade = 150;	
		throw GradeTooLowException();
	}
	if (_grade < 1)
	{
		throw GradeTooHighException();
	}
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(Bureaucrat const& src) : _name(src._name),
						_grade(src._grade)
{
}

Bureaucrat&	Bureaucrat::operator=(Bureaucrat const& src)
{
	if (this != &src)
	{
		//_name = src.getName();
		_grade = src._grade;
	}
	return (*this);
}

std::string const&	Bureaucrat::getName() const
{
	return (_name);
}

int	Bureaucrat::getGrade() const
{
	return (_grade);
}

void	Bureaucrat::promote()
{
	if (getGrade() <= 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	else if (getGrade() > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	else
	{
		--_grade;
	}
}

void	Bureaucrat::demote()
{
	if (getGrade() >= 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	else if (getGrade() < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	else
	{
		++_grade;
	}
}

void	Bureaucrat::signForm(AForm & form)
{
	try
	{
		form.beSigned(*this);
		std::cout << *this << " signed " << form << "\n" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << *this << " couldn't sign " << form 
			<< ", because of " << e.what() << "\n" << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		std::cout << *this << " executed " << form << "\n" << std::endl;
	}
	catch(std::exception & e)
	{
		std::cout << *this << " couldn't execute " << form
			<< ", because of " << e.what() << "\n" << std::endl;
	}
}

char const	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade Too High Exception");
}

char const	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade Too Low Exception");
}

std::ostream&	operator<<(std::ostream &os, Bureaucrat const& src)
{
	os << src.getName() << ", bureaucrat grade " << src.getGrade();
	return (os);
}
