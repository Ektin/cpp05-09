/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EktinOpUrims <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:59:53 by EktinOpUrims      #+#    #+#             */
/*   Updated: 2024/10/17 21:38:23 by EktinOpUrims     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string	_target;

	public:
		std::string const&	getTarget() const;

	public:
		virtual ~PresidentialPardonForm();
		PresidentialPardonForm(std::string const& target);

	private:
		PresidentialPardonForm();
		PresidentialPardonForm&	operator=(PresidentialPardonForm const& form);
		PresidentialPardonForm(PresidentialPardonForm const& form);

	public:
		void	beSigned(Bureaucrat & bur);
		void	execute(Bureaucrat & bur) const;

	private:
		void	do_stuff() const;

	public:
		void	print(std::ostream & os) const;

};

#endif // PRESIDENTIALPARDONFORM_HPP
