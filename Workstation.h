//Name: Yao Chen
//Student ID:134082197
//Date: Dec3, 2021
//Subject: OOP345 NAA MS3
//I have done all the coding by myself and only copied the code that my professor 
//provided to complete my workshops and assignments.

#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H

#include <deque>
#include <iostream>
#include "CustomerOrder.h"

namespace sdds
{
	extern std::deque<CustomerOrder> pending;
	extern std::deque<CustomerOrder> completed;
	extern std::deque<CustomerOrder> incomplete;

	class Workstation : public Station
	{
		std::deque<CustomerOrder> m_orders{};
		Workstation* m_pNextStation{};

	public:
		Workstation(const std::string& line);
		Workstation(Workstation&& W) = delete;
		Workstation& operator=(Workstation&& W) = delete;
		Workstation(const Workstation& W) = delete;
		Workstation& operator=(const Workstation& W) = delete;
		
		void fill(std::ostream& os);
		bool attemptToMoveOrder();
		void setNextStation(Workstation* station =nullptr);
		Workstation* getNextStation() const;
		void display(std::ostream& os) const;
		Workstation& operator+=(CustomerOrder&& newOrder);
	};


}

#endif // !SDDS_WORKSTATION_H