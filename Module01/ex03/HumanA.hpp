/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:21:43 by ogoman            #+#    #+#             */
/*   Updated: 2024/10/24 09:44:34 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include "Weapon.hpp"

class HumanA
{
private:
	std::string _name;
	Weapon &_weapon; // Reference to weapon

public:
	HumanA(const std::string &name, Weapon &weapon_A); // Constructor

	void attack() const; // Attack method
};

#endif
