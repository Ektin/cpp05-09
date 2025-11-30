/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EktinOpUrims <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:59:53 by EktinOpUrims      #+#    #+#             */
/*   Updated: 2024/10/17 18:24:49 by EktinOpUrims     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Form
{
	public:
		virtual ~Form();
		Form(std::string const& name, int grade_sign, int grade_exec);

	private:
		Form();
		Form(Form const& form);
		Form&	operator=(Form const& form);

	private:
		std::string const	_name;
		bool			_signed;
		int const		_grade_to_sign;
		int const		_grade_to_exec;

	public:
		std::string const&	getName() const;
		bool			getSigned() const;
		int			getGradeSign() const;
		int			getGradeExec() const;

	public:
		void	beSigned(class Bureaucrat & bur);

	public:
		class FormAlreadySignedException : public std::exception
		{
			virtual char const *	what() const throw();
		};
};

std::ostream&	operator<<(std::ostream &os, Form const& form);

#endif // FORM_HPP
