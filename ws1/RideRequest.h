
//Full Name  : Erkam Metin Yildirim
//Student ID#: 160235206
//Email      : eyildirim1@myseneca.ca
//Date       : 16/09/23
 /*I have done all the coding by myself and only copied the code that
	my professor provided to complete my workshops and assignments.*/



#ifndef SDDS_RIDEREQUEST_H
#define SDDS_RIDEREQUEST_H
extern double g_taxrate;
extern double g_discount;
#include <iostream>
#include <fstream>
namespace sdds {
	class RideRequest
	{
		std::string m_name;
		std::string m_description;
		double m_price;
		bool m_discountFlag;

		// custom private member: counter for display()
		static int counter;
	public:
		RideRequest();
		void read(std::istream& is);
		void display();
	};
}

#endif // !SDDS_RIDEREQUEST_H

