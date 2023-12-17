#include <iostream>
#include <fstream>
#include <deque>
#include "CustomerOrder.h"
#include "Station.h"
#include "Workstation.h"


//global variables
std::deque<sdds::CustomerOrder> g_pending;
std::deque<sdds::CustomerOrder> g_completed;
std::deque<sdds::CustomerOrder> g_incomplete;

namespace sdds {

	//custom 1-argument constructor
	//Workstation::Workstation(const std::string& ref) : Station(ref) {}
	
	//this modifier fills the order at the front of the queue
	void Workstation::fill(std::ostream& os) {
		//std::cout << "-> " << this->getItemName() << " : " << m_orders.size() << '\n';

		if (!m_orders.empty()) {
			m_orders.front().fillItem(*this, os);
		}
	}

	//attempts to move the order order at the front of the queue to the next station in the assembly line
	bool Workstation::attemptToMoveOrder() {
		
		if (!m_orders.empty() && (m_orders.front().isItemFilled(this->getItemName()) || this->getQuantity() == 0)) {
			//if there are no more stations left, consider it as complete or incomplete
			if (m_pNextStation) {
				*this->getNextStation() += std::move(m_orders.front());
				m_orders.pop_front();
			}
			else if (m_orders.front().isOrderFilled()) {
				g_completed.push_back(std::move(m_orders.front()));
				m_orders.pop_front();
				return true;
			}
			else {
				g_incomplete.push_back(std::move(m_orders.front()));
				m_orders.pop_front();
				return true;
			}
		}
		return false;
	}
	//stores the station param into m_pNextStation
	void Workstation::setNextStation(Workstation* station) {
		m_pNextStation = station;
	}
	//this query returns the address of next Workstation
	Workstation* Workstation::getNextStation() const {
		return m_pNextStation;
	}
	//insert the name of Item to os
	void Workstation::display(std::ostream& os) const {
		if (m_pNextStation) {
			os << getItemName() << " --> " << m_pNextStation->getItemName() << std::endl;
		}
		else {
			os << getItemName() << " --> End of Line" << std::endl;
		}
	}
	//moves the CustomerOrder referenced in parameter newOrder to the back of the queue.
	Workstation& Workstation::operator+=(CustomerOrder&& newOrder) {
		m_orders.push_back(std::move(newOrder));
		return *this;
	}
}
