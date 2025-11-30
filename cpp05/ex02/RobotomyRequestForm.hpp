/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EktinOpUrims <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:59:53 by EktinOpUrims      #+#    #+#             */
/*   Updated: 2024/10/17 21:26:11 by EktinOpUrims     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string	_target;

	public:
		std::string const&	getTarget() const;

	public:
		virtual ~RobotomyRequestForm();
		RobotomyRequestForm(std::string const& target);

	private:
		RobotomyRequestForm();
		RobotomyRequestForm&	operator=(RobotomyRequestForm const& form);
		RobotomyRequestForm(RobotomyRequestForm const& form);

	public:
		void	beSigned(Bureaucrat & bur);
		void	execute(Bureaucrat & bur) const;

	private:
		void	do_stuff() const;

	public:
		void	print(std::ostream & os) const;

};

#endif // ROBOTOMYREQUESTFORM_HPP
