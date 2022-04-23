//Name: Yao Chen
//Student ID:134082197
//Date: Nov13, 2021
//Subject: OOP345 NAA MS1
//I have done all the coding by myself and only copied the code that my professor 
//provided to complete my workshops and assignments.


#include<string>
#include<iostream>
#include<iomanip>
#include "Station.h"
#include "Utilities.h"

namespace sdds
{
	size_t Station::m_widthField = 0u;
	size_t Station::id_generator = 0u;

	Station::Station(const std::string& str)
	{
		Utilities U{};
		size_t next_pos = 0u;
		bool more = true;

		s_name = U.extractToken(str, next_pos, more);
		s_serialNum = std::stoi(U.extractToken(str, next_pos, more));
		s_num = std::stoi(U.extractToken(str, next_pos, more));
		if (m_widthField < U.getFieldWidth())
			m_widthField = U.getFieldWidth();
		s_desc = U.extractToken(str, next_pos, more);

		++id_generator;
		s_id = id_generator;

	}
	const std::string& Station::getItemName() const
	{
		return s_name;
	}
	size_t Station::getNextSerialNumber()
	{
		return s_serialNum++;
	}
	size_t Station::getQuantity() const
	{
		return s_num;
	}
	void Station::updateQuantity()
	{
		if ((s_num - 1) >= 0)
			s_num--;
	}
	void Station::display(std::ostream& os, bool full) const
	{
		os << "[";
		os << std::right << std::setw(3) << std::setfill('0') << s_id;
		os << "] Item: ";
		os << std::left << std::setw(m_widthField) << std::setfill(' ') << s_name;
		os << " [" << std::right << std::setw(6) << std::setfill('0') << s_serialNum;
		os << "]";
		if (full == true)
		{
			os << " Quantity: " << std::left << std::setw(m_widthField) << std::setfill(' ') << s_num;
			os << " Description: " << s_desc;
		}
		os << std::endl;

	}
}
