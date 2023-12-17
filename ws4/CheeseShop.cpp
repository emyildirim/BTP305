//Full Name  : Erkam Metin Yildirim
//Student ID#: 160235206
//Email      : eyildirim1@myseneca.ca
//Date       : 06/10/2023
 /*I have done all the coding by myself and only copied the code that
	my professor provided to complete my workshops and assignments.*/

#include <iostream>
#include "Cheese.h"
#include "CheeseShop.h"

namespace sdds {
	CheeseShop::CheeseShop(const std::string& name) : m_name("No Name"), m_cheeses(nullptr), m_size(0) {
		m_name = name;
	}

	CheeseShop& CheeseShop::addCheese(const Cheese& obj) {

		Cheese** tmp = new Cheese* [m_size];
		int oldSize = m_size;
		//if cheeses in the shop exists make a cpy to tmp
		if (m_size != 0) {
			for (int i = 0; i < m_size; ++i) {
				tmp[i] = new Cheese(*m_cheeses[i]);
			}
		}

		//deallocate
		for (int i = 0; i < m_size; ++i)
			delete m_cheeses[i];
		delete[] m_cheeses;
		m_cheeses = nullptr;

		//allocate for new size
		m_size++;
		m_cheeses = new const Cheese* [m_size];
		m_cheeses[oldSize] = new Cheese(obj);

		if (m_size - 1 != 0){
			for (int i = 0; i < oldSize; ++i) {
				m_cheeses[i] = new Cheese(*tmp[i]);
			}
		}

		for (int i = 0; i < oldSize; ++i)
			delete tmp[i];
		delete[] tmp;
		return *this;
	}

	std::ostream& operator<<(std::ostream& out, const CheeseShop& obj) {
		out << "--------------------------\n";
		out << obj.m_name << "\n--------------------------\n";
		if (obj.m_size > 0 && obj.m_cheeses != nullptr) {
			for (int i = 0; i < obj.m_size; ++i) {
				out << *obj.m_cheeses[i];
			}
			out << "--------------------------\n";
		}
		else {
			out << "This shop is out of cheese!\n--------------------------\n";
		}
		return out;
	}

	CheeseShop::CheeseShop(const CheeseShop& other) {
		//deallocate
		for (int i = 0; i < m_size; ++i)
			delete m_cheeses[i];
		delete[] m_cheeses;
		//reallocate and set the size
		m_cheeses = new const Cheese* [other.m_size];
		m_size = other.m_size;
		m_name = other.m_name;
		//set the Cheese pointers
		for (int i = 0; i < other.m_size; ++i) {
			m_cheeses[i] = new Cheese(*other.m_cheeses[i]);
		}
	}

	CheeseShop& CheeseShop::operator=(const CheeseShop& other) {
		if (this != &other) {
			//deallocate
			for (int i = 0; i < m_size; ++i)
				delete m_cheeses[i];
			delete[] m_cheeses;
			//reallocate and set the size
			m_cheeses = new const Cheese * [other.m_size];
			m_size = other.m_size;
			m_name = other.m_name;
			//set the Cheese pointers
			for (int i = 0; i < other.m_size; ++i) {
				m_cheeses[i] = new Cheese(*other.m_cheeses[i]);
			}
		}
		return *this;
	}

	CheeseShop::CheeseShop(CheeseShop&& other) {
		//deallocate
		for (int i = 0; i < m_size; ++i)
			delete m_cheeses[i];
		delete[] m_cheeses;
		//add the new resources
		m_cheeses = other.m_cheeses;
		m_size = other.m_size;
		m_name = other.m_name;
		//destroy the other's resources
		other.m_cheeses = nullptr;
		other.m_size = 0;
		other.m_name = "";
	}

	CheeseShop& CheeseShop::operator=(CheeseShop&& other) {
		if (this != &other) {
			//deallocate
			for (int i = 0; i < m_size; ++i)
				delete m_cheeses[i];
			delete[] m_cheeses;
			//add the new resources
			m_cheeses = other.m_cheeses;
			m_size = other.m_size;
			m_name = other.m_name;
			//destroy the other's resources
			other.m_cheeses = nullptr;
			other.m_size = 0;
			other.m_name = "";
		}
		return *this;
	}

	CheeseShop::~CheeseShop() {
		if (m_cheeses != nullptr) {
			for (int i = 0; i < m_size; ++i)
				delete m_cheeses[i];
			delete[] m_cheeses;
		}
	}
}
