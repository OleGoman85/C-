/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 09:10:55 by ogoman            #+#    #+#             */
/*   Updated: 2025/01/21 11:51:09 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>   // For input and output
#include <sstream>    // For string streams
#include <stdexcept>  // For exception handling
#include <algorithm>  // For algorithms like std::lower_bound
#include <limits>     // For numeric limits
#include <chrono>     // For measuring time
#include <iomanip>    // For formatting output

/**
 * @brief Constructs PmergeMe object and parses command-line arguments.
 * @param ac Number of arguments.
 * @param av Array of argument strings.
 */
PmergeMe::PmergeMe(int ac, char* av[]) {
    parseArguments(ac, av);
}

/**
 * @brief Destructor for PmergeMe class.
 */
PmergeMe::~PmergeMe() {}

/**
 * @brief Parses command-line arguments and validates them.
 * @param ac Number of arguments.
 * @param av Array of argument strings.
 */
void PmergeMe::parseArguments(int ac, char* av[]) {
    if (ac < 2) {
        throw std::invalid_argument("Error: No input provided.");
    }

    for (int i = 1; i < ac; ++i) {
        std::string number(av[i]);

        // Validate that the argument is a positive integer
        if (number.empty() || !std::all_of(number.begin(), number.end(), [](unsigned char c) { return std::isdigit(c); })) {
            std::ostringstream oss;
            oss << "Error: Argument " << i << " ('" << number << "') is not a valid positive integer.";
            throw std::invalid_argument(oss.str());
        }

        try {
            long num_long = std::stol(number);

            // Ensure the number is within the range of `int`
            if (num_long <= 0 || num_long > std::numeric_limits<int>::max()) {
                std::ostringstream oss;
                oss << "Error: Argument " << i << " ('" << number << "') is out of range.";
                throw std::invalid_argument(oss.str());
            }

            int num = static_cast<int>(num_long);

            // Store the number in both containers for sorting
            vec.push_back(num);
            deq.push_back(num);
        }
        catch (const std::out_of_range&) {
            std::ostringstream oss;
            oss << "Error: Argument " << i << " ('" << number << "') is out of range.";
            throw std::invalid_argument(oss.str());
        }
        catch (const std::invalid_argument&) {
            std::ostringstream oss;
            oss << "Error: Argument " << i << " ('" << number << "') is not a valid number.";
            throw std::invalid_argument(oss.str());
        }
    }
}

/**
 * @brief Sorts a vector using the merge-insertion sort algorithm.
 * @param data Vector of integers to sort.
 */
void PmergeMe::mergeInsertionSortVector(std::vector<int>& data) {
    if (data.size() <= 1)
        return;

    // Step 1: Divide into pairs
    std::vector<std::pair<int, int>> pairs;
    for (size_t i = 0; i + 1 < data.size(); i += 2) {
        if (data[i] > data[i + 1])
            pairs.emplace_back(data[i + 1], data[i]);
        else
            pairs.emplace_back(data[i], data[i + 1]);
    }
    if (data.size() % 2 != 0) {
        pairs.emplace_back(data.back(), -1); // Add a "fake" pair for the last element
    }

    // Step 2: Sort leaders (second elements of pairs)
    std::vector<int> leaders;
    for (const auto& p : pairs) {
        if (p.second != -1) { // Exclude fake leaders
            leaders.push_back(p.second);
        }
    }
    mergeInsertionSortVector(leaders);

    // Step 3: Merge pairs into the sorted result
    std::vector<int> sortedData = leaders;
    for (const auto& p : pairs) {
        if (p.first != -1) { // Exclude fake elements
            auto position = std::lower_bound(sortedData.begin(), sortedData.end(), p.first);
            sortedData.insert(position, p.first);
        }
    }

    data = std::move(sortedData); // Replace the original vector with the sorted one
}

/**
 * @brief Sorts a deque using the merge-insertion sort algorithm.
 * @param data Deque of integers to sort.
 */
void PmergeMe::mergeInsertionSortDeque(std::deque<int>& data) {
    if (data.size() <= 1)
        return;

    // Step 1: Divide into pairs
    std::deque<std::pair<int, int>> pairs;
    for (size_t i = 0; i + 1 < data.size(); i += 2) {
        if (data[i] > data[i + 1])
            pairs.emplace_back(data[i + 1], data[i]);
        else
            pairs.emplace_back(data[i], data[i + 1]);
    }
    if (data.size() % 2 != 0) {
        pairs.emplace_back(data.back(), -1); // Add a "fake" pair for the last element
    }

    // Step 2: Sort leaders (second elements of pairs)
    std::deque<int> leaders;
    for (const auto& p : pairs) {
        if (p.second != -1) { // Exclude fake leaders
            leaders.push_back(p.second);
        }
    }
    mergeInsertionSortDeque(leaders);

    // Step 3: Merge pairs into the sorted result
    std::deque<int> sortedData = leaders;
    for (const auto& p : pairs) {
        if (p.first != -1) { // Exclude fake elements
            auto position = std::lower_bound(sortedData.begin(), sortedData.end(), p.first);
            sortedData.insert(position, p.first);
        }
    }

    data = std::move(sortedData); // Replace the original deque with the sorted one
}

/**
 * @brief Prints a vector with a prefix.
 * @param prefix Prefix to print before the vector.
 * @param data Vector to print.
 */
void PmergeMe::printSequence(const std::string& prefix, const std::vector<int>& data) const {
    std::cout << prefix;
    for (size_t i = 0; i < data.size(); ++i) {
        std::cout << data[i];
        if (i != data.size() - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
}

/**
 * @brief Prints a deque with a prefix.
 * @param prefix Prefix to print before the deque.
 * @param data Deque to print.
 */
void PmergeMe::printSequence(const std::string& prefix, const std::deque<int>& data) const {
    std::cout << prefix;
    for (size_t i = 0; i < data.size(); ++i) {
        std::cout << data[i];
        if (i != data.size() - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
}

/**
 * @brief Sorts and displays the data, measuring execution time for both vector and deque.
 */
void PmergeMe::sortAndDisplay() {
    // Print initial data
    if (vec.size() > 100) {
        std::cout << "Before: ";
        for (size_t i = 0; i < 100; ++i) {
            std::cout << vec[i] << " ";
        }
        std::cout << "..." << std::endl;
    }
    else {
        printSequence("Before: ", vec);
    }
    std::cout << "\n";

    // Sort the vector and measure time
    std::vector<int> vecCopy = vec;
    auto startVec = std::chrono::high_resolution_clock::now();
    mergeInsertionSortVector(vecCopy);
    auto endVec = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> durationVec = endVec - startVec;

    // Sort the deque and measure time
    std::deque<int> deqCopy = deq;
    auto startDeq = std::chrono::high_resolution_clock::now();
    mergeInsertionSortDeque(deqCopy);
    auto endDeq = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> durationDeq = endDeq - startDeq;

    // Print results
    std::cout << "========================================" << std::endl;
    std::cout << "\n";

    if (vecCopy.size() > 100) {
        std::cout << "After: ";
        for (size_t i = 0; i < 100; ++i) {
            std::cout << vecCopy[i] << " ";
        }
        std::cout << "..." << std::endl;
    }
    else {
        printSequence("After: ", vecCopy);
    }

    std::cout << "========================================" << std::endl;
    
    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : "
              << std::fixed << std::setprecision(6) << durationVec.count() << " us" << std::endl;

    std::cout << "Time to process a range of " << deq.size() << " elements with std::deque : "
              << std::fixed << std::setprecision(6) << durationDeq.count() << " us" << std::endl;
}
