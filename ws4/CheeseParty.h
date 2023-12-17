//Full Name  : Erkam Metin Yildirim
//Student ID#: 160235206
//Email      : eyildirim1@myseneca.ca
//Date       : 06/10/2023
 /*I have done all the coding by myself and only copied the code that
	my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_CHEESEPARTY_H
#define SDDS_CHEESEPARTY_H
#include <iostream>
#include "Cheese.h"
#include "CheeseShop.h"

namespace sdds {
	/*Very Important : This class is responsible for
		managing the array of pointers but is not 
		managing the life of Cheese objects.*/
	class Cheese;
	class CheeseParty
	{
		const Cheese** m_pCheeses{ nullptr };
		int m_pSize{ 0 };
	public:
		CheeseParty();
		CheeseParty& addCheese(const Cheese&);
		CheeseParty& removeCheese();

		//add any other special members that are necessary to manage the resource.
		friend std::ostream& operator<<(std::ostream& out, const CheeseParty& obj);
		CheeseParty(const CheeseParty& other);
		CheeseParty& operator=(const CheeseParty& other);
		CheeseParty(CheeseParty&& other);
		CheeseParty& operator=(CheeseParty&& other);
		~CheeseParty();
	};
}

#endif // !SDDS_CHEESEPARTY_H

