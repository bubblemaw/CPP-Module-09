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
#include <exception>
#include <algorithm>

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
	std::vector<int> double_vec;
	std::deque<int> numbers_deq;

	try
	{
		for (it = set.begin(); it < set.end(); ++it)
		{
			numbers_vec.push_back(stoi(*it));
			double_vec.push_back(stoi(*it));
			if (numbers_vec.front() < 0 || numbers_vec.front() > INT32_MAX)
				throw std::bad_alloc();
		}
		for (it = set.begin(); it < set.end(); ++it)
		{
			numbers_deq.push_back(stoi(*it));
		}
	}
	catch (...)
	{
		std::cout << "Error" << std::endl;
		return (0);
	}
	try
	{
		std::sort(double_vec.begin(), double_vec.end());
		double_vec.erase(std::unique(double_vec.begin(), double_vec.end()), double_vec.end());
		if (numbers_vec.size() != double_vec.size())
			throw std::bad_alloc();
	}
	catch(const std::exception& e)
	{
		std::cout << "Error dupliicate numbers" << std::endl;
		return (0);
	}
	if (std::is_sorted(numbers_vec.begin(), numbers_vec.end()))
	{
		std::cout << "This sequence is already sorted" << std::endl;
		return (0);
	}
	
	struct timeval vectorTime;
	struct timeval dequeTime;
	struct timeval currentTime;

	PmergeMe sort;
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
	gettimeofday(&dequeTime, NULL);
	long int dequeTimeMs = dequeTime.tv_sec * 1000000 + dequeTime.tv_usec;	
	sort.mergesort<std::deque<int>>(numbers_deq, 1);
	gettimeofday(&currentTime, NULL);
	currentTimeMs = currentTime.tv_sec * 1000000 + currentTime.tv_usec;
	std::cout << "Time to process a range of " << numbers_vec.size() << " elements with std::vector: " << SaveVecTime << " microseconds" << std::endl;	
	std::cout << "Time to process a range of " << numbers_deq.size() << " elements with std::deque: " << currentTimeMs - dequeTimeMs << " microseconds" << std::endl;	

	return (0);
}