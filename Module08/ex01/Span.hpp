/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:32:56 by ogoman            #+#    #+#             */
/*   Updated: 2025/01/06 10:07:35 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iostream>

class Span
{
private:
	unsigned int _N;		   // Max amount of numbers
	std::vector<int> _numbers; // Vector for storing numbers

public:
	Span();								
	Span(unsigned int N);				
	Span(const Span &other);			
	Span &operator=(const Span &other);
	~Span();						

	void addNumber(int number);
	template <typename Iterator>
	void addRange(Iterator begin, Iterator end);
	int shortestSpan();
	int longestSpan();

	void printNumbers() const;
};

template <typename Iterator>
void Span::addRange(Iterator begin, Iterator end)
{
	if (std::distance(begin, end) > static_cast<int>(_N - _numbers.size()))
		throw std::runtime_error("Range exceeds available space in Span.");
	_numbers.insert(_numbers.end(), begin, end);
}

#endif


/*
std::distance 
calculates the number of elements between two iterators in a range

std::insert 
adds elements from the specified range to the container.
*/


// std::vector<int> array = {2,3,4,5};
// sp2.addRange(array.begin(), array.end());


// template <typename Iterator>
// void Span::addRange(std::vector<int> begin, std::vector<int> end)

