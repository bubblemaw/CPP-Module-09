/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 14:35:14 by maw               #+#    #+#             */
/*   Updated: 2025/11/15 22:32:04 by maw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

date::date()
{
	std::cout << "Default date constructor" <<  std::endl;
}

date::date(std::string input_date)
{
	std::cout << "string date constructor" <<  std::endl;
	_year = stoi(input_date.substr(0, 3));
	_month = stoi(input_date.substr(5, 2));
	_day = stoi(input_date.substr(8, 2));
}

date::date(const date &obj)
{
	std::cout << "Date copy constructor" <<  std::endl;	
	*this = obj;
}

date::~date()
{
	std::cout << "Date Destructor" <<  std::endl;	
}

date& date::operator=(const date &obj)
{
	std::cout << "Date Assignement operator" <<  std::endl;
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

bool date::operator<(const date &obj) const
{
	// if (this->getyear() < obj.getyear())
	// 	return true;
	// if (this->getmonth() < obj.getmonth())
	// 	return true;
	// if (this->getday() < obj.getday())
	// 	return true;
	return false;
}

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
