/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:07:56 by ogoman            #+#    #+#             */
/*   Updated: 2024/10/10 12:37:28 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon
{
private:
	std::string _type; // Weapon type

public:
	Weapon(const std::string &weapon_type);	// Constructor

	const std::string &getType() const;	// Getter for weapon type

	void setType(const std::string &newType);	// Setter for weapon type
};

#endif // WEAPON_HPP
