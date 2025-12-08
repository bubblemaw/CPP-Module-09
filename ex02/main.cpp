/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masase <masase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 14:11:40 by masase            #+#    #+#             */
/*   Updated: 2025/12/01 14:57:33 by masase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac < 2)
		return (0);	
	std::vector<std::string> set(av + 1, av + ac);
	std::vector<std::string>::iterator it = set.begin();
	std::vector<int> numbers;
	v_it it1;
	pair_vec numbers_2;
	for (it = set.begin(); it < set.end(); ++it)
	{
		numbers.push_back(stoi(*it));
	}
	for (it1 = numbers.begin(); it1 < numbers.end(); ++it1)
	{
		numbers_2.push_back(*it1);
	}
	// PmergeMe sort(numbers);
	// std::cout << "numbers before the work" << std::endl;
	// sort.display_set();
	// sort.mergesort();
	// std::cout << "numbers after pairs" << std::endl;
	// sort.display_set();
	PmergeMe sort(numbers_2);
	std::cout << "numbers before the work" << std::endl;
	sort.display_vector_pair(numbers_2);
	sort.mergesort();
	std::cout << "numbers after pairs" << std::endl;
	// sort.display_vector_pair();		
	return (0);
}