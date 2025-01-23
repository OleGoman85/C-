/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:42:51 by ogoman            #+#    #+#             */
/*   Updated: 2025/01/20 12:45:54 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>   // Used for console input and output

/**
 * @brief Main function to process the input file with Bitcoin data.
 * 
 * @param argc Number of command-line arguments.
 * @param argv Array of command-line arguments.
 * @return int Exit code: 0 for success, 1 for error.
 */
int main(int argc, char* argv[])
{
    if (argc != 2) 
    {
        std::cerr << "Usage: ./btc <input_file>" << std::endl;
        return 1;
    }

    try {
        BitcoinExchange btc("./data.csv");
        btc.processInputFile(argv[1]);
    } 
    catch (const std::exception& e) 
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}


/*
create input.txt

date | value
2011-01-03 | 3
2011-01-03 | 2
2011-01-03 | 1
2011-01-03 | 1.2
2011-01-09 | 1
2012-01-11 | -1
2001-42-42
2012-01-11 | 1
2012-01-11 | 2147483648

./btc input.txt
*/


//! Container <Map>


//! std::ifstream

/*
std::ifstream (input file stream) is a C++ class used to read data from files. 
It is part of the <fstream> library and provides functionality for working with file input at a high level of abstraction.

Key Features:

File Reading: Allows reading from files in a convenient manner using stream operations.
File Descriptor Management: Internally handles the file descriptor and ensures proper opening and closing of files.
Error and State Management: Tracks the state of the file (e.g., end of file, errors) and provides methods to check these states (file.eof(), file.fail()).
Stream Compatibility: Works with standard stream methods like std::getline and operators like >> to extract data.

#include <fstream>
#include <iostream>

int main() {
    std::ifstream file("data.txt");
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
    } else {
        std::cerr << "Error: Could not open the file." << std::endl;
    }
    return 0;
}
*/



//! std::istringstream


/*
std::istringstream (input string stream) is a C++ class used to parse or read data from a string as if it were a stream. It is part of the <sstream> library and provides functionality for working with strings as input sources.

Key Features:

String Parsing: Allows treating a string as a stream for extracting data using operators like >> or methods like std::getline.
Initialization with Strings: Can be initialized with a string at construction or assigned later.
Stream-like Behavior: Provides functionality similar to std::ifstream but operates on in-memory strings instead of files.

#include <sstream>
#include <iostream>

int main() {
    std::string data = "123 456 789";
    std::istringstream stream(data);

    int num1, num2, num3;
    stream >> num1 >> num2 >> num3;

    std::cout << "Parsed numbers: " << num1 << ", " << num2 << ", " << num3 << std::endl;

    return 0;
}
*/
