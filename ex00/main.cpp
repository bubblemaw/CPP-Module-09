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
	std::ifstream database("data.csv");
	std::string line;
	std::string number;
	float value;
	char sep;
	std::map<std::string, float> input_data;
	std::map<std::string, float> map_database;
	while (getline(database, line, ','))
	{
		if (getline(database, number))
			map_database[line] = stof(number);
	}
	std::map <std::string, float>::iterator itr;
	std::cout << "map size: " << map_database.size() << std::endl;
	for (itr = map_database.begin(); itr != map_database.end(); ++itr)
	{
		std::cout << itr->first << ' ' << itr->second << std::endl;
	}
	while (getline(input, line, '|'))
	{
		for (itr = map_database.begin(); itr != map_database.end(); ++itr)
		{
			std::cout<< "line: " << line << std::endl;
			std::cout<< "itr: " << itr->first << std::endl;			
			if (line == itr->first)
			{
				std::cout << "we found an occurence" << std::endl;
				break ;
			}
		}
	}		

	return (0);
}