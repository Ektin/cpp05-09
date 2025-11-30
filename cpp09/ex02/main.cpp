/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EktinOpUrims <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:33:52 by EktinOpUrims      #+#    #+#             */
/*   Updated: 2025/03/28 07:12:22 by EktinOpUrims     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>

int	main(int argc,  char * argv[])
{
	std::vector<std::string> myvector(&argv[1], &argv[argc]);
	std::vector<std::string>::const_iterator	it;
	std::cout << std::endl;
	PmergeMe	pmerge(myvector);
	
	if (pmerge.get_is_input_ok())
	{
		pmerge.sort_vector();
		pmerge.sort_list();
	}
	return (0);
}
