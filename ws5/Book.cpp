//Full Name  : Erkam Metin Yildirim
//Student ID#: 160235206
//Email      : eyildirim1@myseneca.ca
//Date       : 13/10/2023
 /*I have done all the coding by myself and only copied the code that
	my professor provided to complete my workshops and assignments.*/

#include <iostream>
#include <iomanip>
#include <string>
#include "Book.h"

namespace sdds {
	Book::Book() : m_year(0), m_price(0) {
	}
	const std::string& Book::title() const {
		return m_title;
	}
	const std::string& Book::country() const {
		return m_country;
	}
	const size_t& Book::year() const {
		return m_year;
	}
	double& Book::price() {
		return m_price;
	}
	Book::Book(const std::string& strBook) {
		std::string book = strBook;

		size_t comma1 = book.find(',', 0) + 1;
		size_t comma2 = book.find(',', comma1) + 1;
		size_t comma3 = book.find(',', comma2) + 1;
		size_t comma4 = book.find(',', comma3) + 1;
		size_t comma5 = book.find(',', comma4) + 1;
		auto len = book.length();

		std::string author = book.substr(0, comma1 - 1);
		std::string title = book.substr(comma1, comma2 - comma1 - 1);
		std::string country = book.substr(comma2, comma3 - comma2 - 1);
		std::string strPrice = book.substr(comma3, comma4 - comma3 - 1);
		std::string strYear = book.substr(comma4, comma5 - comma4 - 1);
		std::string description = book.substr(comma5, len - comma5);

		//erase all the spaces
		while (country.find(' ', 0) != std::string::npos) { // npos = -1
			country.erase(country.find(' ', 0), 1);
		}
		while (strYear.find(' ', 0) != std::string::npos) { // npos = -1
			strYear.erase(strYear.find(' ', 0), 1);
		}
		while (strPrice.find(' ', 0) != std::string::npos) { // npos = -1
			strPrice.erase(strPrice.find(' ', 0), 1);
		}

		//erase front spaces
		bool f1 = 1, f2 = 1, f3 = 0;
		while ((author.find(' ', 0) != std::string::npos || title.find(' ', 0) != std::string::npos
				|| description.find(' ', 0) != std::string::npos) && (f1 || f2 || f3)) { // npos = -1
			if (author[0] == ' ') {
				author.erase(0, 1);
			}
			else {
				f1 = 0;
			}
			if (title[0] == ' ') {
				title.erase(0, 1);
			}
			else {
				f2 = 0;
			}
			if (description[0] == ' ') {
				description.erase(0, 1);
			}
			else {
				f3 = 0;
			}
		}

		//erase back spaces
		len = author.length(); //after front erase
		while (author.find_last_of(' ', len) != std::string::npos) { // npos = -1
			len--;
			if (author[len] != ' ') {
				break;
			}
			author.erase(len, 1);
		}
		len = title.length(); //after front erase
		while (title.find_last_of(' ', len) != std::string::npos) { // npos = -1
			len--;
			if (title[len] != ' ') {
				break;
			}
			title.erase(len, 1);
		}

		m_title = title;
		m_country = country;
		m_author = author;
		m_year = stoul(strYear);
		m_price = stod(strPrice);
		m_description = description;
	}

	std::ostream& operator<<(std::ostream& out, const Book& obj) {
		out << std::setw(20) << std::right << obj.m_author << " | ";
		out << std::setw(22) << obj.m_title << " | ";
		out << std::setw(5) << obj.m_country << " | ";
		out << std::setw(4) << obj.m_year << " | ";
		out << std::setw(6) << std::right << std::fixed << std::setprecision(2) << obj.m_price << " | ";
		out << obj.m_description << std::endl;
		return out;
	}

	Book::Book(const Book& other) {
		m_author = other.m_author;
		m_title = other.m_title;
		m_country = other.m_country;
		m_year = other.m_year;
		m_price = other.m_price;
		m_description = other.m_description;
	}
	Book& Book::operator=(const Book& other) {
		if (this != &other) {
			m_author = other.m_author;
			m_title = other.m_title;
			m_country = other.m_country;
			m_year = other.m_year;
			m_price = other.m_price;
			m_description = other.m_description;
		}
		return *this;
	}
}
