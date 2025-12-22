/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masase <masase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 14:11:46 by masase            #+#    #+#             */
/*   Updated: 2025/12/22 19:58:39 by masase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// PmergeMe::PmergeMe(std::vector<int> &numbers)
// {
// 	std::cout << "PmergeMe Default Constructor" << std::endl;
// 	set = numbers;
// }

PmergeMe::PmergeMe(pair_vec numbers)
{
	std::cout << "PmergeMe Default Constructor" << std::endl;
	set2 = numbers;
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

void	PmergeMe::display_vector(std::vector<int> &vec)
{
	for (int i = 0; i < vec.size(); ++i)
	{
		std::cout << vec.at(i) << " ";
	}
	std::cout << std::endl;
}

void	PmergeMe::display_vector_pair(pair_vec &vec)
{
	p_it it;
	for (it = vec.begin(); it < vec.end(); ++it)
	{
		std::cout << it->get_number() << " ";
	}
	std::cout << std::endl;
}

void	PmergeMe::display_vector_pair_spec(pair_vec &vec)
{
	p_it it;
	for (it = vec.begin(); it < vec.end(); ++it)
	{
		if (it->get_head() ==true)
			std::cout << it->get_number() << "*" << it->get_num_pair() << "*" << " ";
		else
			std::cout << it->get_number() << " ";

	}
	std::cout << std::endl;
}

void PmergeMe::mergesort()
{
	std::cout << "merge sort" << std::endl;
	if (set2.size() < _order * 2)
	{
		display_vector_pair(set2);
		return ;
	}
	createpair_2();
	mergesort(); // recursive after or before ?	

	_order =  _order / 2;
	init_2();
	insertion_2();
	std::cout << "NEW main: ";
	display_vector_pair(main2);
	std::cout << std::endl;
	set2.erase(set2.begin(), set2.end());
	set2.insert(set2.begin(), main2.begin(), main2.end());
	set2.insert(set2.end(), leftover2.begin(), leftover2.end());
	main2.erase(main2.begin(), main2.begin() + main2.size());
	pend2.erase(pend2.begin(), pend2.begin() + pend2.size());
	leftover2.erase(leftover2.begin(), leftover2.begin() + leftover2.size());
}

void PmergeMe::reset_pair(p_it it, int j, bool A, bool B)
{
	it->set_head(true);
	it->set_num_pair(j);
	it->setB(B);
	it->setA(A);
}

void PmergeMe::init_2()
{
	p_it b;
	p_it a;
	int insert_count = 0;
	int j = 1;
	reset_all_pair(set2);
	for (int i = _order; i <= set2.size(); i += _order)
	{
		b = set2.begin() + i - 1;
		if (i == _order)
		{
			reset_pair(b, j, false, true);
			// b->set_head(true);
			// b->set_num_pair(j);
			// b->setB(true);
			// b->setA(false);
			main2.insert(main2.begin() , b - (_order - 1), b + 1);
			insert_count++;
		}
		else
		{
			reset_pair(b, j, false, true);			
			// b->set_head(true);
			// b->set_num_pair(j);
			// b->setB(true);
			// b->setA(false);			
			pend2.insert(pend2.end() , b - (_order - 1), b + 1);
			insert_count++;			
		}
		if (i + _order >= set2.size() && _order > 1) // odd number sequence
			break ;
		i += _order;
		a = set2.begin() + i - 1;
			reset_pair(b, j, false, true);		
		// a->set_head(true);
		// a->set_num_pair(j);
		// a->setB(true);
		// a->setA(false);				
		main2.insert(main2.end() , a - (_order - 1), a + 1);
		insert_count++;
		j++;
	}
	std::cout << "about to insert the thing" << std::endl; 
	set2.erase(set2.begin(), set2.begin() + insert_count * _order);
	std::cout << "the set: ";	
	display_vector_pair(set2);	
	// if (set2.empty() != 1)
		leftover2.insert(leftover2.begin(), set2.begin(), set2.end()); // work to be done here

	// std::cout << "the main: ";
	// display_vector_pair(main2);
	// std::cout << std::endl;
	// std::cout << "the pend: ";
	// display_vector_pair(pend2);
	// std::cout << std::endl;
	// std::cout << "the leftover: ";
	// display_vector_pair(leftover2);
	// std::cout << std::endl;
}

void PmergeMe::insertion_2()
{
	p_it b;
	p_it insert_place;
	int insertion = 0;
	int n = 2;
	int jacob;
	int pairs_pend = pend2.size() / _order + 1;
	int pair_it_pend = pairs_pend;
	int pairs_main = main2.size() / _order + 1;
	int pair_it_main = 0;
	jacob = jacob_generator(n);
	int old_jacob = 0;
	std::cout << "insertion with the order " << _order << std::endl;
	std::cout << "main before insertion" << std::endl;
	display_vector_pair(main2);
	std::cout << "ooend before insertion" << std::endl;
	display_vector_pair(pend2);
	int i = 0;
	while (pend2.empty() == 0)
	{
		i = 0;
		b = pend2.end() - (i + 1);
		while (b->get_num_pair() > jacob)
		{
			b = pend2.end() - (i + 1);
			if (b->get_num_pair() == 0)
			{
				update_jacob(&old_jacob, &jacob, &n, &i);		
			}
			std::cout << "pend num pair: " << b->get_num_pair() << " number: " << b->get_number() << std::endl;			
			i += _order;
		}
		std::cout << "b to insert " << b->get_number() << std::endl;		
		int j = 0;
		insert_place = main2.end() - (j + 1);	
		while (insert_place->get_num_pair() >= b->get_num_pair() && j < main2.size() && b->get_num_pair() != 0)
		{
			j += _order;
			insert_place = main2.end() - (j + 1);
			std::cout << "pend num pair: " << b->get_num_pair() << " main: " << insert_place->get_num_pair() << std::endl;					
		}					
 		while (1 && b->get_num_pair() != 0) //(pair_it < pairs_main)
		{
			if (b->get_number() > insert_place->get_number())
			{
				std::cout << "insert place " << insert_place->get_number() << std::endl;
				main2.insert(main2.end() - j, b - (_order - 1) , b + 1);
				pend2.erase(b - (_order - 1),  b + 1);
				insertion++;
				std::cout << "main after the insert: ";
				display_vector_pair(main2);
				std::cout << "penf after the insert: ";
				display_vector_pair(pend2);				
				break ;
			}
			else if (j + _order > main2.size())
			{
				main2.insert(main2.begin(), b - (_order - 1) , b + 1);
				pend2.erase(b - (_order - 1),  b + 1);
				std::cout << "main after the insert: ";
				display_vector_pair(main2);
				std::cout << "penf after the insert: ";
				display_vector_pair(pend2);					
				break ;
			}
			std::cout << b->get_number() << " du pend plus grand que " << insert_place->get_number() << " du main ?" << std::endl;			
			j += _order;
			insert_place = main2.end() - (j + 1);					
		} 
		if (insertion >= jacob)
			update_jacob(&old_jacob, &jacob, &n, &i);
	}
	set2.insert(set2.begin(), main2.begin(), main2.end());
}

void PmergeMe::update_jacob(int *old_jacob, int *jacob, int *n, int *i)
{
	*old_jacob = *jacob;
	*n++;
	*i = 0;
	*jacob = jacob_generator(*n);
	// std::cout << "NEW JACOB" << std::endl;
}

void PmergeMe::createpair_2()
{
	std::cout << "creating pairs with the order " << _order << std::endl;	
	p_it left_pair;
	p_it right_pair;
	int j = 1;
	for (int i = 0; i < set2.size(); i += _order)
	{
		left_pair = set2.begin() + i + (_order -1);
		left_pair->setB(true);
		left_pair->setA(false);
		left_pair->set_head(true);
		left_pair->set_num_pair(j);
		i += _order;
		if (i + (_order -1) >= set2.size()) // odd number sequence
			break ;
		right_pair = set2.begin() + i + (_order -1);
		right_pair->setB(false);
		right_pair->setA(true);
		right_pair->set_head(true);
		right_pair->set_num_pair(j);		
		std::cout << "left pair " << left_pair->get_number() << " right pair " << right_pair->get_number() << std::endl;		
		if (left_pair->get_number() > right_pair->get_number())
			swap2(left_pair, right_pair, _order);
		j++;
	}
	_order = _order * 2;
}

void PmergeMe::swap2(p_it begin1, p_it begin2, int order)
{
	for (int i = order; i > 0; --i)
	{
		std::iter_swap(begin1, begin2);
		begin1 -= 1;
		begin2 -= 1;		
	}
}

void PmergeMe::reset_all_pair(pair_vec &vec)
{
	p_it it;	
	for (int i = 0; i < vec.size(); ++i)
	{
		it = set2.begin() + i;
		it->setB(false);
		it->setA(false);
		it->set_head(false);
		it->set_num_pair(0);
	}
}

