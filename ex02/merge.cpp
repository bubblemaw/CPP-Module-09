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

merge::~merge()
{
	std::cout << "PmergeMe Destructor" << std::endl;
}

void merge::mergesort(std::vector<int> &vec)
{
	std::cout << "merge sort" << std::endl;
	if (set.size() < _order * 2)
	{
		display_vector(set);
		return ;
	}
	createpair(vec);
	// mergesort(); // recursive after or before ?	

	// _order =  _order / 2;
	// init_2();
	// insertion_2();
}

void merge::createpair(std::vector<int> &vec)
{
	std::cout << "creating pairs with the order " << _order << std::endl;	
	std::vector<int> main;
	std::vector<int> pend;
	if (vec.size() == 2)
	{
		display_vector(vec);		
		return;
	}
	for (int i = 0; i < vec.size(); i += 2)
	{
		if (vec[i] > vec[i + 1])
		{
			main.push_back(vec[i]);
			pend.push_back(vec[i + 1]);
		}
		else
		{
			main.push_back(vec[i + 1]);
			pend.push_back(vec[i]);			
		}
	}
	_order *= 2;
	createpair (main);
	_order /= 2;
	std::cout << "the order " << _order << std::endl; 
	std::cout << "le main: ";
	display_vector(main);
	std::cout << "le pend: ";
	display_vector(pend);
}

void merge::insertion(std::vector<int> &pend, std::vector<int> &main)
{
	int n = 2;
	int jacob;
	jacob = jacob_generator(n);
	int i = jacob;
	while (pend.empty() == 0)
	{
		pend[i]
	}
}

void merge::binary_insertion(std::vector<int> &main, int x, int low, int high)
{
	int low = 0;
	int high = main.size() - 1;
	while (low <= high)
	{  
		int mid = low + (high - low) / 2;
		if (x > main[mid] && x < main[mid + 1])
			main.insert(main.begin()+ mid + 1, x);
		
		
	}
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

void	merge::display_vector(std::vector<int> &vec)
{
	for (int i = 0; i < vec.size(); ++i)
	{
		std::cout << vec.at(i) << " ";
	}
	std::cout << std::endl;
}