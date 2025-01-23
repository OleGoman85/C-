/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 11:01:15 by ogoman            #+#    #+#             */
/*   Updated: 2025/01/20 11:03:59 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>
#include <stdexcept>

class RPN 
{
    public:
        RPN();
        ~RPN();

        RPN(const RPN& other) = delete;
        RPN& operator=(const RPN& other) = delete;

        static int evaluate(const std::string& expression);
    private:
        static int performOperation(char op, int operand1, int operand2);
        static bool isSingleDigit(const std::string& token);
        static bool isOperator(const std::string& token);

};

#endif
