/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:06:33 by ogoman            #+#    #+#             */
/*   Updated: 2024/12/09 07:31:37 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <string>

class Data
{
	public:
		int _x;

		Data() = delete;

		Data(int x);

		Data(const Data &obj);

		Data &operator=(const Data &rhs);

		~Data();
};

#endif
