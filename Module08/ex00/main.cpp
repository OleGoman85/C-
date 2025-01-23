/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:03:04 by ogoman            #+#    #+#             */
/*   Updated: 2025/01/06 10:10:55 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "Easyfind.hpp"

int main()
{
    try {
        std::vector<int> container = {1, 2, 3, 4, 5};
        auto it = easyfind(container, 3);
        // std::vector<int>::iterator it = easyfind(v, 3); //! same
        std::cout << "Found value: " << *it << std::endl;
        
        // Test with a value not in the vector
        it = easyfind(container, 10);  // This will throw an exception
        std::cout << "Found value: " << *it << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
