/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:32:43 by ogoman            #+#    #+#             */
/*   Updated: 2025/01/06 10:32:08 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>

int main()
{
	try
	{
		std::cout << "======= Creating Span sp with capacity 5 =======\n" << std::endl;
		Span sp(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		
		sp.printNumbers();
		std::cout << "Shortest span in sp: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span in sp: " << sp.longestSpan() << std::endl;
		
		std::cout << "\n======= Creating Span sp2 with capacity 10 =======" << std::endl;
		Span sp2(10);
		sp2.addNumber(10);
		sp2.addNumber(20);

		std::cout << "\nBefore addRange:" << std::endl;
		sp2.printNumbers();

		std::vector<int> extra_numbers = {42, 55, 78};
		std::cout << "Adding range {42, 55, 78} to sp2" << std::endl;
		sp2.addRange(extra_numbers.begin(), extra_numbers.end());

		std::cout << "\nAfter addRange:" << std::endl;
		sp2.printNumbers();
		
		std::cout << "\nShortest span in sp2: " << sp2.shortestSpan() << std::endl;
		std::cout << "Longest span in sp2: " << sp2.longestSpan() << std::endl;

		std::cout << "\n========================================" << std::endl;
		
		// Test Copy Constractor
		std::cout << "\nTesting copy constructor:" << std::endl;
		Span sp3(sp2);
		sp3.printNumbers();

		// Test Assignment operator
		std::cout << "\nTesting assignment operator:" << std::endl;
		Span sp4;
		sp4 = sp;
		sp4.printNumbers();
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}

/*

				std::max / std::min  //!
	Returns the maximum or minimum of two values.
	Defined in the <algorithm> or <utility> header file.
	Works only with two arguments (by default, the < operator is used for comparison).

				std::max_element / std::min_element  //!
	Returns an iterator to the maximum or minimum element in the range [begin, end).
	Defined in the <algorithm> header file.
	Works with any container or range (includes more than one element).

				std::minmax_element //!
	Is used to find both the minimum and maximum element in a range. 
	It returns two iterators: the first one points to the minimum element, and the second one points to the maximum element.

	std::vector<int> == auto //!
*/
