// Name: Erkam Yildirim
// Seneca Student ID: 160235206
// Seneca email: eyildirim1@myseneca.ca
// Date of completion: 15/11/2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef SDDS_CUSTOMERORDER_H
#define SDDS_CUSTOMERORDER_H
#include "Station.h"

namespace sdds {

	struct Item
	{
		std::string m_itemName;
		size_t m_serialNumber{ 0 };
		bool m_isFilled{ false };

		Item(const std::string& src) : m_itemName(src) {};
	};

	class CustomerOrder
	{
		std::string m_name;
		std::string m_product;
		size_t m_cntItem;
		Item** m_lstItem;
		static size_t m_widthField;
	public:
		//default constructor
		CustomerOrder();
		//This constructor uses a local Utilities object to extract the tokens from the string and populate the current instance.
		CustomerOrder(const std::string& record);

		//copy constructor and operator not allowed - throw an exception
		CustomerOrder(const CustomerOrder&);
		CustomerOrder& operator=(const CustomerOrder&) = delete;

		//move constructor and operator
		CustomerOrder(CustomerOrder&&) noexcept;
		CustomerOrder& operator=(CustomerOrder&&) noexcept;

		//destructor
		~CustomerOrder();
		//returns true if all the items in the order have been filled; false otherwise
		bool isOrderFilled() const;
		//returns true if all items specified by itemName have been filled.
		bool isItemFilled(const std::string& itemName) const;
		// this modifier fills one item in the current order that the Station specified in the first parameter handles.
		void fillItem(Station& station, std::ostream& os);
		//this query displays the state of the current object in the format
		void display(std::ostream& os) const;
	};
}

#endif // !SDDS_CUSTOMERORDER_H