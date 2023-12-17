// Name: Erkam Yildirim
// Seneca Student ID: 160235206
// Seneca email: eyildirim1@myseneca.ca
// Date of completion: 03/12/2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Workstation.h"
#include"Utilities.h"
#include "LineManager.h"

namespace sdds {
	LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations) {

		std::ifstream File(file);
		m_activeLine = stations;
		std::string line;

		while (std::getline(File, line)) {

			Utilities util;
			bool more = true;
			size_t next_pos = 0;
			std::string nextStationName;

			try {
				//extract from the line of data into an object
				std::string stationName = util.extractToken(line, next_pos, more);
				if (more) {
					nextStationName = util.extractToken(line, next_pos, more);
				}

				auto it = std::find_if(m_activeLine.begin(), m_activeLine.end(), [&](const Workstation* station) {
					return station->getItemName() == stationName;
			    });
			    auto nextIt = std::find_if(m_activeLine.begin(), m_activeLine.end(), [&](const Workstation* station) {
			        return station->getItemName() == nextStationName;
			    });
				if (it != m_activeLine.end() && nextIt != m_activeLine.end()) {
				    (*it)->setNextStation(*nextIt);
					std::rotate(it, it + 1, m_activeLine.end());
				}
				else if (it != m_activeLine.end() && !(nextIt != m_activeLine.end())) {
					std::rotate(it, it + 1, m_activeLine.end());
				}
			}
			catch (...) {
				throw;
			}
		}
		File.close();

		m_cntCustomerOrder = g_pending.size();
		m_firstStation = m_activeLine[4];
	}

	void LineManager::reorderStations() {
		std::vector<Workstation*> tmpLine;
		Workstation* currStation = m_firstStation;

		while (currStation) {
			tmpLine.push_back(currStation);
			currStation = currStation->getNextStation();
		}

		m_activeLine = tmpLine;
	}
	bool LineManager::run(std::ostream& os) {
		static int cntIter = 0;
		os << "Line Manager Iteration: " << ++cntIter << std::endl;
		if (!g_pending.empty()) {
			*m_firstStation += std::move(g_pending.front());
			g_pending.pop_front();
		}

		//try to fill the orders by passing from each active station
		for (auto& station : m_activeLine) {
			station->fill(os);
		}

		//move the order to the next active station
		//or move the order to g_completed/g_incomplete
		for (auto& station : m_activeLine) {
			station->attemptToMoveOrder();
		}

		//if all orders has passed from all the active stations (m_activeLine)
		return ((g_incomplete.size() + g_completed.size()) == m_cntCustomerOrder);
	}

	void LineManager::display(std::ostream& os) const {
		for (const auto& station : m_activeLine) {
			station->display(os);
		}
	}
}