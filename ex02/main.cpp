/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masase <masase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 14:11:40 by masase            #+#    #+#             */
/*   Updated: 2025/11/30 20:56:41 by masase           ###   ########.fr       */
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
	for (it = set.begin(); it < set.end(); ++it)
	{
		numbers.push_back(stoi(*it));
	}
	PmergeMe sort(numbers);
	std::cout << "numbers before the work" << std::endl;
	sort.display_set();
	sort.mergesort();
	std::cout << "numbers after pairs" << std::endl;
	sort.display_set();	
	return (0);
}