#include <iostream>
#include <iomanip>
#include <fstream>
#include <string> //std::getline()
#include "RideRequest.h"

double g_taxrate;
double g_discount;

namespace sdds {

	RideRequest::RideRequest() {
		m_price = 0;
		m_discountFlag = false;
	}

	void RideRequest::read(std::istream& is) {
		if (!is.fail()) {
			char statusTmp = '\0'; //for discount
			std::getline(is, m_name, ',');
			std::getline(is, m_description, ',');
			is >> m_price;
			is.ignore(1000, ',');
			is >> statusTmp;
			is.ignore(1000, '\n');
			statusTmp == 'Y' ? m_discountFlag = true : m_discountFlag = false;
		}
	}

	int RideRequest::counter = 1;

	void RideRequest::display() {
		if (m_name[0] == '\0') {
			std::cout << counter << ". " << std::left << "No Ride Request" << std::endl;
		}
		else {
			double taxedPrice = m_price + (m_price * g_taxrate);	//calculate taxed price
			std::cout << std::left << std::setw(2) << counter << ". " << std::setw(10) << m_name;
			std::cout << "|" << std::setw(25) << m_description;
			std::cout << "|" << std::setprecision(2) << std::fixed << std::setw(12) << taxedPrice << "|";
			if (m_discountFlag) {
				double discountedPrice = taxedPrice - g_discount; // calculate discount
				std::cout << std::right << std::setw(13) << discountedPrice;
			}
			std::cout << std::endl;
		}
		counter++;
	}
}