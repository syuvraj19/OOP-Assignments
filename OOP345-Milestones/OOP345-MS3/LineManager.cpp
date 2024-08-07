


#include <iostream>
#include <fstream>
#include <algorithm>
#include "LineManager.h"
#include "Utilities.h"

using namespace sdds;
using namespace std;

LineManager::LineManager(const string& file, const vector<Workstation*>& stations) {
	Utilities utility;

	ifstream input(file);
	if (!input.is_open()) {
		throw string("Unable to open file.");
	}


	string data;
	while (!input.eof())
	{
		getline(input, data);
		size_t pos = 0;
		bool more = true;
		string curStation, nextStation;
		curStation = utility.extractToken(data, pos, more);

		if (more) {
			nextStation = utility.extractToken(data, pos, more);
		}

		Workstation* curWorkstation = nullptr;
		Workstation* nextWorkstation = nullptr;
		for_each(stations.begin(), stations.end(), [&curWorkstation, &nextWorkstation, curStation, nextStation](Workstation* ws) {
			if (ws->getItemName() == curStation) {
				curWorkstation = ws;
			}
			else if (ws->getItemName() == nextStation) {
				nextWorkstation = ws;
			}
			});

		if (m_active_Line.size() == 0) {
			m_first_Station = curWorkstation;
		}

		curWorkstation->setNextStation(nextWorkstation);
		m_active_Line.push_back(curWorkstation);
	}

	input.close();

}

void LineManager::reorderStations() {
	vector<Workstation*> newStations;
	Workstation* lastStation = nullptr;
	unsigned int count = 0;
	while (count < m_active_Line.size()) {
		for (unsigned int i = 0; i < m_active_Line.size(); i++) {
			if (m_active_Line[i]->getNextStation() == lastStation) {
				newStations.push_back(m_active_Line[i]);
				lastStation = m_active_Line[i];
				count++;
				break;
			}
		}
	}
	reverse(newStations.begin(), newStations.end());
	m_first_Station = newStations[0];
	m_active_Line = newStations;
}

bool LineManager::run(ostream& os) {
	static int count = 0;
	count++;
	os << "Line Manager Iteration: " << count << endl;

	if (!g_pending.empty()) {
		(*m_first_Station) += move(g_pending.front());
		g_pending.pop_front();
	}

	for (unsigned int i = 0; i < m_active_Line.size(); i++) {
		m_active_Line[i]->fill(os);
	}

	for (unsigned int i = 0; i < m_active_Line.size(); i++) {
		m_active_Line[i]->attemptToMoveOrder();
	}

	bool isEmpty = true;
	for (unsigned int i = 0; i < m_active_Line.size(); i++) {
		if (!m_active_Line[i]->empty()) {
			isEmpty = false;
			break;
		}
	}

	return isEmpty;
}

void LineManager::display(ostream& os) const {
	for (unsigned int i = 0; i < m_active_Line.size(); i++) {
		m_active_Line[i]->display(os);
	}
}
