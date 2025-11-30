/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EktinOpUrims <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:59:53 by EktinOpUrims      #+#    #+#             */
/*   Updated: 2024/10/17 21:21:49 by EktinOpUrims     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class AForm
{
	public:
		virtual ~AForm();
		AForm(std::string const& name, int grade_sign, int grade_exec);

	private:
		AForm();

	protected:
		AForm(AForm const& form);
		AForm&	operator=(AForm const& form);

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
		virtual void	execute(class Bureaucrat & bur) const = 0;

	public:
		virtual void	print(std::ostream & os) const;

	public:
		class FormAlreadySignedException : public std::exception
		{
			virtual char const *	what() const throw();
		};
		class FormNotYetSignedException : public std::exception
		{
			virtual char const *	what() const throw();
		};
};

std::ostream&	operator<<(std::ostream &os, AForm const& form);

#endif // AFORM_HPP
