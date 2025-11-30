/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masase <masase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 14:11:46 by masase            #+#    #+#             */
/*   Updated: 2025/11/30 22:31:39 by masase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(std::vector<int> &numbers)
{
	std::cout << "PmergeMe Default Constructor" << std::endl;
	set = numbers;
}

PmergeMe::PmergeMe(const PmergeMe &obj)
{
	std::cout << "PmergeMe Copy Constructor" << std::endl;
	*this = obj;
}

PmergeMe::~PmergeMe()
{
	std::cout << "PmergeMe Destructor" << std::endl;
}

PmergeMe&	PmergeMe::operator=(const PmergeMe &obj)
{
	std::cout << "PmergeMe Assignement operator" << std::endl;
	if (this != &obj)
	{

	}
	return *this;
}

void	PmergeMe::display_set()
{
	for (int i = 0; i < set.size(); ++i)
	{
		std::cout << set.at(i) << " ";
	}
	std::cout << std::endl;
}

void	PmergeMe::display_vector(std::vector<int> &vec)
{
	for (int i = 0; i < vec.size(); ++i)
	{
		std::cout << vec.at(i) << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::mergesort()
{
	std::cout << "merge sort" << std::endl;
	if (set.size() > _order * 2)
	{
		createpair();
		mergesort(); // recursive after or before ?
	}
	_order =  _order / 2;
	init();
	// insertion();
}

void PmergeMe::init()
{
	v_it b;
	v_it a;
	for (int i = 0; i < set.size(); i += _order)
	{
		std::cout << "dans le init " << "with this order " << _order << std::endl;
		b = set.begin() + i + (_order - 1);
		i += _order;
		if (i + (_order -1) >= set.size()) // odd number sequence
			break ;
		a = set.begin() + i + (_order -1);
		display_set();
		std::cout << "b set " << *b << " a set " << *a << std::endl;		
		main.insert(main.begin() , a - (_order - 1), a);
		if (i - (_order * 2) == 0)
			pend.insert(pend.begin() , a - (_order - 1), a);
		else
			pend.insert(pend.begin() , a - (_order - 1), a);
	}
	std::cout << "the main: ";
	display_vector(main);
	std::cout << std::endl;
	std::cout << "the pend: ";
	display_vector(pend);
	std::cout << std::endl;	
}

void PmergeMe::insertion()
{
	
}

void PmergeMe::createpair()
{
	std::cout << "creating pairs with the order " << _order << std::endl;	
	v_it left_pair;
	v_it right_pair;
	for (int i = 0; i < set.size(); i += _order)
	{
		left_pair = set.begin() + i + (_order -1);
		i += _order;
		if (i + (_order -1) >= set.size()) // odd number sequence
			break ;
		right_pair = set.begin() + i + (_order -1);
		std::cout << "left pair " << *left_pair << " right pair " << *right_pair << std::endl;		
		if (*left_pair > *right_pair)
			swap(left_pair, right_pair, _order);
	}
	_order = _order * 2;
}

void PmergeMe::swap(v_it begin1, v_it begin2, int order)
{
	for (int i = order; i > 0; --i)
	{
		std::iter_swap(begin1, begin2);
		std::cout << "we just swapped " << *begin1 << " and " << *begin2 << std::endl;
		begin1 -= 1;
		begin2 -= 1;		
	}
}
