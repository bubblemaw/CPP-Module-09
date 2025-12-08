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

class Pair;

typedef std::vector<int>::iterator v_it;
typedef std::vector<Pair> pair_vec;
typedef pair_vec::iterator p_it;
// typedef std::vector<Pair>::iterator p_it;


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
		pair_vec jacob2;
		pair_vec set2;
		pair_vec main2;
		pair_vec pend2;
		pair_vec leftover2;
	public:
		PmergeMe(std::vector<int> &numbers);
		PmergeMe(pair_vec numbers);		
		PmergeMe(const PmergeMe &obj);
		~PmergeMe();
		PmergeMe& operator=(const PmergeMe &obj);
		int	jacob_generator(int n);
		void display_set();
		void display_vector(std::vector<int> &vec);
		void display_vector_pair(pair_vec&vec);
		void mergesort();
		void createpair();
		void createpair_2();		
		void init();
		void insertion();
		void swap(v_it begin1, v_it begin2, int order);
		void swap2(p_it begin1, p_it begin2, int order);
};

	class Pair
	{
		private:
			bool A;
			bool B;
			int num_pair;
			int number;
			bool head;
		public:
			Pair(int n): number(n), A(false), B(false), num_pair(0), head(false){}
			void setA(bool set){A = set;}
			void setB(bool set){B = set;}
			void set_num_pair(int n){num_pair = n;}
			void set_number(int n){number = n;}
			void set_head(bool set){head = set;}
			bool getA(){return(A);}
			bool getB(){return(B);}
			int get_num_pair(){return(num_pair);}
			int get_number(){return(number);}
			bool get_head(){return(head);}		

	};		




#endif