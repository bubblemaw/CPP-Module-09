/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 14:35:14 by maw               #+#    #+#             */
/*   Updated: 2025/11/18 10:50:03 by maw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

date::date()
{
	// std::cout << "Default date constructor" <<  std::endl;
}

date::date(std::string input_date)
{
	// std::cout << "string date constructor" <<  std::endl;
	_year = stoi(input_date.substr(0, 3));
	_month = stoi(input_date.substr(5, 2));
	_day = stoi(input_date.substr(8, 2));
}

date::date(const date &obj)
{
	// std::cout << "Date copy constructor" <<  std::endl;	
	*this = obj;
}

date::~date()
{
	// std::cout << "Date Destructor" <<  std::endl;	
}

date& date::operator=(const date &obj)
{
	// std::cout << "Date Assignement operator" <<  std::endl;
	if (this != &obj)
	{
		this->_year = obj._year;
		this->_month = obj._month;
		this->_day = obj._day;				
	}
	return *this;	
}

void date::setyear(int number)
{
	this->_year = number;
}

void date::setmonth(int number)
{
	this->_month = number;
}

void date::setday(int number)
{
	this->_day = number;
}

int date::getyear() const
{
	return (this->_year);
}

int date::getmonth() const
{
	return (this->_month);
}

int date::getday() const
{
	return (this->_day);
}

bool valid_date(const date &obj)
{
	if (obj.getday() < 1 || obj.getday() > 31)
		throw unvalid_date();
	else if (obj.getmonth() > 0 && obj.getmonth() < 8)
	{
		if (obj.getmonth() % 2 != 0 && obj.getday() > 30)
			throw unvalid_date();
	}
	else if (obj.getmonth() > 7 && obj.getmonth() < 13)
	{
		if (obj.getmonth() % 2 != 0 && obj.getday() > 30)
			throw unvalid_date();
	}	
}

// bool date::operator<(const date &obj) const
// {
// 	// if (this->getyear() < obj.getyear())
// 	// 	return true;
// 	// if (this->getmonth() < obj.getmonth())
// 	// 	return true;
// 	// if (this->getday() < obj.getday())
// 	// 	return true;
// 	return false;
// }

std::istream& operator>>(std::istream &in, date &obj)
{
	int year, month, day;
	char sep1, sep2;

	// if (!in >> year)
	// 	return in;
	if (in >> year >> sep1 >> month >> sep2 >> day)
	{
		obj.setyear(year);
		obj.setmonth(month);
		obj.setday(day);
	}
	// else if (sep1 != '-') 
	// 	throw std::exception();
	// else if (sep2 != '-') 
	// 	throw std::exception();
	return in;
}

std::ostream& operator<<(std::ostream &out, const date &obj)
{
	out << obj.getyear() << "-"	<<
 		obj.getmonth() << "-" <<
		obj.getday() << " ";
	return out;
}

bool operator>(const date &ob1, const date &ob2)
{
	if (ob1.getyear() > ob2.getyear())
		return true;
	if (ob1.getyear() == ob2.getyear() && ob1.getmonth() > ob2.getmonth())
		return true;
	if (ob1.getmonth() == ob2.getmonth() && ob1.getday() > ob2.getday())
		return true;
	return false;	
}

bool operator<(const date &ob1, const date &ob2)
{
	if (ob1.getyear() < ob2.getyear())
		return true;
	if (ob1.getyear() == ob2.getyear() && ob1.getmonth() < ob2.getmonth())
		return true;
	if (ob1.getmonth() == ob2.getmonth() && ob1.getday() < ob2.getday())
		return true;
	return false;
}

bool operator<=(const date &ob1, const date &ob2)
{
	if (ob1.getyear() < ob2.getyear())
		return true;
	if (ob1.getyear() == ob2.getyear() && ob1.getmonth() < ob2.getmonth())
		return true;
	if (ob1.getmonth() == ob2.getmonth() && ob1.getday() < ob2.getday())
		return true;
	if (ob1.getyear() == ob2.getyear() && ob1.getmonth() == ob2.getmonth() && ob1.getday() == ob2.getday())
		return true;
	return false;
}

bool operator>=(const date &ob1, const date &ob2)
{
	if (ob1.getyear() > ob2.getyear())
		return true;
	if (ob1.getyear() == ob2.getyear() && ob1.getmonth() > ob2.getmonth())
		return true;
	if (ob1.getmonth() == ob2.getmonth() && ob1.getday() > ob2.getday())
		return true;
	if (ob1.getyear() == ob2.getyear() && ob1.getmonth() == ob2.getmonth() && ob1.getday() == ob2.getday())
		return true;
	return false;
}


exchange::exchange()
{
	std::cout << "Default exchange constructor" <<  std::endl;
	std::ifstream database("data.csv");	
	std::string line;
	std::string number;	
	while (getline(database, line, ','))
	{
		if (getline(database, number))
			map_database[line] = stof(number);
	}
	
}

exchange::exchange(const exchange &obj)
{
	std::cout << "exchange copy constructor" <<  std::endl;	
}

exchange::~exchange()
{
	std::cout << "exchange destructor" <<  std::endl;	
}

exchange& exchange::operator=(const exchange &obj)
{
	std::cout << "exchange assignement operator" <<  std::endl;
	return *this;
}

void	exchange::calcul(std::string file_input)
{
	std::string line;
	std::ifstream input(file_input);
	if (!input)
		std::cout << "could not open the file" << std::endl;
	date input_temp;
	date data_temp;
	std::map <std::string, float>::reverse_iterator itr;	
	while (getline(input, line, '|'))
	{
		std::cout << "rhe line: " << line << std::endl;
		for (itr = map_database.rbegin(); itr != map_database.rend(); ++itr)
		{
			input_temp = date(line);
			data_temp = date(itr->first);			
			if (data_temp <= input_temp)
			{
				std::cout << "WE FOUND THE LANE" << std::endl;
				if (getline(input, line))
				{
					std::cout << "the answer is: "<< stof(line) * itr->second << std::endl;
					break ;
				}
			}
			// std::cout << "looping" << std::endl;
		}
	}		
	
}