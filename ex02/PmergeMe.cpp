/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masase <masase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 14:11:46 by masase            #+#    #+#             */
/*   Updated: 2025/12/01 16:06:56 by masase           ###   ########.fr       */
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

int PmergeMe::jacob_generator(int n)
{
	return (round((pow(2, n +1 ) + pow(-1, n)) / 3 ));
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
	if (set.size() < _order * 2)
	{
		return ;
	}
	createpair();
	mergesort(); // recursive after or before ?	
	_order =  _order / 2;
	init();
	insertion();
	main.erase(main.begin(), main.begin() + main.size());
	pend.erase(pend.begin(), pend.begin() + pend.size());	
}

void PmergeMe::init()
{
	v_it b;
	v_it a;
	for (int i = 0; i < set.size(); i += _order)
	{
		if (i + _order >= set.size()) // odd number sequence
			break ;				
		// std::cout << "dans le init " << "with this order " << _order << std::endl;
		b = set.begin() + i + (_order - 1);
		if (i == 0)
			main.insert(main.begin() , b - (_order - 1), b + 1);
		else
			pend.insert(pend.end() , b - (_order - 1), b + 1);		
		if (i + _order >= set.size()) // odd number sequence
			break ;		
		i += _order;
		a = set.begin() + i + (_order - 1);
		if (i + _order >= set.size()) // odd number sequence
			break ;	
		display_set();
		std::cout << "b set " << *b << " a set " << *a << std::endl;		
		main.insert(main.end() , a - (_order - 1), a + 1);
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
	v_it b;
	v_it insert_place;
	int insertion;
	int n = 2;
	int jacob;
	int pairs_pend = pend.size() / _order;
	int pair_it_pend = pairs_pend;
	int pairs_main = main.size() / _order;
	jacob = jacob_generator(n);
	n++;
	std::cout << "insertion with the order " << _order << std::endl;	
	for (int i = pend.size() ; i > 0; i -= _order)
	{
		while (pair_it_pend + 1 > jacob || pair_it_pend > 0)
		{
			b = pend.begin() +  (i - 1);
			i -= _order;
			pair_it_pend--;
			std::cout << "b to insert " << *b << std::endl;			
		}
 		for (int j = 0; pair_it_pend < pairs_main; j += _order) //(pair_it < pairs_main)
		{
			insert_place = main.begin() + j + (_order - 1);
			std::cout << "insert palce " << *insert_place << std::endl;					
		}
		
	}	
	
}

void PmergeMe::createpair()
{
	// std::cout << "creating pairs with the order " << _order << std::endl;	
	v_it left_pair;
	v_it right_pair;
	for (int i = 0; i < set.size(); i += _order)
	{
		left_pair = set.begin() + i + (_order -1);
		i += _order;
		if (i + (_order -1) >= set.size()) // odd number sequence
			break ;
		right_pair = set.begin() + i + (_order -1);
		// std::cout << "left pair " << *left_pair << " right pair " << *right_pair << std::endl;		
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
		// std::cout << "we just swapped " << *begin1 << " and " << *begin2 << std::endl;
		begin1 -= 1;
		begin2 -= 1;		
	}
}
