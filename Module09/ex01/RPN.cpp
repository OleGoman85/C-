/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 11:01:18 by ogoman            #+#    #+#             */
/*   Updated: 2025/01/21 06:28:34 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <sstream>       // Used for parsing strings with string streams
#include <cctype>        // Provides character classification functions like std::isdigit
#include <iostream>      // Used for error reporting

/**
 * @brief Default constructor for RPN.
 */
RPN::RPN() {}

/**
 * @brief Destructor for RPN.
 */
RPN::~RPN() {}

/**
 * @brief Evaluates a reverse Polish notation (RPN) expression.
 * 
 * @param expression The RPN expression as a space-separated string.
 * @return int The result of the evaluation.
 * @throws std::runtime_error If the expression is invalid or division by zero occurs.
 */
int RPN::evaluate(const std::string& expression)
{
    std::stack<int> stack; // Stack to store operands
    std::istringstream stream(expression);
    std::string token;

    while (stream >> token) 
    {
        if (isSingleDigit(token)) 
        {
            stack.push(token[0] - '0'); // Convert character to integer
        } 
        else if (isOperator(token)) 
        {
            if (stack.size() < 2) 
                throw std::runtime_error("Error: insufficient operands");

            int operand2 = stack.top(); stack.pop();
            int operand1 = stack.top(); stack.pop();
            stack.push(performOperation(token[0], operand1, operand2));
        } 
        else 
        {
            throw std::runtime_error("Error: invalid token");
        }
    }

    if (stack.size() != 1)
        throw std::runtime_error("Error: invalid expression");

    return stack.top();
}

/**
 * @brief Performs a single arithmetic operation.
 * 
 * @param op The operator character ('+', '-', '*', '/').
 * @param operand1 The first operand.
 * @param operand2 The second operand.
 * @return int The result of the operation.
 * @throws std::runtime_error If the operator is unknown or division by zero occurs.
 */
int RPN::performOperation(char op, int operand1, int operand2) 
{
    switch (op) 
    {
        case '+': return operand1 + operand2;
        case '-': return operand1 - operand2;
        case '*': return operand1 * operand2;
        case '/': 
            if (operand2 == 0) 
                throw std::runtime_error("Error: division by zero");
            return operand1 / operand2;
        default:
            throw std::runtime_error("Error: unknown operator");
    }
}

/**
 * @brief Checks if a token is a single digit.
 * 
 * @param token The token to check.
 * @return true If the token is a single digit.
 * @return false Otherwise.
 */
bool RPN::isSingleDigit(const std::string& token) 
{
    return token.size() == 1 && std::isdigit(token[0]);
}

/**
 * @brief Checks if a token is a valid operator.
 * 
 * @param token The token to check.
 * @return true If the token is a valid operator.
 * @return false Otherwise.
 */
bool RPN::isOperator(const std::string& token) 
{
    return token.size() == 1 && std::string("+-*/").find(token[0]) != std::string::npos;
}

// Special meaning: npos is not the actual position, but an indicator that the seek operation failed.