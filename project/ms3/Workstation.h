// Name: Erkam Yildirim
// Seneca Student ID: 160235206
// Seneca email: eyildirim1@myseneca.ca
// Date of completion: 03/12/2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H

#include <deque>
#include <vector>
#include "Station.h"
#include "CustomerOrder.h"

//global variables
extern std::deque<sdds::CustomerOrder> g_pending;
extern std::deque<sdds::CustomerOrder> g_completed;
extern std::deque<sdds::CustomerOrder> g_incomplete;

namespace sdds {
	class Workstation : public Station
	{
		std::deque<CustomerOrder> m_orders;
		Workstation* m_pNextStation = nullptr;
	public:
		//custom 1-argument constructor
		Workstation(const std::string& ref) : Station(ref) {}
		//this modifier fills the order at the front of the queue
		void fill(std::ostream& os);
		//attempts to move the order order at the front of the queue to the next station in the assembly line
		bool attemptToMoveOrder();
		//stores the station param into m_pNextStation
		void setNextStation(Workstation* station);
		//this query returns the address of next Workstation
		Workstation* getNextStation() const;
		//insert the name of Item to os
		void display(std::ostream& os) const;
		//moves the CustomerOrder referenced in parameter newOrder to the back of the queue.
		Workstation& operator+=(CustomerOrder&& newOrder);

		//Copy or Move Not allowed
	};
}

#endif // !SDDS_WORKSTATION_H