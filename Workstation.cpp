//Name: Yao Chen
//Student ID:134082197
//Date: Dec3, 2021
//Subject: OOP345 NAA MS3
//I have done all the coding by myself and only copied the code that my professor 
//provided to complete my workshops and assignments.

#include "Workstation.h"

namespace sdds
{
	std::deque<CustomerOrder>pending{};
	std::deque<CustomerOrder>incomplete{};
	std::deque<CustomerOrder>completed{};

	Workstation::Workstation(const std::string& line) : Station(line)
	{
	}
	void Workstation::fill(std::ostream& os)
	{
		if (m_orders.size() > 0)
			m_orders.front().fillItem(*this, os);

	}
	bool Workstation::attemptToMoveOrder()
	{
		bool temp = false;

		if (m_orders.empty())
			temp = true;
		else
		{
			if (m_orders.front().isItemFilled(getItemName()) || getQuantity() == 0)
			{
				if (m_pNextStation != nullptr)
				{
					*m_pNextStation += std::move(m_orders.front());
				}
				else
					if (m_orders.front().isFilled())
						completed.push_back(std::move(m_orders.front()));
					else incomplete.push_back(std::move(m_orders.front()));

				m_orders.pop_front();
				temp = true;

			}
			
		}

		return temp;
	}
	void Workstation::setNextStation(Workstation* station)
	{
		m_pNextStation = station;
	}
	Workstation* Workstation::getNextStation() const
	{
		return m_pNextStation;
	}
	void Workstation::display(std::ostream& os) const
	{
		if (m_pNextStation == nullptr)
			os << getItemName() << " --> End of line";
		else
			os << getItemName() << " --> " << m_pNextStation->getItemName();
		os << "\n";

	}


	//move "newOrder" to the back of the queue
	Workstation& Workstation::operator+=(CustomerOrder&& newOrder)
	{
		m_orders.push_back(std::move(newOrder));
		
		return *this;
	}
}