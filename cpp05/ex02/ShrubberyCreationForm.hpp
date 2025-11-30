/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EktinOpUrims <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:59:53 by EktinOpUrims      #+#    #+#             */
/*   Updated: 2024/10/17 21:22:10 by EktinOpUrims     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	_target;

	public:
		std::string const&	getTarget() const;

	public:
		virtual ~ShrubberyCreationForm();
		ShrubberyCreationForm(std::string const& target);

	private:
		ShrubberyCreationForm();
		ShrubberyCreationForm&	operator=(ShrubberyCreationForm const& form);
		ShrubberyCreationForm(ShrubberyCreationForm const& form);

	public:
		void	beSigned(Bureaucrat & bur);
		void	execute(Bureaucrat & bur) const;

	private:
		void	do_stuff() const;

	public:
		void	print(std::ostream & os) const;

};

#endif // SHRUBBERYCREATIONFORM_HPP
