// Name: Erkam Yildirim
// Seneca Student ID: 160235206
// Seneca email: eyildirim1@myseneca.ca
// Date of completion: 05/11/2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>
#include <iomanip>
#include <string>
#include "Station.h"
#include "Utilities.h"

namespace sdds {

	//initialize the class variables
	size_t Station::m_widthField = 0;
	size_t Station::m_id_generator = 0;

	//custom 1-argument constructor
	Station::Station(const std::string& record) {
		Utilities util;
		bool more = true;
		size_t next_pos = 0;

		//extract from the line of data into an object
		m_id = ++m_id_generator;
		m_itemName = util.extractToken(record, next_pos, more);
		m_serialNumber = std::stoi(util.extractToken(record, next_pos, more));
		m_quantity = std::stoi(util.extractToken(record, next_pos, more));
		if (util.getFieldWidth() > m_widthField) {
			m_widthField = util.getFieldWidth();
		}
		m_description = util.extractToken(record, next_pos, more);
	}

	//returns the name of the current Station object
	const std::string& Station::getItemName() const {
		return m_itemName;
	}

	//returns the next serial number to be used on the assembly line and increments
	size_t Station::getNextSerialNumber() {
		return m_serialNumber++;
	}

	//returns the remaining quantity of items in the Station object
	size_t Station::getQuantity() const {
		return m_quantity;
	}
	//subtracts 1 from the available quantity; should not drop below 0.
	void Station::updateQuantity() {
		if (m_quantity != 0) {
			m_quantity--;
		}
	}

	//inserts information about the current object into stream os
	void Station::display(std::ostream& os, bool full) const {
		os << std::setw(3) << std::right << std::setfill('0') << m_id << " | "
			<< std::setw(m_widthField) << std::left << std::setfill(' ') << m_itemName << " | "
			<< std::setw(6) << std::right << std::setfill('0') << m_serialNumber << " | ";
		if (full != false) {
			os << std::setw(4) << std::right << std::setfill(' ') << m_quantity << " | "
				<< m_description;
		}
		os << '\n';
	}
}