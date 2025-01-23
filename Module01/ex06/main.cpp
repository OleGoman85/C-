/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:27:36 by ogoman            #+#    #+#             */
/*   Updated: 2024/10/24 09:58:41 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <level>" << std::endl;
		return 1;
	}

	std::string harl_complain = argv[1];
	Harl harl;

	harl.complain(harl_complain);

	return 0;
}

//* /.harl DEBUG                 "DEBUG", "INFO", "WARNING", "ERROR"
