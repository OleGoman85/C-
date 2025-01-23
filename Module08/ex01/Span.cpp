/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:32:52 by ogoman            #+#    #+#             */
/*   Updated: 2025/01/06 10:27:22 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <limits>

Span::Span() : _N(0) {}

Span::Span(unsigned int N) : _N(N) {}

Span::Span(const Span &other) : _N(other._N), _numbers(other._numbers) {}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_N = other._N;
		_numbers = other._numbers;
	}
	return *this;
}

Span::~Span() {}

// Add one number
void Span::addNumber(int number)
{
	if (_numbers.size() >= _N)
		throw std::runtime_error("Span is already full.");
	_numbers.push_back(number);
}

// Finding the shortest interval
int Span::shortestSpan()
{
	if (_numbers.size() < 2)
		throw std::runtime_error("Not enough elements to calculate span.");
	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());
	int min_span = std::numeric_limits<int>::max();
	for (size_t i = 1; i < sorted.size(); i++)
	{
		int diff = sorted[i] - sorted[i - 1];
		if (diff < min_span)
			min_span = diff;
	}
	return min_span;
}

// Finding the largest interval
int Span::longestSpan()
{
	if (_numbers.size() < 2)
		throw std::runtime_error("Not enough elements to calculate span.");
	auto max_span = std::minmax_element(_numbers.begin(), _numbers.end());
	return *max_span.second - *max_span.first;
}

// Output numbers
void Span::printNumbers() const
{
	std::cout << "Numbers in Span: ";
	for (size_t i = 0; i < _numbers.size(); ++i)
	{
		std::cout << _numbers[i] << " ";
	}
	std::cout << std::endl;
}


/*
				std::minmax_element //!
	Is used to find both the minimum and maximum element in a range. 
	It returns two iterators: the first one points to the minimum element, and the second one points to the maximum element.
*/