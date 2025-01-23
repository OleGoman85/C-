/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:13:36 by ogoman            #+#    #+#             */
/*   Updated: 2024/10/10 12:37:23 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

// Constructor
Weapon::Weapon(const std::string &weapon_type) : _type(weapon_type) {}

// Getter for weapon type
const std::string &Weapon::getType() const {return _type;}

// Setter for weapon type
void Weapon::setType(const std::string &newType) {_type = newType;}

