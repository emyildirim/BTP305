//Full Name  : Erkam Metin Yildirim
//Student ID#: 160235206
//Email      : eyildirim1@myseneca.ca
//Date       : 06/10/2023
 /*I have done all the coding by myself and only copied the code that
	my professor provided to complete my workshops and assignments.*/

#include <iostream>
#include "Cheese.h"
#include "CheeseShop.h"
#include "CheeseParty.h"

namespace sdds {
	CheeseParty::CheeseParty() : m_pCheeses(nullptr), m_pSize(0){
	}
	CheeseParty& CheeseParty::addCheese(const Cheese& obj) {
		if (m_pCheeses != nullptr && m_pSize > 0) {
			for (int i = 0; i < m_pSize; ++i) {
				if (&obj == m_pCheeses[i]) {
					return *this;
				}
			}
		}
		//shallow copy to tmp
		const Cheese** tmp = nullptr;
		if (m_pCheeses != nullptr && m_pSize > 0) {
			tmp = new const Cheese * [m_pSize];
			for (int i = 0; i < m_pSize; ++i) {
				tmp[i] = m_pCheeses[i];
			}
		}

		//deallocate
		if (m_pCheeses != nullptr && m_pSize > 0) {
			delete[] m_pCheeses;
		}
		//reallocate and resize
		m_pCheeses = new const Cheese * [m_pSize + 1];
		m_pCheeses[m_pSize] = &obj;
		//copy the pointers' addresses, not the parameters
		if (tmp != nullptr && m_pSize > 0) {
			for (int i = 0; i < m_pSize; ++i) {
				m_pCheeses[i] = tmp[i];
			}
			delete[] tmp;
		}
		m_pSize++;
		return *this;
	}
	CheeseParty& CheeseParty::removeCheese() {
			for (int i = 0; i < m_pSize; ++i) {
				if (m_pCheeses[i]->showWeight() == 0) {
					//remove the 0 weight cheese
					m_pCheeses[i] = nullptr;
					break;

					//shallow copy to tmp
					const Cheese** tmp = new const Cheese * [m_pSize-1];
					for (int i = 0; i < m_pSize; ++i) {
						tmp[i] = m_pCheeses[i];
					}
					//deallocate
					delete[] m_pCheeses;
					m_pSize--; //
					//reallocate and resize
					m_pCheeses = new const Cheese * [m_pSize-1];
					//copy the pointers' addresses, not the parameters
					for (int i = 0; i < m_pSize-1; ++i) {
						m_pCheeses[i] = tmp[i];
					}
					delete[] tmp;
				}
			}
		return *this;
	}

	std::ostream& operator<<(std::ostream& out, const CheeseParty& obj) {
		out << "--------------------------\n";
		out << "Cheese Party\n--------------------------\n";
		if (obj.m_pSize > 0 && obj.m_pCheeses != nullptr) {
			for (int i = 0; i < obj.m_pSize; ++i) {
				if (obj.m_pCheeses[i]) {
					out << *obj.m_pCheeses[i];
				}
			}
			out << "--------------------------\n";
		}
		else {
			out << "This party is just getting started!\n--------------------------\n";
		}
		return out;
	}

	CheeseParty::CheeseParty(const CheeseParty& other) {
		if (m_pCheeses != nullptr) {
			delete[] m_pCheeses;
		}
		m_pCheeses = new const Cheese * [other.m_pSize];
		m_pSize = other.m_pSize;

		//copy the pointers' addresses, not the parameters
		for (int i = 0; i < m_pSize; ++i) {
			m_pCheeses[i] = other.m_pCheeses[i];
		}
	}

	CheeseParty& CheeseParty::operator=(const CheeseParty& other) {
		if (this != &other) {
			if (m_pCheeses != nullptr) {
				delete[] m_pCheeses;
			}
			m_pCheeses = new const Cheese * [other.m_pSize];
			m_pSize = other.m_pSize;

			//copy the pointers' addresses, not the parameters
			for (int i = 0; i < m_pSize; ++i) {
				m_pCheeses[i] = other.m_pCheeses[i];
			}
		}
		return *this;
	}

	CheeseParty::CheeseParty(CheeseParty&& other) {
		if (m_pCheeses != nullptr) {
			delete[] m_pCheeses;
		}
		m_pCheeses = new const Cheese * [other.m_pSize];
		m_pSize = other.m_pSize;

		//copy the pointers' addresses, not the parameters
		for (int i = 0; i < m_pSize; ++i) {
			m_pCheeses[i] = other.m_pCheeses[i];
		}
		delete[] other.m_pCheeses;
		other.m_pCheeses = nullptr;
		other.m_pSize = 0;
	}

	CheeseParty& CheeseParty::operator=(CheeseParty&& other) {
		if (this != &other) {
			if (m_pCheeses != nullptr) {
				delete[] m_pCheeses;
			}
			m_pCheeses = new const Cheese * [other.m_pSize];
			m_pSize = other.m_pSize;

			//copy the pointers' addresses, not the parameters
			for (int i = 0; i < m_pSize; ++i) {
				m_pCheeses[i] = other.m_pCheeses[i];
			}
		}
		delete[] other.m_pCheeses;
		other.m_pCheeses = nullptr;
		other.m_pSize = 0;
		return *this;
	}

	CheeseParty::~CheeseParty() {
		if (m_pCheeses != nullptr) {
			delete[] m_pCheeses;
		}
	}
}
