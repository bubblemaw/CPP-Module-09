/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 14:35:08 by maw               #+#    #+#             */
/*   Updated: 2025/11/15 22:33:49 by maw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	std::ifstream input(av[1]);
	date line;
	float value;
	char sep;
	std::map<date, float> input_data;
	std::map <date, float>::iterator itr;
	while (input >> line >> sep >> value)
	{
		input_data[line] = value;
		std::cout << "yo" << std::endl;
	}
	std::cout << input_data.size() << std::endl;
	for (itr = input_data.begin(); itr != input_data.end(); ++itr)
	{
		std::cout << itr->second << " " << itr->second << std::endl;
	}

	// std::map<int, std::string> myMap = {{1, "one"}, {2, "two"}, {3, "three"}};

	// // Get the first element
	// auto firstElement = myMap.begin();

	// // Access key and value
	// int firstKey = firstElement->first;      // 1
	// std::string firstValue = firstElement->second;  // "one"

	// // Alternative syntax
	// int firstKey2 = (*firstElement).first;
	// std::string firstValue2 = (*firstElement).second;


	return (0);
}