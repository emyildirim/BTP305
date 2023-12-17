// Name: Erkam Yildirim
// Seneca Student ID: 160235206
// Seneca email: eyildirim1@myseneca.ca
// Date of completion: 05/11/2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>
#include <string>
#include "Utilities.h"

namespace sdds {

	//initialize the class variable
	char Utilities::m_delimiter = {};

	//MEMBER FUNCTIONS
	// sets the field width of the current object to the value of parameter 
	void Utilities::setFieldWidth(size_t newWidth) {
		m_widthField = newWidth;
	}

	//returns the field width of the current object
	size_t Utilities::getFieldWidth() const {
		return m_widthField;
	}

	//extracts a token from string str referred to by the first parameter.
	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
		//get the token
		std::string token = "";
		auto pos = str.find_first_of(m_delimiter, next_pos);
		if (pos == next_pos) {
			more = false;
			throw "next position cannot be an index of a delimeter";
		}
		//if pos is valid
		if (pos != std::string::npos) {
			token = str.substr(next_pos, pos - next_pos);

			//REMOVE the spaces-----
			//find the first and last index of the place where it is not a space
			auto startPos = token.find_first_not_of(" ");
			auto endPos = token.find_last_not_of(" ");
			token = token.substr(startPos, endPos - startPos + 1);

			next_pos = pos + 1;
			more = true;
		}
		else {
			//at the end of the str
			token = str.substr(next_pos);
			auto startPos = token.find_first_not_of(" ");
			auto endPos = token.find_last_not_of(" ");
			token = token.substr(startPos, endPos - startPos + 1);
			next_pos = str.length();
			more = false;
		}
		if (m_widthField < token.length()) {
			m_widthField = token.length();
		}
		return token;
	}
}
