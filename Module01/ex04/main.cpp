/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:09:30 by ogoman            #+#    #+#             */
/*   Updated: 2024/10/29 09:05:56 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> //std::cin, std::cout, std::cerr
#include <fstream>	//std::ifstream reading, std::ofstream writing
#include <string>	//std::string


// Function to replace occurrences of a string in a file
void replaceInFile(const std::string &filename, const std::string &s1, const std::string &s2)
{
	std::ifstream inFile(filename); // Open the file for reading
	if (!inFile)
	{
		std::cerr << "Error: Cannot open file " << filename << std::endl;
		return;
	}

	std::string newFile = filename + ".replace"; // Create a new filename for the output
	std::ofstream outFile(newFile);				 // Open the new file for writing (create if it doesn't exist)
	if (!outFile)
	{
		std::cerr << "Error: Cannot create file " << newFile << std::endl;
		inFile.close();
		return;
	}

	std::string line;
	while (std::getline(inFile, line)) // Read each line from the input file
	{
		std::size_t pos = 0;									// Start position for searching
		while ((pos = line.find(s1, pos)) != std::string::npos) // Search for occurrences of s1
		{
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos += s2.length();
		}
		outFile << line << std::endl; // Write the modified line to the output file
	}

	inFile.close();	 // Close the input file
	outFile.close(); // Close the output file
}


int main(int argc, char *argv[])
{
	if (argc != 4) // Check if the correct number of arguments is provided
	{
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl; 
		return 1;
	}

	std::string filename = argv[1]; 
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (s1.empty() || s2.empty()) // Check if the replacement strings are empty
	{
		std::cerr << "Error: Strings must not be empty" << std::endl;
		return 1;
	}

	replaceInFile(filename, s1, s2);

	return 0;
}

/**
 * *This program replaces occurrences of a specified substring in a file with a new substring and writes the results to a new file.
 * ./replace example_text Alex Maria
 */