//Full Name  : Erkam Metin Yildirim
//Student ID#: 160235206
//Email      : eyildirim1@myseneca.ca
//Date       : 13/10/2023
 /*I have done all the coding by myself and only copied the code that
	my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include "SpellChecker.h"

namespace sdds {
	class Book
	{
		std::string m_author;
		std::string m_title;
		std::string m_country; // the country of publication
		size_t m_year;
		double m_price;
		std::string m_description;
	public:
		Book();
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		Book(const std::string& strBook);

		friend std::ostream& operator<<(std::ostream& out, const Book& obj);
		//part 2
		template<typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(m_description);
		}

		Book(const Book& other);
		Book& operator=(const Book& other);
	};
}

#endif // !SDDS_BOOK_H

