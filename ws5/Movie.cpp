//Full Name  : Erkam Metin Yildirim
//Student ID#: 160235206
//Email      : eyildirim1@myseneca.ca
//Date       : 13/10/2023
 /*I have done all the coding by myself and only copied the code that
	my professor provided to complete my workshops and assignments.*/

#include <iostream>
#include <iomanip>
#include <string>
#include "Movie.h"

namespace sdds {
	Movie::Movie() : m_year(0){
	}
	const std::string& Movie::title() const {
		return m_title;
	}
	Movie::Movie(const std::string& strMovie) {
		std::string movie = strMovie;

		size_t comma1 = movie.find(',', 0) + 1;
		size_t comma2 = movie.find(',', comma1) + 1;
		auto len = movie.length();

		std::string title = movie.substr(0, comma1 - 1);
		std::string strYear = movie.substr(comma1, comma2 - comma1 - 1);
		std::string description = movie.substr(comma2, len - comma2);

		//erase all the spaces
		while (strYear.find(' ', 0) != std::string::npos) { // npos = -1
			strYear.erase(strYear.find(' ', 0), 1);
		}

		//erase front spaces
		bool f1 = 1, f2 = 1;
		while ((title.find(' ', 0) != std::string::npos || description.find(' ', 0) != std::string::npos)
			&& (f1 || f2)) { // npos = -1
			if (title[0] == ' ') {
				title.erase(0, 1);
			}
			else {
				f1 = 0;
			}
			if (description[0] == ' ') {
				description.erase(0, 1);
			}
			else {
				f2 = 0;
			}
		}

		//erase back spaces
		len = title.length(); //after front erase
		while (title.find_last_of(' ', len) != std::string::npos) { // npos = -1
			len--;
			if (title[len] != ' ') {
				break;
			}
			title.erase(len, 1);
		}

		m_title = title;
		m_year = stoul(strYear);
		m_description = description;
	}

	std::ostream& operator<<(std::ostream& out, const Movie& obj) {
		out << std::setw(40) << obj.m_title << " | ";
		out << std::setw(4) << obj.m_year << " | ";
		out << obj.m_description << std::endl;
		return out;
	}

	Movie::Movie(const Movie& other) {
		m_title = other.m_title;
		m_year = other.m_year;
		m_description = other.m_description;
	}
	Movie& Movie::operator=(const Movie& other) {
		if (this != &other) {
			m_title = other.m_title;
			m_year = other.m_year;
			m_description = other.m_description;
		}
		return *this;
	}
}
