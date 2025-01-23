/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 09:48:37 by ogoman            #+#    #+#             */
/*   Updated: 2025/01/06 11:10:08 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>

int main()
{
	MutantStack<int> mstack;
	MutantStack<std::string> mstack_string;

	mstack.push(5);
	mstack.push(17);
	std::cout << "Top element: " << mstack.top() << std::endl;
	std::cout << "\nStack Size "<<mstack.size() << std::endl;
	

	mstack.pop();
	std::cout << "\nSize after pop: " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it_begin = mstack.begin();
	MutantStack<int>::iterator it_end = mstack.end();

	std::cout << "\nIterating through MutantStack (int): " << "";
	while (it_begin != it_end)
	{
		std::cout << *it_begin << " ";
		++it_begin;
	}
	std::cout<<std::endl;
	
	std::cout << "\nIterating through MutantStack (int revers): " << "";
	auto rev_it = mstack.rbegin();
	// MutantStack<int>::reverse_iterator rev_it = mstack.rbegin(); //!same
	while(rev_it != mstack.rend())
	{
		std::cout << *rev_it << " ";
		rev_it++;
	}

	std::cout<<std::endl;
	std::cout << "\nIterating through MutantStack (string): " << "";

	mstack_string.push("Hello");
	mstack_string.push("World");
	mstack_string.push("!");

	MutantStack<std::string>::iterator it_str_begin = mstack_string.begin();
	MutantStack<std::string>::iterator it_str_end = mstack_string.end();
	
	while (it_str_begin != it_str_end)
	{
		std::cout << *it_str_begin << " ";
		it_str_begin++;
	}
		std::cout<<std::endl;
	
	return 0;
}


//! main from ex02
// int main()
// {
// 	MutantStack<int> mstack;
// 	mstack.push(5);
// 	mstack.push(17);
// 	std::cout << mstack.top() << std::endl;
// 	mstack.pop();
// 	std::cout << mstack.size() << std::endl;
// 	mstack.push(3);
// 	mstack.push(5);
// 	mstack.push(737);
// 	//[...]
// 	mstack.push(0);
// 	MutantStack<int>::iterator it = mstack.begin();
// 	MutantStack<int>::iterator ite = mstack.end();
// 	++it;
// 	--it;
// 	while (it != ite)
// 	{
// 	std::cout << *it << std::endl;
// 	++it;
// 	}
// 	std::stack<int> s(mstack);
// 	return 0;
// }


//!LIST
// #include <list>
// int main()
// {

// 	std::list<int> mstack;

// 	mstack.push_back(5);
// 	mstack.push_back(17);
// 	std::cout << "Top element: " << mstack.back() << std::endl;

// 	mstack.pop_back();
// 	std::cout << "Size after pop: " << mstack.size() << std::endl;

// 	mstack.push_back(3);
// 	mstack.push_back(5);
// 	mstack.push_back(737);
// 	mstack.push_back(0);

// 	std::list<int>::iterator it = mstack.begin();
// 	std::list<int>::iterator ite = mstack.end();

// 	std::cout << "Iterating through std::list:" << std::endl;
// 	while (it != ite) {
// 		std::cout << *it << std::endl;
// 		++it;
// 	}
// }
