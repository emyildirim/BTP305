//Full Name  : Erkam Metin Yildirim
//Student ID#: 160235206
//Email      : eyildirim1@myseneca.ca
//Date       : 13/10/2023
 /*I have done all the coding by myself and only copied the code that
	my professor provided to complete my workshops and assignments.*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "SpellChecker.h"

namespace sdds {
	SpellChecker::SpellChecker(const char* filename) {
		std::ifstream file(filename);
			if (!file) {
				throw "Bad file name!\n";
			}
			else {
				std::string badWord;
				std::string goodWord;
				unsigned iter = 0;
				while (file && iter < SIZE) {

					std::getline(file, badWord, ' ');
					std::getline(file, goodWord, '\n');

					//erase all spaces
					while (goodWord.find(' ', 0) != std::string::npos) { // npos = -1
						goodWord.erase(goodWord.find_first_of(' ', 0), 1);
					}
					
					m_badWords[iter] = badWord;
					m_goodWords[iter] = goodWord;
					iter++;
				}
			}
	}

	//initialize the static variable
	unsigned SpellChecker::count[SIZE] = { 0 };

	void SpellChecker::operator()(std::string& text) {
		for (auto i = 0u; i < SIZE; i++) {
			std::size_t index = 0;
			while ((index = text.find(m_badWords[i], index)) != std::string::npos) {
				text.replace(index, m_badWords[i].length(), m_goodWords[i]);
				count[i]++;
				index += m_goodWords[i].length();
			}
		}
	}
	void SpellChecker::showStatistics(std::ostream& out) const {
		out << "Spellchecker Statistics\n";
		for (auto i = 0u; i < SIZE; ++i) {
			out << std::setw(15) << std::right << m_badWords[i];
			out << ": " << count[i] << " replacements" << std::endl;
		}
	}
}
