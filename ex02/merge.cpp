/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 11:03:51 by maw               #+#    #+#             */
/*   Updated: 2026/01/05 00:08:14 by maw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

merge::merge(std::vector<int> &numbers)
{
	std::cout << "PmergeMe Default Constructor" << std::endl;
	set = numbers;
}

void merge::mergesort()
{
	std::cout << "merge sort" << std::endl;
	if (set.size() < _order * 2)
	{
		display_vector(set);
		return ;
	}
	createpair();
	mergesort(); // recursive after or before ?	

	_order =  _order / 2;
	init_2();
	insertion_2();
}

void merge::createpair()
{
	std::cout << "creating pairs with the order " << _order << std::endl;	
	v_it left_pair;
	v_it right_pair;
	std::vector<int> main;
	std::vector<int> pend;
	int j = 1;
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
		j++;
	}
	_order = _order * 2;
}

void merge::swap(v_it begin1, v_it begin2, int order)
{
	for (int i = order; i > 0; --i)
	{
		std::iter_swap(begin1, begin2);
		begin1 -= 1;
		begin2 -= 1;		
	}
}