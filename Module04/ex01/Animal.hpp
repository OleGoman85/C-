/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:49:27 by ogoman            #+#    #+#             */
/*   Updated: 2024/11/26 08:58:34 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal
{
	protected:
		std::string _type;
	public:
		Animal();
		Animal(const Animal &obj);
		Animal &operator=(const Animal &rhs);
		virtual ~Animal() = default;

		virtual void makeSound() const;
		virtual std::string getType() const;
};

#endif // ANIMAL_HPP