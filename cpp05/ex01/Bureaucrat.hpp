/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EktinOpUrims <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:52:16 by EktinOpUrims      #+#    #+#             */
/*   Updated: 2024/10/17 18:15:28 by EktinOpUrims     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
# include "Form.hpp"

class Bureaucrat
{
	public:
		virtual ~Bureaucrat();
		Bureaucrat(std::string const& name, int grade);

	private:
		Bureaucrat();
		Bureaucrat(Bureaucrat const& src);
		Bureaucrat&	operator=(Bureaucrat const& src);

	private:
		std::string const	_name;
		int			_grade;

	public:
		std::string const&	getName() const;
		int			getGrade() const;

	public:
		void	promote();
		void	demote();

	public:
		void	signForm(class Form & form);

	public:
		class GradeTooHighException : public std::exception
		{
			public:
				virtual char const *	what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual char const *	what() const throw();
		};
};

std::ostream&	operator<<(std::ostream &os, Bureaucrat const& src);

#endif // BUREAUCRAT_HPP
