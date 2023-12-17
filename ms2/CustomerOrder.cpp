// Name: Erkam Yildirim
// Seneca Student ID: 160235206
// Seneca email: eyildirim1@myseneca.ca
// Date of completion: 15/11/2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>
#include <string>
#include <iomanip>
#include "CustomerOrder.h"

namespace sdds {

	//initialize the static member
	size_t CustomerOrder::m_widthField = 0;

	//default constructor
	CustomerOrder::CustomerOrder() : m_name(""), m_product(""), m_cntItem(0), m_lstItem(nullptr){
	}
	//This constructor uses a local Utilities object to extract the tokens from the string and populate the current instance.
	CustomerOrder::CustomerOrder(const std::string& record) {
		Utilities util;
		bool more = true;
		size_t next_pos = 0;
		m_cntItem = 0;
		m_lstItem = nullptr;

		//extract from the line of data into an object
		m_name = util.extractToken(record, next_pos, more);
		m_product = util.extractToken(record, next_pos, more);
		while (more) {
			try {
				//extract each item to the list
				Item* obj = new Item(util.extractToken(record, next_pos, more));

				if (m_cntItem != 0) {
					//copy the existant items to tmp
					Item** tmp = new Item * [m_cntItem];
					for (size_t i = 0; i < m_cntItem; ++i) {
						tmp[i] = m_lstItem[i];
					}
					//deallocate and resize the list of items
					delete[] m_lstItem;
					m_lstItem = new Item * [m_cntItem + 1];

					//paste the copied items to the list
					for (size_t i = 0; i < m_cntItem; ++i) {
						m_lstItem[i] = tmp[i];
					}
					//add the new item and deallocate tmp
					m_lstItem[m_cntItem] = obj;
					m_cntItem++;
					delete[] tmp;
					
				}
				else {
					m_cntItem++;
					m_lstItem = new Item * [m_cntItem];
					m_lstItem[m_cntItem - 1] = obj;
				}
			}
			catch (...) {

			}
		}
		
		//get the lastest width field for outputting
		if (util.getFieldWidth() > m_widthField) {
			m_widthField = util.getFieldWidth();
		}
	}

	//copy constructor and operator not allowed - throw an exception
	CustomerOrder::CustomerOrder(const CustomerOrder&) {
		throw "Copy constructor not allowed";
	}

	//CustomerOrder& CustomerOrder::operator=(const CustomerOrder&) = delete;

	//move constructor and operator
	CustomerOrder::CustomerOrder(CustomerOrder&& other) noexcept {

		//move resources from other
		m_name = other.m_name;
		m_product = other.m_product;
		m_cntItem = other.m_cntItem;
		m_lstItem = other.m_lstItem;
		//destroy the resources of other
		other.m_cntItem = 0;
		
		other.m_lstItem = nullptr;
	}
	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& other) noexcept {
		if (this != &other) {

			//move resources from other
			for (size_t i = 0; i < m_cntItem; ++i) {
				delete m_lstItem[i];
			}
			delete[] m_lstItem;
		
			m_name = other.m_name;
			m_product = other.m_product;
			m_cntItem = other.m_cntItem;
			m_lstItem = other.m_lstItem;
			
		
			//destroy the resources of other
			other.m_cntItem = 0;
			other.m_lstItem = nullptr;
		}
		return *this;
	}

	//destructor
	CustomerOrder::~CustomerOrder() {
		for (size_t i = 0; i < m_cntItem; ++i) {
			delete m_lstItem[i];
		}
		delete[] m_lstItem;
	}
	//returns true if all the items in the order have been filled; false otherwise
	bool CustomerOrder::isOrderFilled() const {
		size_t cnt = 0;
		for (size_t i = 0; i < m_cntItem; ++i) {
			if (m_lstItem[i]->m_isFilled) {
				cnt++;
			}
		}
		if (cnt == m_cntItem) {
			return true;
		}
		return false;
	}
	//returns true if all items specified by itemName have been filled.
	bool CustomerOrder::isItemFilled(const std::string& itemName) const {
		int itemCnt = 0;
		int fillCnt = 0;
		for (size_t i = 0; i < m_cntItem; ++i) {
			if (m_lstItem[i]->m_itemName == itemName) {
				itemCnt++;
				if (m_lstItem[i]->m_isFilled) {
					fillCnt++;
				}
			}
		}
		//if items filled or if the item name not found
		if (itemCnt == fillCnt || itemCnt == 0) {
			return true;
		}
		return false;
	}
	// this modifier fills one item in the current order that the Station specified in the first parameter handles.
	void CustomerOrder::fillItem(Station& station, std::ostream& os) {
		for (size_t i = 0; i < m_cntItem; ++i) {
			if (m_lstItem[i]->m_itemName == station.getItemName() 
				&& !m_lstItem[i]->m_isFilled) {
				if (station.getQuantity() != 0) {
					//set item as filled and set serial number
					m_lstItem[i]->m_isFilled = true;
					m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
					
					//update the inventory
					station.updateQuantity();

					//print info
					os << "    Filled " << m_name << ", " << m_product << " [" << station.getItemName() << "]\n";
				}
				else {
					//print info
					os << "    Unable to fill " << m_name << ", " << m_product << " [" << station.getItemName() << "]\n";
				}
				return;
			}
		}
	}
	//this query displays the state of the current object in the format
	void CustomerOrder::display(std::ostream& os) const {
		os << m_name << " - " << m_product << '\n';
		for (size_t i = 0; i < m_cntItem; ++i) {
			os << "[" << std::setw(6) << std::setfill('0') << m_lstItem[i]->m_serialNumber;
			os	<< "] " << std::setw(m_widthField) << std::setfill(' ') << std::left << m_lstItem[i]->m_itemName << " - ";
			if (m_lstItem[i]->m_isFilled) {
				os << "FILLED\n";
			}
			else {
				os << "TO BE FILLED\n";
			}
		}
	}
}
