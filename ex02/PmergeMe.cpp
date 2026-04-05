/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 14:11:46 by masase            #+#    #+#             */
/*   Updated: 2026/01/03 10:42:38 by maw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int PmergeMe::jacob_generator(int n)
{
	return (round((pow(2, n +1 ) + pow(-1, n)) / 3 ));
}

PmergeMe::PmergeMe()
{
	std::cout << "PmergeMe Default Constructor" << std::endl;
	// set = numbers;
}

// PmergeMe::PmergeMe(pair_vec numbers)
// {
// 	std::cout << "PmergeMe Default Constructor" << std::endl;
// 	set2 = numbers;
// }

// PmergeMe::PmergeMe(const PmergeMe &obj)
// {
// 	std::cout << "PmergeMe Copy Constructor" << std::endl;
// 	*this = obj;
// }

PmergeMe::~PmergeMe()
{
	std::cout << "PmergeMe Destructor" << std::endl;
}

// PmergeMe&	PmergeMe::operator=(const PmergeMe &obj)
// {
// 	std::cout << "PmergeMe Assignement operator" << std::endl;
// 	if (this != &obj)
// 	{

// 	}
// 	return *this;
// }

int PmergeMe::comp = 0;

