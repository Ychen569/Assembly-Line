//Name: Yao Chen
//Student ID:134082197
//Date: Nov13, 2021
//Subject: OOP345 NAA MS1
//I have done all the coding by myself and only copied the code that my professor 
//provided to complete my workshops and assignments.

#include <string>
#include <iostream>
#include "Utilities.h"

namespace sdds
{
	char Utilities::m_delimiter = '\0';

	void Utilities::setFieldWidth(size_t newWidth)
	{
		m_widthField = newWidth;
	}
	size_t Utilities::getFieldWidth() const
	{
		return m_widthField;
	}
	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
	{
		std::string token{};
		size_t size = 0u;
		size_t pos_delim = str.find(m_delimiter, next_pos);
		size = pos_delim - next_pos;
		token = str.substr(next_pos, size);
		if (token != "")
		{
			if (size > token.length())
			{
				size = token.length();
				more = false;
			}
			else more = true;
			if (m_widthField < size)
				m_widthField = size;
			next_pos = pos_delim + 1;
		}
		else
		{
			more = false;
			throw "erro\n";

		}



		return token;
	}
	void Utilities::setDelimiter(char newDelimiter)
	{
		m_delimiter = newDelimiter;
	}
	char Utilities::getDelimiter()
	{
		return m_delimiter;
	}
}

