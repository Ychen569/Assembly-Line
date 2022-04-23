//Name: Yao Chen
//Student ID:134082197
//Date: Nov13, 2021
//Subject: OOP345 NAA MS1
//I have done all the coding by myself and only copied the code that my professor 
//provided to complete my workshops and assignments.


#ifndef SDDS_STATION_H
#define SDDS_STATION_H
#include<string>

namespace sdds
{
	class Station
	{
		size_t s_id = 0;
		std::string s_name{};
		std::string s_desc{};
		unsigned int s_serialNum = 0u;
		unsigned int s_num = 0u;
		static size_t m_widthField;
		static size_t id_generator;
	public:
		Station(const std::string& str);
		const std::string& getItemName()const;
		size_t getNextSerialNumber();
		size_t getQuantity()const;
		void updateQuantity();
		void display(std::ostream& os, bool full) const;



	};
}

#endif // SDDS_STATION_H



