/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 11:01:21 by ogoman            #+#    #+#             */
/*   Updated: 2025/01/21 06:28:08 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream> // Used for standard input and output operations

/**
 * @brief Main function to evaluate a reverse Polish notation (RPN) expression.
 * 
 * @param argc The number of command-line arguments.
 * @param argv The array of command-line arguments.
 * @return int Exit code: 0 for success, 1 for errors.
 */
int main(int argc, char* argv[]) 
{
    if (argc != 2) 
    {
        std::cerr << "Usage: ./RPN <expression>" << std::endl;
        return 1;
    }

    try {
        int result = RPN::evaluate(argv[1]); // Evaluate the RPN expression
        std::cout << result << std::endl;
    }
    catch (const std::exception& e) 
    {
        std::cerr << e.what() << std::endl; // Handle exceptions by printing the error message
        return 1;
    }

    return 0;
}


//./RPN "2 3 + 3 - 5 + 9 +"

//! Container <Stack>