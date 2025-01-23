/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:28:28 by ogoman            #+#    #+#             */
/*   Updated: 2024/11/26 08:13:35 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    _type = "WrongCat 🐾";
    std::cout << _type << " created" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
    std::cout << "WrongCat copied" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
    if (this != &other)
    {
        WrongAnimal::operator=(other);
    }
    std::cout << "WrongCat assigned" << std::endl;
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat 🐾 destroyed" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << ": 🐾 Wrong Meow!" << std::endl;
}
