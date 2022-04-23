//Name: Yao Chen
//Student ID:134082197
//Date: Dec3, 2021
//Subject: OOP345 NAA MS3
//I have done all the coding by myself and only copied the code that my professor 
//provided to complete my workshops and assignments.

#ifndef SDDS_LINEMANAGER_H
#define SDDS_LINEMANAGER_H

#include<vector>
#include<iostream>
#include "Workstation.h"

namespace sdds
{
	class LineManager
	{
		std::vector<Workstation*> activeLine{};
		size_t m_cntCustomerOrder = 0u;
		Workstation* m_firstStation{};

	public:
		LineManager(const std::string& file, const std::vector<Workstation*>& stations);
		void linkStations();
		bool run(std::ostream& os);
		void display(std::ostream& os) const;

	};

}

#endif // !SDDS_LINEMANAGER_H
