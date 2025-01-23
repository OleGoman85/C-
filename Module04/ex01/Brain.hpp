/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:48:21 by ogoman            #+#    #+#             */
/*   Updated: 2024/11/19 07:18:12 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class Brain
{
private:
	std::string ideas[100];
	int ideaCount = 0; // amount of ideas //* IDEAS *//

public:
	Brain();
	~Brain();
	Brain(const Brain &other);
	Brain &operator=(const Brain &other);

	//* IDEAS *//
	void addIdea(const std::string &idea);
	void printIdeas() const;
};

#endif // BRAIN_HPP