//Name: Yao Chen
//Student ID:134082197
//Date: Dec3, 2021
//Subject: OOP345 NAA MS3
//I have done all the coding by myself and only copied the code that my professor 
//provided to complete my workshops and assignments.

#include<algorithm>
#include<fstream>
#include<iostream>
#include "LineManager.h"
#include "Station.h"
#include "Utilities.h"

namespace sdds
{
	LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations)
	{
		try
		{
			std::string temp{};
			Utilities util{};

			std::ifstream input(file);
			if (!input)
				throw 3;

			while (getline(input, temp))
			{
				size_t l_next_pos = 0u;
				bool l_more = true;
				std::string l_firstName{}, l_nextName{};
				l_firstName = util.extractToken(temp, l_next_pos, l_more);
				if (l_more)
					l_nextName = util.extractToken(temp, l_next_pos, l_more);

				std::for_each(stations.begin(), stations.end(), [&](Workstation* station)
					{
						if (station->getItemName() == l_firstName)
						{
							for_each(stations.begin(), stations.end(), [&](Workstation* nextStation)
								{
									if (nextStation->getItemName() == l_nextName)
										station->setNextStation(nextStation);

								});
							activeLine.push_back(station);
						}
					});
				m_firstStation = activeLine.front();
			}
			m_cntCustomerOrder = pending.size();
		}
		catch (int i)
		{
			std::cout << "invalid file name!\n";
		}
		catch (...)
		{
			std::cout << "error in LineManager constructor!\n";
		}


	}
	void LineManager::linkStations()
	{
		std::vector<Workstation*> temp{};
		temp.push_back(m_firstStation);
		Workstation* station = activeLine.front();
		Workstation* pos{};
	
		while (station->getNextStation())
		{
			std::for_each(activeLine.begin(), activeLine.end(), [&](Workstation* nextStation)
				{
					if (station->getNextStation()->getItemName() == nextStation->getItemName())
					{
						temp.push_back(nextStation);
						pos = nextStation;
					}

				});
			station = pos;
		}

		activeLine = temp;
	}
	bool LineManager::run(std::ostream& os)
	{
		bool temp = false;
		static size_t count = 0;

		os << "Line Manager Iteration: " << ++count << "\n";

		if (!pending.empty())
		{
			*m_firstStation += std::move(pending.front());
			pending.pop_front();
		}
		
		std::for_each(activeLine.begin(), activeLine.end(), [&os](Workstation* station)
			{
				station->fill(os);
			});
		std::for_each(activeLine.begin(), activeLine.end(), [&os](Workstation* station)
			{
				station->attemptToMoveOrder();
			});

		if (m_cntCustomerOrder == (completed.size() + incomplete.size()))
			temp = true;

		return temp;
	}
	void LineManager::display(std::ostream& os) const
	{
		std::for_each(activeLine.begin(), activeLine.end(), [&os](Workstation* station)
			{
				station->display(os);
			});
	}
}