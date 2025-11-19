/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 14:53:13 by maw               #+#    #+#             */
/*   Updated: 2025/11/19 22:34:20 by maw              ###   ########.fr       */
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
# include <limits>
# include <cmath>
# include <iomanip>


class exchange
{
	private:
		std::map<std::string, float> map_database;
	public:
		exchange();
		exchange(const exchange &obj);
		~exchange();
		exchange& operator=(const exchange &obj);
		void calcul(std::string file_input);
};

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
		// bool operator<(const date &obj) const;
		void setyear(int number);
		void setmonth(int number);
		void setday(int number);
		int getyear() const;
		int getmonth() const;
		int getday() const;


};
	bool operator<(const date &ob1, const date &ob2);
	bool operator>(const date &ob1, const date &ob2);
	bool operator<=(const date &ob1, const date &ob2);
	bool operator>=(const date &ob1, const date &ob2);		
	std::istream& operator>>(std::istream &in, date &obj);
	std::ostream& operator<<(std::ostream &out,const date &obj);
class FileNotOpen : public std::exception
{
	public:
		virtual const char *what() const throw()
		{
			return "Error: could not open file.";
		}
};

class unvalid_date : public std::exception
{
	public:
		virtual const char *what() const throw()
		{
			return "This date doesn't exist";
		}
};

class wrongformat : public std::exception
{
	public:
		virtual const char *what() const throw()
		{
			return "Bad input => ";
		}
};

class ex_too_large : public std::exception
{
	public:
		virtual const char *what() const throw()
		{
			return "Error: too large a number.";
		}
};

class ex_not_positive : public std::exception
{
	public:
		virtual const char *what() const throw()
		{
			return "Error: not a positive number.";
		}
};	

#endif 