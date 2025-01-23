/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 09:48:48 by ogoman            #+#    #+#             */
/*   Updated: 2025/01/06 10:12:34 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		MutantStack(const MutantStack &other);
		MutantStack &operator=(const MutantStack &other);
		~MutantStack();

		using iterator = typename std::deque<T>::iterator;
		using const_iterator = typename std::deque<T>::const_iterator;
		using reverse_iterator = typename std::deque<T>::reverse_iterator;
		using const_reverse_iterator = typename std::deque<T>::const_reverse_iterator;

		iterator begin() { return this->c.begin(); }
		iterator end() { return this->c.end(); }

		const_iterator begin() const { return this->c.begin(); }
		const_iterator end() const { return this->c.end(); }

		reverse_iterator rbegin() { return this->c.rbegin(); }
		reverse_iterator rend() { return this->c.rend(); }

		const_reverse_iterator rbegin() const { return this->c.rbegin(); }
		const_reverse_iterator rend() const { return this->c.rend(); }
};

#include "MutantStack.tpp"

#endif




/*

	std::deque (double-ended queue)//!
	A sequence container allowing fast insertion and removal of elements at both its beginning and end. Supports random access to elements, making it efficient for adding or removing from both ends.

	std::stack//!
	An adapter container that provides a LIFO (Last-In-First-Out) data structure. Elements are added and removed from only one end (the top).

	push() / pop()//! std::stack
	push() adds a new element to the top of a stack or the back/front of certain containers.
	pop() removes the element at the top of a stack or the back/front of certain containers.

	push_back() / push_front()//! std::vector / std::list / std::deque
	push_back() inserts a new element at the end (back) of a container (like std::deque or std::vector).
	push_front() inserts a new element at the beginning (front) of a container (like std::deque or std::list).

	pop_back() / pop_front()//!
	pop_back() removes the last (back) element of a container.
	pop_front() removes the first (front) element of a container.

	top()//!
	Returns a reference to the top element in a stack (the most recently added element).

	begin() / end()//!
	begin() returns an iterator pointing to the first element of a container.
	end() returns an iterator pointing just past the last element of a container, marking the boundary of the sequence.

	rbegin()//!
	Returns a reverse iterator pointing to the last element of a container, enabling iteration from the end to the beginning.

	rend()//!
	Returns a reverse iterator pointing just before the first element of a container, marking the boundary of reverse iteration.
	rend() its like end(), but just elements before first (not the after last, like end() )

	using//!
	A C++ keyword that introduces type aliases or imports names from namespaces, simplifying code and improving readability.(psevdonim)

*/