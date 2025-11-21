/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 21:17:30 by maw               #+#    #+#             */
/*   Updated: 2025/11/21 13:52:33 by maw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
	// std::cout << "Default RPN constructor" <<  std::endl;	
}

RPN::RPN(const RPN &obj)
{
	// std::cout << "RPN copy constructor" <<  std::endl;
	*this = obj;
}

RPN::~RPN()
{
	// std::cout << "RPN Destructor" <<  std::endl;	
}

RPN&	RPN::operator=(const RPN &obj)
{
	// std::cout << "RPN assignment operator" <<  std::endl;
	if (this != &obj)
	{
		this->r_1 = obj.r_1;
		this->r_2 = obj.r_2;
		this->_stack = obj._stack;		
	}
	return *this;
}
void RPN::polish(char *str)
{
	for (int i = 0; str[i]; i++)
	{
		if (isdigit(str[i]))
			_stack.push(str[i] - '0');
		else if (isspace(str[i]))
			(void)str[i];
		else if (str[i] == '+')
		{
			r_1 = _stack.top();
			_stack.pop();
			r_2 = _stack.top(); 
			_stack.pop();
			_stack.push(r_2 + r_1);
		}
		else if (str[i] == '-')
		{
			r_1 = _stack.top(); 
			_stack.pop();
			r_2 = _stack.top(); 
			_stack.pop();
			_stack.push(r_2 - r_1);
		}
		else if (str[i] == '*')
		{
			r_1 = _stack.top(); 
			_stack.pop();
			r_2 = _stack.top(); 
			_stack.pop();
			_stack.push(r_2 * r_1);
		}
		else if (str[i] == '/')
		{
			r_1 = _stack.top(); 
			_stack.pop();
			r_2 = _stack.top(); 
			_stack.pop();
			_stack.push(r_2 / r_1);
		}
		else
			throw ex_token();				
	}
	std::cout << _stack.top() << std::endl;
}