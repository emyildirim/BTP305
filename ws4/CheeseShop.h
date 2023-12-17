//Full Name  : Erkam Metin Yildirim
//Student ID#: 160235206
//Email      : eyildirim1@myseneca.ca
//Date       : 06/10/2023
 /*I have done all the coding by myself and only copied the code that
	my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_CHEESESHOP_H
#define SDDS_CHEESESHOP_H
#include <iostream>
#include "Cheese.h"
namespace sdds {
	/*Very Important : This class is responsible for
		managing both the array and the Cheese objects*/
	class Cheese;
	class CheeseShop
	{
		std::string m_name{""};
		const Cheese** m_cheeses{ nullptr };
		int m_size{ 0 };
	public:
		CheeseShop(const std::string& name);
		CheeseShop& addCheese(const Cheese&);

		//add any other special members that are necessary to manage the resources.
		friend std::ostream& operator<<(std::ostream& out, const CheeseShop& obj);
		CheeseShop(const CheeseShop& other);
		CheeseShop& operator=(const CheeseShop& other);
		CheeseShop(CheeseShop&& other);
		CheeseShop& operator=(CheeseShop&& other);
		~CheeseShop();
	};
}
#endif // !SDDS_CHEESESHOP_H

