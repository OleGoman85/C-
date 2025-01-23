/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:03:26 by ogoman            #+#    #+#             */
/*   Updated: 2025/01/06 10:10:48 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iterator>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T& container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end()) {
        throw std::runtime_error("Element not found in container");
    }
    return it;
}

#endif // EASYFIND_HPP



/*
instead of FIND

for (auto it = container.begin(); it != container.end(); ++it) {
    if (*it == value) {
        return it;
    }
}
throw std::runtime_error("Element not found in container");



std::vector<int>::iterator == auto //!

*/