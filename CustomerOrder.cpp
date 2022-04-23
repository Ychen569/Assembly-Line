//Name: Yao Chen
//Student ID:134082197
//Date: Nov28, 2021
//Subject: OOP345 NAA MS2
//I have done all the coding by myself and only copied the code that my professor 
//provided to complete my workshops and assignments.

#include<iostream>
#include<iomanip>
#include "CustomerOrder.h"
#include "Utilities.h"

namespace sdds
{
	size_t CustomerOrder::m_widthField = 0u;



	CustomerOrder::CustomerOrder()
	{
	}

	CustomerOrder::CustomerOrder(const std::string& str)
	{
		size_t l_next_pos = 0u;
		bool l_more = true;
		Utilities U{};
		if (l_more)
		{
			m_name = U.extractToken(str, l_next_pos, l_more);
			m_product = U.extractToken(str, l_next_pos, l_more);

			std::string temp{};
			size_t l_cntItem = 0u;
			temp = str.substr(l_next_pos, str.length() - l_next_pos + 1);
			for (auto i = 0u; i < temp.length(); ++i)
			{
				if (temp[i] == U.getDelimiter())
					l_cntItem++;
			}
			m_cntItem = l_cntItem + 1;
			m_lstItem = new Item * [m_cntItem];

			for (auto i = 0u; i < m_cntItem; ++i)
			{
				m_lstItem[i] = new Item(U.extractToken(str, l_next_pos, l_more));
			}
		}
		if (CustomerOrder::m_widthField < U.getFieldWidth())
			CustomerOrder::m_widthField = U.getFieldWidth();
		
	}

	CustomerOrder::CustomerOrder(const CustomerOrder& C)
	{
		throw 3;
	}

	CustomerOrder::CustomerOrder(CustomerOrder&& C)noexcept
	{
		*this = std::move(C);
	}
	//"promise"that it doesn't throw exceptions
	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& C)noexcept
	{
		if (this != &C)
		{
			for (auto i = 0u; i < m_cntItem; ++i)
			{
				delete m_lstItem[i];
			}
			delete[] m_lstItem;
			
			m_name = C.m_name;
			m_product = C.m_product;
			m_cntItem = C.m_cntItem;
			m_lstItem = C.m_lstItem;
			C.m_lstItem = nullptr;
			C.m_name = "";
			C.m_product = "";
			C.m_cntItem = 0u;


		}
		return *this;// TODO: insert return statement here
	}

	CustomerOrder::~CustomerOrder()
	{
		for (auto i = 0u; i < m_cntItem; ++i)
		{
			delete m_lstItem[i];
		}
		delete[] m_lstItem;
	}

	//return true if all items have been filled.
	bool CustomerOrder::isFilled() const
	{
		bool temp = true;
		for (auto i = 0u; i < m_cntItem&&temp== true; ++i)
		{
			if (m_lstItem[i]->m_isFilled == false)
				temp = false;
		}
		
		return temp;
	}

	//return true if the item with itemName has been filled.If the item doesn't exist in the order, return true.
	bool CustomerOrder::isItemFilled(const std::string& itemName) const
	{
		
		bool temp = true;
		for (auto i = 0u; i < m_cntItem; ++i)
		{
			if (itemName == m_lstItem[i]->m_itemName)
			{
				temp = m_lstItem[i]->m_isFilled;
				
			}
			
		}


		return temp;
	}

	void CustomerOrder::fillItem(Station& station, std::ostream& os)
	{
		for (auto i = 0u; i < m_cntItem; ++i)
		{
			if (station.getItemName() == m_lstItem[i]->m_itemName && m_lstItem[i]->m_isFilled == false)
			{
				if (station.getQuantity() >= 1)
				{
					m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
					m_lstItem[i]->m_isFilled = true;
					station.updateQuantity();
					os << "    Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]\n";
				}
				else os << "    Unable to fill " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]\n";
			}
		}
	}

	void CustomerOrder::display(std::ostream& os) const
	{
		os << m_name << " - " << m_product << std::endl;
		for (auto i = 0u; i < m_cntItem; ++i)
		{
			os << "[" << std::setw(6) << std::right << std::setfill('0') << m_lstItem[i]->m_serialNumber << "] ";
			os << std::setw(m_widthField) << std::setfill(' ') << std::left << m_lstItem[i]->m_itemName << " - ";
			os << (m_lstItem[i]->m_isFilled ? "FILLED\n" : "TO BE FILLED\n");
		}

	}

}
