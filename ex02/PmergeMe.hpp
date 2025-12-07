/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 14:11:50 by masase            #+#    #+#             */
/*   Updated: 2025/12/03 16:46:16 by maw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <vector>
# include <deque>
# include <iostream>
# include <algorithm>
# include <string>
# include <algorithm>
# include <cmath>

typedef std::vector<int>::iterator v_it; 

class PmergeMe
{
	private:
		int _order = 1;
		int _insertion;
		int _jacob;
		std::vector<int> jacob;
		std::vector<int> set;
		std::vector<int> main;
		std::vector<int> pend;
		std::vector<int> leftover;	
	public:
		PmergeMe(std::vector<int> &numbers);
		PmergeMe(const PmergeMe &obj);
		~PmergeMe();
		PmergeMe& operator=(const PmergeMe &obj);
		int	jacob_generator(int n);
		void display_set();
		void display_vector(std::vector<int> &vec);		
		void mergesort();
		void createpair();
		void init();
		void insertion();
		void swap(v_it begin1, v_it begin2, int order);

};

class Pair
{
	private:
		int A;
		int B;
		int num;
	public:

};



#endif