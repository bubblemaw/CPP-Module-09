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

class Pair;

typedef std::vector<int>::iterator v_it;
typedef std::vector<Pair> pair_vec;
typedef pair_vec::iterator p_it;
// typedef std::vector<Pair>::iterator p_it;

class merge
{
	private:
		int comp = 0;
		int _order = 1;
		int _insertion;
		int _jacob;
		pair_vec jacob2;
		std::vector<int> set;
		std::vector<int> main;
		std::vector<int> pend;
		std::vector<int> leftover;
	public:
		merge(std::vector<int> &numbers);
		merge(const merge &obj);
		~merge();
		merge& operator=(const merge &obj);
		int	jacob_generator(int n);
		void display_vector(std::vector<int> &vec);
		void display_vector_pair(pair_vec&vec);
		void display_vector_pair_spec(pair_vec&vec);
		void set_pair(p_it &it, int j, bool A, bool B);
		void reset_all_pair(pair_vec &vec);
		void mergesort(std::vector<int> &vec);
		void createpair(std::vector<int> &vec);		
		void init();
		void insertion(std::vector<int> &pend, std::vector<int> &main);
		void swap(v_it begin1, v_it begin2, int order);
		void update_jacob(int *old_jacob, int *jacob, int *n, int *i);
		void insert_number(p_it &insert_place, p_it &b, int j, int *insertion);
		void insert_number_at_the_beginning(p_it &insert_place, p_it &b, int j, int *insertion);
		void skip_unneccessary_pairs(p_it &insert_place, p_it &b, int *j);
		void select_correct_pair_pend(p_it &b, int *jacob, int *old_jacob, int *n, int *i);
		void insert_right_place(p_it &b, p_it &insert_place, int *j, int *insertion);
};

class PmergeMe
{
	private:
		int comp = 0;
		int _order = 1;
		int _insertion;
		int _jacob;
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
		void display_vector(std::vector<int> &vec);
		void display_vector_pair(pair_vec&vec);
		void display_vector_pair_spec(pair_vec&vec);
		void set_pair(p_it &it, int j, bool A, bool B);
		void reset_all_pair(pair_vec &vec);
		void mergesort();
		void createpair_2();		
		void init_2();
		void insertion_2();
		void swap2(p_it begin1, p_it begin2, int order);
		void update_jacob(int *old_jacob, int *jacob, int *n, int *i);
		void insert_number(p_it &insert_place, p_it &b, int j, int *insertion);
		void insert_number_at_the_beginning(p_it &insert_place, p_it &b, int j, int *insertion);
		void skip_unneccessary_pairs(p_it &insert_place, p_it &b, int *j);
		void select_correct_pair_pend(p_it &b, int *jacob, int *old_jacob, int *n, int *i);
		void insert_right_place(p_it &b, p_it &insert_place, int *j, int *insertion);
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