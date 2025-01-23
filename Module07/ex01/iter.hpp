/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 07:13:40 by ogoman            #+#    #+#             */
/*   Updated: 2024/12/16 09:09:09 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef> // Add this to include size_t

template <typename T>
void iter(T *array, size_t length, void (*func)(T const &))
{
    if (!array) return;
    for (size_t i = 0; i < length; ++i)
    {
        func(array[i]);
    }
}

#endif
