/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 14:11:46 by masase            #+#    #+#             */
/*   Updated: 2025/12/06 15:42:44 by maw              ###   ########.fr       */
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
	std::cout << "NEW main: ";
	display_vector(main);
	std::cout << std::endl;
	std::cout << "NEW pend: ";
	display_vector(pend);
	std::cout << std::endl;
	set.erase(set.begin(), set.end());
	set.insert(set.begin(), main.begin(), main.end());
	set.insert(set.end(), leftover.begin(), leftover.end());
	main.erase(main.begin(), main.begin() + main.size());
	pend.erase(pend.begin(), pend.begin() + pend.size());
	leftover.erase(leftover.begin(), leftover.begin() + leftover.size());
}

void PmergeMe::init()
{
	v_it b;
	v_it a;
	int insert_count = 0;
	for (int i = _order; i <= set.size(); i += _order)
	{
		// std::cout << "the set: "; 
		display_set();
		// std::cout << "the order is: " << _order << std::endl; 
		b = set.begin() + i - 1;
		if (i == _order)
		{
			main.insert(main.begin() , b - (_order - 1), b + 1);
			insert_count++;			
		}
		else
		{
			pend.insert(pend.end() , b - (_order - 1), b + 1);
			insert_count++;			
		}
		std::cout << i + _order << " " << set.size() << std::endl;
		if (i + _order >= set.size()) // odd number sequence
			break ;		
		i += _order;
		a = set.begin() + i - 1;
		// std::cout << "b set " << *b << " a set " << *a << std::endl;		
		main.insert(main.end() , a - (_order - 1), a + 1);
		insert_count++;
	}
	set.erase(set.begin(), set.begin() + insert_count * _order);
	leftover.insert(leftover.begin(), set.begin(), set.end());
	// std::cout << "the set: ";	
	// display_set();
	// std::cout << "the main: ";
	// display_vector(main);
	// std::cout << std::endl;
	// std::cout << "the pend: ";
	// display_vector(pend);
	// std::cout << std::endl;
	// std::cout << "the leftover: ";
	// display_vector(leftover);
	// std::cout << std::endl;
}

void PmergeMe::insertion()
{
	v_it b;
	v_it insert_place;
	int insertion = 0;
	int n = 2;
	int jacob;
	int pairs_pend = pend.size() / _order + 1;
	int pair_it_pend = pairs_pend;
	int pairs_main = main.size() / _order + 1;
	int pair_it_main = 0;
	jacob = jacob_generator(n);
	int old_jacob = 0;
	std::cout << "insertion with the order " << _order << std::endl;	
	for (int i = 0 ; i < pend.size() ; i += _order)
	{
		while (pair_it_pend > 0)
		{
			std::cout << " dans le selec la paire du pend: " << pair_it_pend << std::endl; 
			b = pend.end() - (i + 1);
			if (pair_it_pend <= jacob && pair_it_pend > old_jacob)
			{
				std::cout << "b to insert " << *b << std::endl;
				break ;
			}
			i += _order;
			pair_it_pend--;
		}
		pair_it_main = pair_it_pend;
		int j = (pairs_main - pair_it_pend) * _order;		
 		while (pair_it_main > 0 && pair_it_main <= pair_it_pend) //(pair_it < pairs_main)
		{
			std::cout << "insert main la paire du pend: " << pair_it_pend << std::endl;
			std::cout << "insert main la paire du main: " << pair_it_main << std::endl;
			insert_place = main.end() - (j + 1);
			if (*b > *insert_place)
			{
				std::cout << "insert place " << *insert_place << std::endl;
				main.insert(main.end() - j, b - (_order - 1) , b + 1);
				insertion++;
				std::cout << "main after the insert: ";
				display_vector(main);
				break ;
			}
			pair_it_main--;
			j += _order;			
		}
		std::cout << "la paire du pend: " << pair_it_pend << std::endl; 
		if (insertion >= jacob || pair_it_pend == 1)
		{
			pair_it_pend = pairs_pend;
			old_jacob = jacob;
			n++;
			i = 0;
			jacob = jacob_generator(n);
			std::cout << "NEW JACOB" << std::endl;
		}
		pair_it_pend--;		
	}
	pend.erase(pend.begin(), pend.begin() + pend.size());
	set.insert(set.begin(), main.begin(), main.end());
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
