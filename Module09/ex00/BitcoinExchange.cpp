/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:43:05 by ogoman            #+#    #+#             */
/*   Updated: 2025/01/20 12:51:17 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>             // Used for file input/output operations
#include <sstream>             // Used for parsing strings with streams
#include <stdexcept>           // Provides standard exception handling classes
#include <iomanip>             // Used for formatted output (if needed)
#include <iostream>            // Used for console input and output

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const std::string& dbFile) { loadDatabase(dbFile); }
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _exchangeRates(other._exchangeRates) {}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other) {
        _exchangeRates = other._exchangeRates;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}


/**
 * @brief Loads the database file and populates the map with exchange rates.
 * 
 * @param dbFile Path to the database file in CSV format.
 * @throws std::runtime_error if the file cannot be opened.
 */
void BitcoinExchange::loadDatabase(const std::string& dbFile)
{
    std::ifstream file(dbFile); // Open the database file
    if (!file.is_open()) {
        throw std::runtime_error("Error: could not open database file.");
    }

    std::string line;
    while (std::getline(file, line)) // Read the file line by line
    {
        std::istringstream stream(line);
        std::string date;
        float rate;

        // Parse the date and exchange rate
        if (std::getline(stream, date, ',') && stream >> rate) 
        {
            if (isValidDate(date)) {
                _exchangeRates[date] = rate;
            }
        }
    }
}


/**
 * @brief Processes the input file and calculates Bitcoin values using exchange rates.
 * 
 * @param inputFile Path to the input file.
 */

void BitcoinExchange::processInputFile(const std::string& inputFile) 
{
    std::ifstream file(inputFile); // Opens the input file for reading
    if (!file.is_open()) 
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    bool isFirstLine = true;
    while (std::getline(file, line)) 
    {
        if (isFirstLine) // Skips the first line (header)
        {
            isFirstLine = false;
            continue;
        }

        std::istringstream stream(line); // Parses the line into a string stream
        std::string date;
        std::string valueStr;

        // Extracts the date and value from the current line
        if (std::getline(stream, date, '|') && std::getline(stream, valueStr)) 
        {
            date.erase(date.find_last_not_of(" \t\r\n") + 1); // Trims trailing spaces from the date
            valueStr.erase(0, valueStr.find_first_not_of(" \t\r\n")); // Trims leading spaces from the value

            if (!isValidDate(date))
            {
                std::cerr << "Error: bad input => " << line << std::endl;
                continue;
            }

            if (!isValidFloat(valueStr))
            {
                std::cerr << "Error: bad input => " << line << std::endl;
                continue;
            }

            float value = std::stof(valueStr);
            if (!isValidValue(value)) { // Validates the value range
                continue;
            }

            float rate = getExchangeRate(date); // Gets the exchange rate for the date
            if (rate == 0.0f) 
            {
                std::cerr << "Error: date out of range => " << date << std::endl;
                continue;
            }

            std::cout << date << " => " << value << " = " << value * rate << std::endl;
        }
        else
        {
            std::cerr << "Error: bad input => " << line << std::endl;
        }
    }
}


/**
 * @brief Retrieves the exchange rate for a specific date or the nearest earlier date.
 * 
 * @param date The date to find the exchange rate for.
 * @return float The exchange rate, or 0.0 if the date is out of range.
 */

float BitcoinExchange::getExchangeRate(const std::string& date) const
{
    auto it = _exchangeRates.lower_bound(date); // Finds the nearest key not less than the date
    if (it == _exchangeRates.end() || it->first != date) 
    {
        if (it == _exchangeRates.begin()) // If the date is before all keys in the map
        {
            return 0.0f;
        }
        --it;
    }
    return it->second;
}


/**
 * @brief Validates if a date is in the correct format and range.
 * 
 * @param date The date to validate.
 * @return true If the date is valid.
 * @return false If the date is invalid.
 */

bool BitcoinExchange::isValidDate(const std::string& date) const 
{
    if (date.size() != 10 || date[4] != '-' || date[7] != '-') return false;

    try {
        int year = std::stoi(date.substr(0, 4));
        int month = std::stoi(date.substr(5, 2));
        int day = std::stoi(date.substr(8, 2));

        if (year < 2009 || year > 2022) return false;
        if (month < 1 || month > 12) return false;

        static const int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) {
            if (day > 29) return false;
        } else if (day > daysInMonth[month - 1]) {
            return false; 
        }
    } catch (...) {
        return false;
    }

    return true;
}


/**
 * @brief Validates if a string represents a valid float.
 * 
 * @param value The string to validate.
 * @return true If the string is a valid float.
 * @return false If the string is not a valid float.
 */

bool BitcoinExchange::isValidFloat(const std::string& value) const 
{
    try {
        std::stof(value);
        return true;
    } catch (...) {
        return false;
    }
}


/**
 * @brief Validates if a float value is within the allowed range.
 * 
 * @param value The value to validate.
 * @return true If the value is valid.
 * @return false If the value is invalid.
 */

bool BitcoinExchange::isValidValue(float value) const 
{
    if (value <= 0) 
    {
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }
    if (value > 100000) 
    {
        std::cerr << "Error: too large a number." << std::endl;
        return false;
    }
    return true;
}



/*
//!std::stoi 
Converts a substring of a std::string into an int
int number = std::stoi("23423423dfsdff");
std::cout << number << std::endl;

output: 23423423

*/


/*
//!substr
Returns a substring from a given string.
substr(start, length)
start - from index (2)
length - amount of characters (4)

int number = std::stoi(std::string("123456789242dfsdff").substr(2,4));
std::cout << number << std::endl;

output: 3456

*/


/*
//!lower_bound
auto it = _exchangeRates.lower_bound(date)
lower_bound to find the nearest key that is not less than the specified key.
*/