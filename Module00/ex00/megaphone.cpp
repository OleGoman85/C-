/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 07:21:43 by ogoman            #+#    #+#             */
/*   Updated: 2024/09/19 08:07:25 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype> // std::toupper

void toUpper(char &c)
{
    c = std::toupper(static_cast<unsigned char>(c));
}

int main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "LOUD AND UNBEARABLE FEEDBACK NOISE" << std::endl;
	}
	else
	{
		for (int i = 1; i < ac; i++)
		{
			for (int j = 0; av[i][j] != '\0'; j++)
			{
				toUpper(av[i][j]);
				std::cout << av[i][j];
			}
			if (i < ac -1)
				std::cout << " ";
		}
		std::cout << std::endl;
	}
	return (0);
}