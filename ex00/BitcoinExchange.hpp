/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 14:53:13 by maw               #+#    #+#             */
/*   Updated: 2025/11/15 22:09:18 by maw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <iostream>
# include <istream>
# include <fstream>
# include <string>
# include <array>
# include <vector>
# include <map>
# include <exception>
# include <iterator>

class date
{
	private:
		int _year;
		int _month;
		int _day;
	public:
		date();
		date(std::string date);
		date(const date &obj);
		~date();
		date& operator=(const date &obj);
		bool operator<(const date &obj) const;
		void setyear(int number);
		void setmonth(int number);
		void setday(int number);
		int getyear() const;
		int getmonth() const;
		int getday() const;

	class FileNotOpen : public std::exception
	{
		public:
			virtual const char *what() const throw()
			{
				return "Couldn't open the file :(\n";
			}

	};
};
	std::istream& operator>>(std::istream &in, date &obj);
	std::ostream& operator<<(std::ostream &out,const date &obj);

#endif 