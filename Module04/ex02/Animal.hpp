/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:49:27 by ogoman            #+#    #+#             */
/*   Updated: 2024/11/26 09:03:28 by ogoman           ###   ########.fr       */
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

		virtual ~Animal() = default;			 // Automatically generates a default destructor, as no custom destructor logic is needed.
		virtual void makeSound() const = 0;		 // Pure virtual function to enforce implementation in derived classes; represents the animal's sound.
		virtual std::string getType() const;
};

#endif // ANIMAL_HPP
