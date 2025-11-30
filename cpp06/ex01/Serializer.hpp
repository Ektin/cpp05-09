/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EktinOpUrims <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 15:07:46 by EktinOpUrims      #+#    #+#             */
/*   Updated: 2025/01/25 18:54:46 by EktinOpUrims     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include "Data.hpp"
//# include <cstdint>
//# include <stdint.h>

typedef long unsigned int uintptr_t;

class Serializer
{
	private:
		Serializer();
		~Serializer();
		Serializer(Serializer const & src);
		Serializer & operator=(Serializer const & src);

	public:
		static	uintptr_t	serialize(Data* ptr);
		static	Data*	deserialize(uintptr_t raw);
};

#endif // SERIALIZER_HPP
