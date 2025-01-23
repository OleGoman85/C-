/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:07:00 by ogoman            #+#    #+#             */
/*   Updated: 2024/12/09 09:43:22 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"
#include <cstdint> // For uintptr_t

class Serializer
{
	public:
		~Serializer();
		Serializer() = delete;
		Serializer(const Serializer &obj) = delete;
		Serializer &operator=(const Serializer &rhs) = delete;
		
		static uintptr_t serialize(Data *ptr);	 // Serialize pointer to uintptr_t
		static Data *deserialize(uintptr_t raw); // Deserialize uintptr_t back to pointer
};


#endif
