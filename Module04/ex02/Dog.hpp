/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:50:18 by ogoman            #+#    #+#             */
/*   Updated: 2024/11/19 07:19:45 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain *brain;

	public:
		Dog();
		~Dog();
		Dog(const Dog &other);
		Dog &operator=(const Dog &other);

		std::string getType() const override;

		void makeSound() const override;

		//* IDEAS *//
		
		void addIdea(const std::string &idea);
		void printIdeas() const;
};

#endif // DOG_HPP