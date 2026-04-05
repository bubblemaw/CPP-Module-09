/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 14:11:50 by masase            #+#    #+#             */
/*   Updated: 2026/01/03 11:03:52 by maw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <vector>
# include <deque>
# include <iostream>
# include <algorithm>
# include <string>
# include <cmath>

class PmergeMe
{
	private:

	public:
		PmergeMe();
		PmergeMe(const PmergeMe &obj);
		~PmergeMe();
		PmergeMe& operator=(const PmergeMe &obj);
		template <typename T> void mergesort(T &vec, int order);
		template <typename T> void createpair(T &vec, int order);
		template <typename T> void swap(T begin1, T begin2, int order);		
		template <typename T> void display_vector(T &vec);
		template <typename T> void display_vector_iterator(T &vec);
		int	jacob_generator(int n);
		static int comp;		
};

template <typename T> bool comparaison(T left, T right)
{
	PmergeMe::comp++;
	if (*left > *right)
		return false;
	else
		return true;
}

template <typename T>
void PmergeMe::mergesort(T &vec, int order)
{
	typedef typename T::iterator Iterator;

	if (vec.size() < order * 2)
	{
		// display_vector(vec);
		return ;
	}
	createpair(vec, order);
	mergesort(vec, order * 2);

	std::vector<Iterator> main;
	std::vector<Iterator> pend;
	T leftover;

	main.insert(main.end(), vec.begin() + (order - 1));
	main.insert(main.end(), vec.begin() + ((2 * order) - 1));

	// dispatching main and pend
	Iterator temp_it;
	for (int i = order * 2; i < vec.size(); i += order)
	{
		if (i + (order -1) >= vec.size()) // odd number sequence
		{
			leftover.insert(leftover.end(), vec.begin() + i, vec.end());
			break ;
		}
		temp_it = vec.begin() + i + (order -1);
		pend.insert(pend.end(), temp_it);
		i += order;
		if (i + (order -1) >= vec.size()) // odd number sequence
		{
			leftover.insert(leftover.end(), vec.begin() + i, vec.end());
			break ;
		}
		temp_it = vec.begin() + i + (order -1);
		main.insert(main.end(), temp_it);				
	}

	// std::cout << "* Display of the dispatching with a order of " << order << " *"<< std::endl;
	// if (main.empty() == 0)
	// {
	// 	std::cout << "main: ";
	// 	display_vector_iterator(main);
	// }
	// if (pend.empty() == 0)
	// {
	// 	std::cout << "pend: ";		
	// 	display_vector_iterator(pend);
	// }	

	int n = 2;
	int prev_jacob = jacob_generator(1);
	int insertion = 0;
	int offset = 0;
	while (pend.empty() == 0)
	{
		int curr_jacob = jacob_generator(n);
		int insert_to_do = curr_jacob - prev_jacob;
		int idx_limit = curr_jacob - prev_jacob;
		if (insert_to_do > pend.size())
			break ;
		// std::cout << "insertion with jacob number of " << curr_jacob << std::endl;
		while (insert_to_do > 0)
		{
			typename std::vector<Iterator>::iterator pend_it;
			typename std::vector<Iterator>::iterator main_insert_place;
			typename std::vector<Iterator>::iterator main_limit;
			pend_it = pend.begin() + (insert_to_do - 1);
			main_limit = main.begin() + curr_jacob + insertion - offset;
			if (main_limit >= main.end())
				main_limit = main.end();
			// std::cout << "* pend that we insert *" <<  **pend_it << std::endl;				
			// if (main_limit != main.end())
				// std::cout << "main limit: " <<  **main_limit << std::endl;
			// else
				// std::cout << "main limit: is the end "<< std::endl;
			main_insert_place = std::upper_bound(main.begin(), main_limit, *pend_it, comparaison<Iterator>);	
			// std::cout << "insertion before: " << **main_insert_place  << std::endl;	
			main.insert(main_insert_place, *pend_it);
			pend.erase(pend_it);
			insert_to_do--;
			if (main_insert_place - main.begin() == curr_jacob + insertion)
			{
				// std::cout << "dans le offset" << std::endl;
				offset += 1;
			}
		}
		offset = 0;
		insertion += idx_limit;
		prev_jacob = curr_jacob;
		n++;
	}
	while (pend.empty() == 0) // insert what left
	{
		bool is_odd;
		if ((pend.size() + main.size()) % 2 == 0)
			is_odd =  false;
		else 
			is_odd = true;
		typename std::vector<Iterator>::iterator pend_it;
		typename std::vector<Iterator>::iterator main_insert_place;		
		typename std::vector<Iterator>::iterator main_limit;	
		
		pend_it = pend.begin() + (pend.size() - 1);
		main_limit = main.begin() + (main.size() - pend.size() + is_odd);
		main_insert_place = std::upper_bound(main.begin(), main_limit, *pend_it, comparaison<Iterator>);	
		main.insert(main_insert_place, *pend_it);
		pend.erase(pend_it);
	}

	// std::cout << "* Display after insertion with a order of " << order << " *"<< std::endl;
	// if (main.empty() == 0)
	// {
	// 	std::cout << "main: ";		
	// 	display_vector_iterator(main);
	// }
	// if (pend.empty() == 0)
	// {
	// 	std::cout << "pend: ";			
	// 	display_vector_iterator(pend);
	// }	
	// copie des pairs entiere dans nouvelle chaine
	T copy;
	typename std::vector<Iterator>::iterator it;
	for(it = main.begin(); it != main.end(); ++it)
	{
		int i = 0;
		while (i < (int)vec.size())
		{

			if (vec[i] == **it)
			{
				int j = order;
				while (j > 0)
				{
					copy.insert(copy.end(), vec[i - (j - 1)]);
					j--;
				}
				break ;
			}
			i++;
		}
	}
	// ajout du leftovers dans la nouvelle chaine

	// Iterator copy_it = copy.end() - 1;
	// std::cout << "the leftover: " << std::endl;
	// 	display_vector(leftover);
	copy.insert(copy.end(), leftover.begin(), leftover.end());
	// std::cout << "* Display of the original vec " << order << " *"<< std::endl;
	// 	display_vector(vec);	
	// std::cout << "* Display of the new vec " << order << " *"<< std::endl;
	// 	display_vector(copy);
	vec.erase(vec.begin(), vec.end());
	vec.insert(vec.end(), copy.begin(), copy.end());
}

template <typename T>
void PmergeMe::createpair(T &vec, int order)
{
	typedef typename T::iterator Iterator;	
	// std::cout << "creating pairs with the order " << order << std::endl;	
	Iterator left_pair;
	Iterator right_pair;
	int j = 1;
	for (int i = 0; i < vec.size(); i += order)
	{
		left_pair = vec.begin() + i + (order -1);
		i += order;
		if (i + (order -1) >= vec.size()) // odd number sequence
			break ;
		right_pair = vec.begin() + i + (order -1);			
		// std::cout << "left pair " << *left_pair << " right pair " << *right_pair << std::endl;		
		if (*left_pair > *right_pair)
			swap(left_pair, right_pair, order);
	}
}

template <typename T>
void PmergeMe::swap(T begin1, T begin2, int order)
{
	for (int i = order; i > 0; --i)
	{
		std::iter_swap(begin1, begin2);
		begin1 -= 1;
		begin2 -= 1;		
	}
}

template <typename T>
void	PmergeMe::display_vector(T &vec)
{
	for (int i = 0; i < vec.size(); ++i)
	{
		std::cout << vec.at(i) << " ";
	}
	std::cout << std::endl;
}

template <typename T>
void	PmergeMe::display_vector_iterator(T &vec)
{
	typedef typename T::iterator Iterator;

	for (int i = 0; i < vec.size(); ++i)
	{
		std::cout << *vec[i] << " ";
	}
	std::cout << std::endl;
}


#endif