/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EktinOpUrims <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:00:27 by EktinOpUrims      #+#    #+#             */
/*   Updated: 2024/10/17 16:58:37 by EktinOpUrims     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name(""), _grade(150)
{
}

Bureaucrat::Bureaucrat(std::string const& name, int grade) : 
		_name(name), _grade(grade)
{
	try
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
	catch(GradeTooHighException &e)
	{
		std::cout << e.what() << ": " << getGrade() << std::endl;
		_grade = 1;
	}
	catch(GradeTooLowException &e)
	{
		std::cout << e.what() << ": " << getGrade() << std::endl;
		_grade = 150;
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
	try
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
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << ": promotion is impossible" << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << ": illegal is caught on promotion"
			<< *this << std::endl;
	}
}

void	Bureaucrat::demote()
{
	try
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
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << ": demotion is impossible" << std::endl;
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << ": illegal is caught on demotion"
			<< *this << std::endl;
	}
}

char const	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade Too High Exception";
}

char const	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade Too Low Exception";
}

std::ostream&	operator<<(std::ostream &os, Bureaucrat const& src)
{
	os << src.getName() << ", bureaucrat grade " << src.getGrade();
	return (os);
}
