/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 07:39:40 by ogoman            #+#    #+#             */
/*   Updated: 2024/12/05 07:14:30 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter
{
	private:
		ScalarConverter() = delete;
		~ScalarConverter() = delete;
		ScalarConverter(const ScalarConverter &obj) = delete;
		ScalarConverter &operator=(const ScalarConverter &rhs) = delete;

	public:
		static void convert(const std::string &literal);
};

#endif
