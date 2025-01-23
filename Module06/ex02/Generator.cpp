/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Generator.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 09:37:27 by ogoman            #+#    #+#             */
/*   Updated: 2024/12/11 12:26:41 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Generator.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib> // rand()
#include <ctime>   // time()

Base* generate()
{

    int random = rand() % 3; // random number 0-2
    switch (random)
    {
        case 0:
            return new A();
        case 1:
            return new B();
        default:
            return new C();
    }
}


// Error //!
// Base* generate()
// {
//     int random = rand() % 4; // random number 0-3
//     switch (random)
//     {
//         case 0:
//             return new A();
//         case 1:
//             return new B();
//         case 2:
//             return new C();
//         default:
//             return new D();
//     }
// }
