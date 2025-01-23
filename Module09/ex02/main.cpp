/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 07:38:19 by ogoman            #+#    #+#             */
/*   Updated: 2025/01/21 11:29:13 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>     // For input and output operations

/**
 * @brief Main function to execute the program.
 * @param argc Number of command-line arguments.
 * @param argv Array of command-line argument strings.
 * @return Program exit status.
 */
int main(int argc, char* argv[]) {
    try {
        PmergeMe pm(argc, argv);
        pm.sortAndDisplay();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    // Return 0 to indicate successful execution.
    return 0;
}


// ./PmergeMe $(shuf -i 1-100000 -n 3000)
// ./PmergeMe `shuf -i 1-1000 -n 3000 | tr "\n" " " `
// ./PmergeMe `shuf -i 1-1000 -n 3000 | tr "\n" " " `




//!std::lower_bound:
/*
std::lower_bound is an algorithm provided in the <algorithm> header. 
It is used to find the position in a sorted range where a given element can be inserted while maintaining the order of elements.

std::lower_bound(begin, end, value);

begin — an iterator pointing to the beginning of the range.
end — an iterator pointing to the end of the range.
value — the value for which the position is being sought.
*/
