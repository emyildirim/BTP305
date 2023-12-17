// Name: Erkam Yildirim
// Seneca Student ID: 160235206
// Seneca email: eyildirim1@myseneca.ca
// Date of completion: 05/11/2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H

namespace sdds {
	class Utilities
	{
		size_t m_widthField = 1;
		static char m_delimiter;
	public:
		//MEMBER FUNCTIONS
		// sets the field width of the current object to the value of parameter 
		void setFieldWidth(size_t newWidth);
		//returns the field width of the current object
		size_t getFieldWidth() const;
		//extracts a token from string str referred to by the first parameter.
		std::string extractToken(const std::string& str, size_t& next_pos, bool& more);

		//CLASS FUNCTIONS
		//sets the delimiter for this class to the character received
		static void setDelimiter(char newDelimiter) {
			m_delimiter = newDelimiter;
		}
		//returns the delimiter for this class.
		static char getDelimiter() {
			return m_delimiter;
		}
	};
}

#endif // !SDDS_UTILITIES_H