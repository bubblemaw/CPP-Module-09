/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 14:35:08 by maw               #+#    #+#             */
/*   Updated: 2025/11/17 15:28:32 by maw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	exchange matrice;
	matrice.calcul(av[1]);
	// std::ifstream input(av[1]);
	// float value;
	// char sep;
	// std::map<std::string, float> input_data;
	// std::map <std::string, float>::iterator itr;
	// for (itr = map_database.begin(); itr != map_database.end(); ++itr)
	// {
	// 	std::cout << itr->first << ' ' << itr->second << std::endl;
	// }

	

	return (0);
}