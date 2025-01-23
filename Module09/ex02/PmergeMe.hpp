/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 07:37:11 by ogoman            #+#    #+#             */
/*   Updated: 2025/01/21 11:25:29 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>     // For std::vector
#include <deque>      // For std::deque
#include <string>     // For std::string
#include <utility>    // For std::pair

/**
 * @brief A class to demonstrate the Ford-Johnson merge-insertion sorting algorithm.
 * 
 * This class processes command-line arguments, sorts them using a custom sorting algorithm
 * implemented for both std::vector and std::deque, and measures the execution time for sorting.
 */
class PmergeMe
{
    public:
        /**
         * @brief Constructor to initialize the class with command-line arguments.
         * @param argc Number of arguments.
         * @param argv Array of argument strings.
         */
        PmergeMe(int argc, char* argv[]);
        ~PmergeMe();

        /**
         * @brief Deleted copy constructor to prevent copying.
         */
        PmergeMe (const PmergeMe &other) = delete;

        /**
         * @brief Deleted assignment operator to prevent copying.
         */
        PmergeMe &operator=(const PmergeMe &other) = delete;

        /**
         * @brief Sorts the data stored in the class and displays the results.
         * 
         * This function measures the time taken to sort the data stored in
         * std::vector and std::deque, and prints the sorted results.
         */
        void sortAndDisplay();
        
    private:
        std::vector<int> vec; ///< Container to store input numbers as a vector.
        std::deque<int> deq; ///< Container to store input numbers as a deque.

        /**
         * @brief Parses and validates command-line arguments.
         * 
         * Converts arguments to integers and stores them in the `vec` and `deq` containers.
         * Throws exceptions if invalid arguments are encountered.
         * 
         * @param argc Number of arguments.
         * @param argv Array of argument strings.
         */
        void parseArguments(int argc, char* argv[]);

        /**
         * @brief Sorts a std::vector using the merge-insertion sort algorithm.
         * 
         * @param data A reference to the vector of integers to sort.
         */
        void mergeInsertionSortVector(std::vector<int>& data);

        /**
         * @brief Sorts a std::deque using the merge-insertion sort algorithm.
         * 
         * @param data A reference to the deque of integers to sort.
         */
        void mergeInsertionSortDeque(std::deque<int>& data);

        /**
         * @brief Prints a std::vector with a given prefix.
         * 
         * @param prefix A string to print before the vector.
         * @param data The vector to print.
         */
        void printSequence(const std::string& prefix, const std::vector<int>& data) const;

        /**
         * @brief Prints a std::deque with a given prefix.
         * 
         * @param prefix A string to print before the deque.
         * @param data The deque to print.
         */
        void printSequence(const std::string& prefix, const std::deque<int>& data) const;
};

#endif // PMERGEME_HPP
