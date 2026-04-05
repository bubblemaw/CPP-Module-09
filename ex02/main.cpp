/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 14:11:40 by masase            #+#    #+#             */
/*   Updated: 2026/01/03 10:41:50 by maw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <ctime>
#include <sys/time.h>

void display_vector(std::vector<int> &vec)
{
	for (int i = 0; i < vec.size(); ++i)
	{
		std::cout << vec.at(i) << " ";
	}
	std::cout << std::endl;
}

void display_vector(std::deque<int> &deq)
{
	for (int i = 0; i < deq.size(); ++i)
	{
		std::cout << deq.at(i) << " ";
	}
	std::cout << std::endl;
}

int main(int ac, char **av)
{
	if (ac < 2)
		return (0);	
	std::vector<std::string> set(av + 1, av + ac);
	std::vector<std::string>::iterator it = set.begin();
	std::vector<int> numbers_vec;
	std::deque<int> numbers_deq;
	// std::deque<int> numbers;
	for (it = set.begin(); it < set.end(); ++it)
	{
		numbers_vec.push_back(stoi(*it));
	}
	for (it = set.begin(); it < set.end(); ++it)
	{
		numbers_deq.push_back(stoi(*it));
	}
	struct timeval vectorTime;
	struct timeval dequeTime;
	struct timeval currentTime;

	PmergeMe sort;
	std::cout << "VECTOR" << std::endl;
	std::cout << "Before: ";
	display_vector(numbers_vec);
	gettimeofday(&vectorTime, NULL);
	long int vectorTimeMs = vectorTime.tv_sec * 1000000 + vectorTime.tv_usec;

	sort.mergesort<std::vector<int>>(numbers_vec, 1);

	gettimeofday(&currentTime, NULL);
	long int currentTimeMs = currentTime.tv_sec * 1000000 + currentTime.tv_usec;	
	long int SaveVecTime = currentTimeMs - vectorTimeMs;
	std::cout << "After: ";	
	display_vector(numbers_vec);
	std::cout << "numbers of comparaison: " << sort.comp << std::endl;


	// std::cout << "DEQUE" << std::endl;
	// std::cout << "Before: " << std::endl;
	// display_vector(numbers_deq);
	gettimeofday(&dequeTime, NULL);
	long int dequeTimeMs = dequeTime.tv_sec * 1000000 + dequeTime.tv_usec;	
	sort.mergesort<std::deque<int>>(numbers_deq, 1);
	gettimeofday(&currentTime, NULL);
	currentTimeMs = currentTime.tv_sec * 1000000 + currentTime.tv_usec;
	std::cout << "Time to process a range of " << numbers_vec.size() << " elements with std::vector: " << SaveVecTime << " microseconds" << std::endl;	
	std::cout << "Time to process a range of " << numbers_deq.size() << " elements with std::deque: " << currentTimeMs - vectorTimeMs << " microseconds" << std::endl;	
	// std::cout << "After: " << std::endl;	
	// display_vector(numbers_deq);
	// std::cout << "numbers of comparaison: " << sort.comp << std::endl;	
	// sort.display_comp();
	// std::cout << "numbers after pairs" << std::endl;
	// PmergeMe sort(numbers_2);
	// std::cout << "numbers before the work" << std::endl;
	// sort.display_vector_pair(numbers_2);
	// sort.mergesort();
	// std::cout << "numbers after pairs" << std::endl;
	// sort.display_vector_pair();		
	return (0);
}