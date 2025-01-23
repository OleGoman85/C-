/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:51:15 by ogoman            #+#    #+#             */
/*   Updated: 2024/11/19 07:19:39 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain *brain;

	public:
		Cat();
		~Cat();
		Cat(const Cat &other);
		Cat &operator=(const Cat &other);

		std::string getType() const override;

		void makeSound() const override;

		//* IDEAS *//
				
		void addIdea(const std::string &idea);
		void printIdeas() const;

};

#endif // CAT_HPP
