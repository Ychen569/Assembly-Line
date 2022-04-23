//Name: Yao Chen
//Student ID:134082197
//Date: Nov28, 2021
//Subject: OOP345 NAA MS2
//I have done all the coding by myself and only copied the code that my professor 
//provided to complete my workshops and assignments.


#ifndef SDDS_CUSTOMERORDER_H
#define SDDS_CUSTOMERORDER_H

#include <string>
#include "Station.h"

namespace sdds
{

	struct Item
	{
		std::string m_itemName;
		size_t m_serialNumber{ 0 };
		bool m_isFilled{ false };

		Item(const std::string& src) : m_itemName(src)
		{
		};
	};
	class CustomerOrder
	{
		std::string m_name{};
		std::string m_product{};
		//a count of the number of items in the customer's order
		size_t m_cntItem = 0u;;
		Item** m_lstItem = nullptr;

		static size_t m_widthField;

	public:
		CustomerOrder();
		CustomerOrder(const std::string& str);
		CustomerOrder(const CustomerOrder& C);
		CustomerOrder& operator=(const CustomerOrder& C)= delete;
		CustomerOrder(CustomerOrder&& C)noexcept;
		CustomerOrder& operator=(CustomerOrder&& C)noexcept;
		~CustomerOrder();
		bool isFilled() const;
		bool isItemFilled(const std::string& itemName) const;
		void fillItem(Station& station, std::ostream& os);
		void display(std::ostream& os) const;

	};

}

#endif // !SDDS_CUSTOMERORDER_H


