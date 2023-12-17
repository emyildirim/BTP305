//Full Name  : Erkam Metin Yildirim
//Student ID#: 160235206
//Email      : eyildirim1@myseneca.ca
//Date       : 22/09/2023
 /*I have done all the coding by myself and only copied the code that
	my professor provided to complete my workshops and assignments.*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "AirportModels.h"

namespace sdds {

	//insertion operator to output
	std::ostream& operator<<(std::ostream& out, const Airport& obj) {
		if (obj.m_code.empty() || obj.m_latitude <= 0.0) {
			out << "Empty Airport";
		}
		else {
			out << std::setw(20) << std::setfill('.') << std::right << "Airport Code" << " : ";
			out << std::setw(30) << std::left << obj.m_code << std::endl;
			out << std::setw(20) << std::right << "Airport Name" << " : ";
			out << std::setw(30) << std::left << obj.m_name << std::endl;
			out << std::setw(20) << std::right << "City" << " : ";
			out << std::setw(30) << std::left << obj.m_city << std::endl;
			out << std::setw(20) << std::right << "State" << " : ";
			out << std::setw(30) << std::left << obj.m_state << std::endl;
			out << std::setw(20) << std::right << "Country" << " : ";
			out << std::setw(30) << std::left << obj.m_country << std::endl;
			out << std::setw(20) << std::right << "Latitude" << " : ";
			out << std::setw(30) << std::left << obj.m_latitude << std::endl;
			out << std::setw(20) << std::right << "Longitude" << " : ";
			out << std::setw(30) << std::left << obj.m_longitude << std::endl;
		}
		std::cout << std::setfill(' ');
		return out;
	}

	Airport& Airport::operator=(const Airport& other) {
		if (this != &other) {
			// create a deep copy of other's data
			m_code = other.m_code;
			m_name = other.m_name;
			m_city = other.m_city;
			m_state = other.m_state;
			m_country = other.m_country;
			m_latitude = other.m_latitude;
			m_longitude = other.m_longitude;

		}
		return *this;

	}

	//custom constructor
	AirportLog::AirportLog(const char* fileN) {
		std::ifstream file(fileN);
		//std::istream& file = f;  //done it to use std::getline() properly
		m_count = 0;
		std::string str;
		//counted num of airports
		while (!file.fail()) {
			std::getline(file, str, '\n');
			m_count++;
		}
		m_count = m_count - 2;
		//allocating the list of airports
		m_airports = new Airport[m_count];
		//adding the airports to the list from the file
		int iter = 0;
		//set the file cursor to the beginning // clear the flag
		file.clear();
		file.seekg(0);
		file.ignore(1000, '\n'); //ignore the first line
		for (int i = 0; i < m_count; i++) {
			std::getline(file, m_airports[iter].m_code, ',');
			std::getline(file, m_airports[iter].m_name, ',');
			std::getline(file, m_airports[iter].m_city, ',');
			std::getline(file, m_airports[iter].m_state, ',');
			std::getline(file, m_airports[iter].m_country, ',');
			file >> m_airports[iter].m_latitude;
			file.ignore(1000, ',');
			file >> m_airports[iter].m_longitude;
			file.ignore(1000, '\n');
			iter++;
		}

		file.close();
	}

	void AirportLog::addAirport(const Airport& obj) {
		//create tmp contanier
		Airport* tmp = new Airport[m_count];

		//hard copy to tmp
		if (m_airports != nullptr) {
			for (int i = 0; i < m_count; ++i) {
				tmp[i] = m_airports[i];
				
			}
			delete[] m_airports;
			m_airports = nullptr;
		}
		m_count++;
		m_airports = new Airport[m_count];

		if (m_airports != nullptr) {
			//hard copy to tmp
			for (int i = 0; i < m_count - 1; ++i) {
				m_airports[i] = tmp[i];
				
			}
		}
		// add the new airport
		m_airports[m_count - 1] = obj;
		
		delete[] tmp;
	}

	AirportLog AirportLog::findAirport(const char* state, const char* country)const {
		AirportLog temp;
		for (int i = 0; i < m_count; ++i) {
			if (m_airports[i].m_state.compare(state) == 0 
				&& m_airports[i].m_country.compare(country) == 0) {
				temp.addAirport(m_airports[i]);
			}
		}
		return temp;
	}

	Airport AirportLog::operator[](size_t index){
		if (m_airports != NULL) {
			return this->m_airports[index];
		}
		else {
			return Airport();
		}
	}

	AirportLog::operator size_t() const {
		return this->m_count;
	}


	AirportLog::AirportLog(const AirportLog& other) : m_count(other.m_count){
		if (other.m_count > 0) {
			m_airports = new Airport[other.m_count];
			m_count = other.m_count;
			*this = other;
		}
	}
	AirportLog& AirportLog::operator=(const AirportLog& other) {
		if (this != &other) {
			// release current resources
			if (m_airports != nullptr) {
				delete[] m_airports;
			}

			// create a deep copy of other's data
			if (other.m_count > 0) {
				m_airports = new Airport[other.m_count];
				m_count = other.m_count;
				for (int i = 0; i < m_count; ++i) {
					m_airports[i] = other.m_airports[i];
				}
			}
			else {
				m_airports = nullptr;
				m_count = 0;
			}
		}
		return *this;
	}
	AirportLog::~AirportLog() {
		if (m_airports != nullptr) {
			delete[] m_airports;
		}
	}
	//move constructor -- when you move the resources from 'other' it does not have it anymore
	AirportLog::AirportLog(AirportLog&& other) {
		// move other's resources
		m_airports = other.m_airports;
		m_count = other.m_count;

		// reset other's resources
		other.m_airports = nullptr;
		other.m_count = 0;
	}
	//move assignment
	AirportLog& AirportLog::operator=(AirportLog&& other){
		if (this != &other) {
			// release current resources
			delete[] m_airports;

			// move other's resources
			m_airports = other.m_airports;
			m_count = other.m_count;

			// reset other's resources
			other.m_airports = nullptr;
			other.m_count = 0;
		}
		return *this;
	}
}

