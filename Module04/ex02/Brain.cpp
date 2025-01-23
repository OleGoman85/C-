/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:48:38 by ogoman            #+#    #+#             */
/*   Updated: 2024/11/19 07:19:28 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructed" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructed" << std::endl;
}

Brain::Brain(const Brain &other)
{
	std::cout << "Brain copied" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		ideas[i] = other.ideas[i];
	}
}

Brain &Brain::operator=(const Brain &other)
{
	std::cout << "Brain assignment" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
		{
			ideas[i] = other.ideas[i];
		}
	}
	return *this;
}

//* IDEAS *//

void Brain::addIdea(const std::string &idea)
{
	if (ideaCount < 100)
	{ 
		ideas[ideaCount++] = idea;
	}
}

void Brain::printIdeas() const
{
	for (int i = 0; i < ideaCount; ++i)
	{
		std::cout << ideas[i] << std::endl;
	}
}