/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:42:57 by ogoman            #+#    #+#             */
/*   Updated: 2025/01/20 09:32:06 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>

class BitcoinExchange
{
    private:
        std::map<std::string, float> _exchangeRates;

        void loadDatabase(const std::string& dbFile);
        float getExchangeRate(const std::string& date) const;
        bool isValidDate(const std::string& date) const;
        bool isValidFloat(const std::string& value) const;
        bool isValidValue(float value) const;
        
    public:
        // Default Constructor
        BitcoinExchange();

        // Constructor with database file
        explicit BitcoinExchange(const std::string& dbFile);

        // Copy Constructor
        BitcoinExchange(const BitcoinExchange& other);

        // Copy Assignment Operator
        BitcoinExchange& operator=(const BitcoinExchange& other);

        // Destructor
        ~BitcoinExchange();

        // Public Methods
        void processInputFile(const std::string& inputFile);

    };

#endif
