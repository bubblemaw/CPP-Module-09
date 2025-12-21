/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masase <masase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 14:11:46 by masase            #+#    #+#             */
/*   Updated: 2025/12/21 13:44:12 by masase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(std::vector<int> &numbers)
{
	std::cout << "PmergeMe Default Constructor" << std::endl;
	set = numbers;
}

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

void	PmergeMe::display_vector_pair(pair_vec &vec)
{
	p_it it;
	for (it = vec.begin(); it < vec.end(); ++it)
	{
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
	std::cout << "NEW pend: ";
	display_vector_pair(pend2);
	std::cout << std::endl;
	set2.erase(set2.begin(), set2.end());
	set2.insert(set2.begin(), main2.begin(), main2.end());
	set2.insert(set2.end(), leftover2.begin(), leftover2.end());
	main2.erase(main2.begin(), main2.begin() + main2.size());
	pend2.erase(pend2.begin(), pend2.begin() + pend2.size());
	leftover2.erase(leftover2.begin(), leftover2.begin() + leftover2.size());
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

void PmergeMe::init_2()
{
	p_it b;
	p_it a;
	int insert_count = 0;
	for (int i = _order; i <= set2.size(); i += _order)
	{
		std::cout << "the set: "; 
		display_vector_pair(set2);
		// std::cout << "the order is: " << _order << std::endl; 
		b = set2.begin() + i - 1;
		if (i == _order)
		{
			main2.insert(main2.begin() , b - (_order - 1), b + 1);
			insert_count++;
		}
		else
		{
			pend2.insert(pend2.end() , b - (_order - 1), b + 1);
			insert_count++;			
		}
		std::cout << i + _order << " " << set2.size() << std::endl;
		if (i + _order >= set2.size()) // odd number sequence
			break ;		
		i += _order;
		a = set2.begin() + i - 1;
		// std::cout << "b set " << *b << " a set " << *a << std::endl;		
		main2.insert(main2.end() , a - (_order - 1), a + 1);
		insert_count++;
	}
	set2.erase(set2.begin(), set2.begin() + insert_count * _order);
	leftover2.insert(leftover2.begin(), set2.begin(), set2.end());
	std::cout << "the set: ";	
	display_vector_pair(set2);
	std::cout << "the main: ";
	display_vector_pair(main2);
	std::cout << std::endl;
	std::cout << "the pend: ";
	display_vector_pair(pend2);
	std::cout << std::endl;
	std::cout << "the leftover: ";
	display_vector_pair(leftover2);
	std::cout << std::endl;
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
	for (int i = 0 ; i < pend2.size() ; i += _order)
	{
		while (pair_it_pend > 0)
		{
			std::cout << " dans le selec la paire du pend: " << pair_it_pend << std::endl;
			std::cout << "i: " << i << std::endl;
			b = pend2.end() - (i + 1);
			if (pair_it_pend <= jacob && pair_it_pend > old_jacob)
			{
				std::cout << "b to insert " << b->get_number() << std::endl;
				break ;
			}
			i += _order;
			pair_it_pend--;
		}
		pair_it_main = pair_it_pend + insertion;
		int j = ((pairs_main - insertion) - (pair_it_pend + insertion)) * _order;		
 		while (pair_it_main > 0 && pair_it_main <= pair_it_pend) //(pair_it < pairs_main)
		{
			std::cout << "iterator pend: " << pair_it_pend << std::endl;
			std::cout << "iterator main: " << pair_it_main << std::endl;
			insert_place = main2.end() - (j + 1);
			if (pair_it_main == 1) // insert a the beginnning
			{
				main2.insert(main2.begin(), b - (_order - 1) , b + 1 );
				// pairs_pend--;
				// pairs_main++;			
				insertion++;
				std::cout << "main after the insert: ";
				display_vector_pair(main2);
				break ;
			}
			std::cout << b->get_number() << " du pend plus grand que " << insert_place->get_number() << " du main ?" << std::endl;
			if (b->get_number() > insert_place->get_number()) // insert in between 
			{
				std::cout << "insert place " << insert_place->get_number() << std::endl;
				main2.insert(main2.end() - j, b - (_order - 1) , b + 1);
				// pairs_pend--;	
				// pairs_main++;
				insertion++;
				std::cout << "main after the insert: ";
				display_vector_pair(main2);
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
	pend2.erase(pend2.begin(), pend2.begin() + pend2.size());
	set2.insert(set2.begin(), main2.begin(), main2.end());
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
	std::cout << "main before insertion" << std::endl;
	display_vector(main);
	std::cout << "ooend before insertion" << std::endl;
	display_vector(pend);
	for (int i = 0 ; i < pend.size() ; i += _order)
	{
		while (pair_it_pend > 0)
		{
			std::cout << " dans le selec la paire du pend: " << pair_it_pend << std::endl;
			std::cout << "i: " << i << std::endl;
			b = pend.end() - (i + 1);
			if (pair_it_pend <= jacob && pair_it_pend > old_jacob)
			{
				std::cout << "b to insert " << *b << std::endl;
				break ;
			}
			i += _order;
			pair_it_pend--;
		}
		pair_it_main = pair_it_pend + insertion;
		int j = ((pairs_main - insertion) - (pair_it_pend + insertion)) * _order;		
 		while (pair_it_main > 0 && pair_it_main <= pair_it_pend) //(pair_it < pairs_main)
		{
			std::cout << "iterator pend: " << pair_it_pend << std::endl;
			std::cout << "iterator main: " << pair_it_main << std::endl;
			insert_place = main.end() - (j + 1);
			if (pair_it_main == 1) // insert a the beginnning
			{
				main.insert(main.begin(), b - (_order - 1) , b + 1 );
				// pairs_pend--;
				// pairs_main++;			
				insertion++;
				std::cout << "main after the insert: ";
				display_vector(main);
				break ;
			}
			std::cout << *b << " du pend plus grand que " << *insert_place << " du main ?" << std::endl;
			if (*b > *insert_place) // insert in between 
			{
				std::cout << "insert place " << *insert_place << std::endl;
				main.insert(main.end() - j, b - (_order - 1) , b + 1);
				// pairs_pend--;	
				// pairs_main++;
				insertion++;
				std::cout << "main after the insert: ";
				display_vector(main);
				break ;
			}
			pair_it_main--;
			j += _order;			
		}
		std::cout << "la paire du pend: " << pair_it_pend << std::endl; 
		if (insertion >= jacob || pair_it_pend == 2)
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

void PmergeMe::swap2(p_it begin1, p_it begin2, int order)
{
	for (int i = order; i > 0; --i)
	{
		std::iter_swap(begin1, begin2);
		std::cout << "we just swapped " << begin1->get_number() << " and " << begin2->get_number() << std::endl;
		begin1 -= 1;
		begin2 -= 1;		
	}
}

