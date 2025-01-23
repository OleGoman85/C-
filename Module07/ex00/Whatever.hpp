/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:25:08 by ogoman            #+#    #+#             */
/*   Updated: 2024/12/16 09:08:58 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

// Swap function: swaps the values of two arguments
template<typename T>
void swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

// Min function: returns the smallest of the two arguments
template<typename T>
const T &min(const T &a, const T &b) {
    return (a < b) ? a : b;
}

// Max function: returns the largest of the two arguments
template<typename T>
const T &max(const T &a, const T &b) {
    return (a > b) ? a : b;
}

#endif // WHATEVER_HPP


/*
TEMPLATE-tells the compiler that the following function or class is a template, meaning it can be used with different data types (int, float, std::string).

T - is the type, not a variable. T = type

TYPENAME - is used to specify the type parameter in the template.
*/