/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 09:38:15 by ogoman            #+#    #+#             */
/*   Updated: 2024/12/10 09:47:14 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"
#include <exception> // std::bad_cast

void identify(Base* base)
{
    if (dynamic_cast<A*>(base)) //return nullptr or ptr
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(base))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(base))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

void identify(Base& base)
{
    try
    {
        (void)dynamic_cast<A&>(base);
        std::cout << "A" << std::endl;
        return;
    }
    catch (std::bad_cast&) {}

    try
    {
        (void)dynamic_cast<B&>(base);
        std::cout << "B" << std::endl;
        return;
    }
    catch (std::bad_cast&) {}

    try
    {
        (void)dynamic_cast<C&>(base);
        std::cout << "C" << std::endl;
        return; 
    }
    catch (std::bad_cast&) {}

    // If the object does not belong to any of the known classes
    std::cout << "Error, wrong class D" << std::endl;
}

/*
DYNAMIC_CAST is a cast operator in C++ that is used to safely cast pointers or references
 to objects in a class hierarchy that supports polymorphism (i.e. classes that have at least one virtual function).
*/


