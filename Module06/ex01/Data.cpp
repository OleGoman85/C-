/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:22:18 by ogoman            #+#    #+#             */
/*   Updated: 2024/12/10 09:57:24 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"


Data::Data(int x) : _x(x) {}

// Data::Data(const Data& obj) {*this = obj;}
Data::Data(const Data &obj) : _x(obj._x) {}

Data &Data::operator=(const Data &rhs)
{
	if (this != &rhs)
	{
		_x = rhs._x;
	}
	return *this;
}

Data::~Data() {}
