/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 21:17:36 by maw               #+#    #+#             */
/*   Updated: 2025/11/21 13:51:31 by maw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP
# include <iostream>
# include <stack>

class RPN
{
	private:
		int r_1;
		int r_2;
		std::stack<int> _stack;
	public:
		RPN();
		RPN(const RPN &obj);
		~RPN();
		RPN& operator=(const RPN &obj);
		void polish(char *str);
	class ex_token : public std::exception
	{
		public:
			virtual const char *what() const throw()
			{
				return "Error";
			}
	};
};


#endif