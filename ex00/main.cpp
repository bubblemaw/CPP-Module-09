/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 14:35:08 by maw               #+#    #+#             */
/*   Updated: 2025/11/08 16:03:37 by maw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
		return ;
	std::ifstream input(av[1]);
	std::string line;
	std::vector<std::string> ville;
	while (getline(input, line))
	{
		ville.push_back(line);
	}
}