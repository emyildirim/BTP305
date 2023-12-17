// Name: Erkam Yildirim
// Seneca Student ID: 160235206
// Seneca email: eyildirim1@myseneca.ca
// Date of completion: 05/11/2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_STATION_H
#define SDDS_STATION_H

#include "Utilities.h"

namespace sdds {
	class Station
	{
		size_t m_id;
		std::string m_itemName;
		std::string m_description;
		size_t m_serialNumber;
		size_t m_quantity;
		static size_t m_widthField;  // = 0
		static size_t m_id_generator;// = 0
	public:
		//custom 1-argument constructor
		Station(const std::string&);
		//returns the name of the current Station object
		const std::string& getItemName() const;
		//returns the next serial number to be used on the assembly line and increments
		size_t getNextSerialNumber();
		//returns the remaining quantity of items in the Station object
		size_t getQuantity() const;
		//subtracts 1 from the available quantity; should not drop below 0.
		void updateQuantity();
		//inserts information about the current object into stream os
		void display(std::ostream& os, bool full) const;
	};
}

#endif // !SDDS_STATION_H