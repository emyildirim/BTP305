//Full Name  : Erkam Metin Yildirim
//Student ID#: 160235206
//Email      : eyildirim1@myseneca.ca
//Date       : 06/10/2023
 /*I have done all the coding by myself and only copied the code that
	my professor provided to complete my workshops and assignments.*/

#include <iostream>
#include <iomanip>
#include <string>
#include "Cheese.h"
//using namespace std;

namespace sdds {
	Cheese::Cheese() : m_name("NaC"), m_weight(0), m_pricePerGram(0) {
	} 

	Cheese::Cheese(const std::string& str) {
		std::string tmp = str;
		m_name = getName(tmp);
		m_weight = getWeight(tmp);
		m_pricePerGram = getPrice(tmp);
		m_features = getFeatures(tmp);
	}

	Cheese Cheese::slice(size_t weight) {
		int castedWeight = static_cast<int>(weight);
		if (castedWeight <= m_weight) {
			m_weight = m_weight - castedWeight;
			Cheese copy(*this);
			copy.m_weight = castedWeight;
			return copy;
		}
		else {
			return Cheese();
		}
	}

	std::ostream& operator<<(std::ostream& out, const Cheese& obj) {
		out << "|" << std::setw(21) << std::left << obj.m_name;
		out << "|" << std::setw(5) << obj.m_weight;
		out << "|" << std::setw(5) << std::fixed << std::setprecision(2) << obj.m_pricePerGram;
		out << "|" << std::setw(33) << std::right << obj.m_features << " |" << std::endl;
		return out;
	}

	std::string Cheese::getName(std::string& line)const {
		//find the index of 1st comma
		auto cutIndex = line.find_first_of(',', 0);
		//get the substr before the comma
		std::string substr = line.substr(0, cutIndex);
		eraseSpace(substr);
		return substr;
	}

	int Cheese::getWeight(std::string& line)const {
		//find the index of 1st comma (+ 1 to find the next comma)
		auto startIndex = line.find(',', 0) + 1;
		//find the counter: 2nd comma - 1st comma
		auto counter = line.find(',', startIndex) - startIndex;
		//get substr: start from the 1st comma and count 
		std::string substr = line.substr(startIndex, counter);
		eraseSpace(substr);
		return stoul(substr);
	}

	double Cheese::getPrice(std::string& line)const {
		//find the index of 2nd comma (+ 1 to find the next comma)
		auto startIndex = line.find(',', line.find(',', 0) + 1) + 1;
		//find the counter: 3nd comma - 2nd comma
		auto counter = line.find(',', startIndex) - startIndex;
		//get substr: start from the 2nd comma and count 
		std::string substr = line.substr(startIndex, counter);
		eraseSpace(substr);
		return stod(substr);
	}

	std::string Cheese::getFeatures(std::string& line)const {
		//find the index of 3rd comma (+ 1 to find the next comma)
		auto startIndex = line.find(',', line.find(',', line.find(',', 0) + 1) + 1) + 1;
		//find the counter: 3rd comma - length of the line
		auto counter = line.length() - startIndex;
		//get substr: start from the 3rd comma and count 
		std::string substr = line.substr(startIndex, counter);
		//erase ALL the spaces
		while (static_cast<int>(substr.find_first_of(' ', 0)) != - 1) { // npos = -1
			substr.erase(substr.find_first_of(' ', 0), 1);
		}
		//replace the comma with a space
		for (auto i = 0u; substr[i] != '\0'; ++i) {
			if (substr[i] == ',') {
				substr[i] = ' ';
			}
		}
		return substr;
	}

	void Cheese::eraseSpace(std::string& str)const {
		//erase all spaces from the beginning
		while (static_cast<int>(str.find_first_of(' ', 0)) != -1) { // npos = -1
			if (str[0] != ' ') {
				break;
			}
			str.erase(0, 1);
		}

		//erase all spaces from the end
		size_t len = str.length(); //after front erase
		while (static_cast<int>(str.find_last_of(' ', len)) != -1) { // npos = -1
			len--;
			if (str[len] != ' ') {
				break;
			}
			str.erase(len, 1);
		}
	}

	int Cheese::showWeight()const {
		return m_weight;
	}

	Cheese::Cheese(const Cheese& other) {
		m_name = other.m_name;
		m_weight = other.m_weight;
		m_pricePerGram = other.m_pricePerGram;
		m_features = other.m_features;
	}
}
