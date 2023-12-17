//Full Name  : Erkam Metin Yildirim
//Student ID#: 160235206
//Email      : eyildirim1@myseneca.ca
//Date       : 09/11/2023
 /*I have done all the coding by myself and only copied the code that
	my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_COVIDCOLLECTION_H
#define SDDS_COVIDCOLLECTION_H

#include <iostream>
#include <list>
#include <vector>

namespace sdds {

	//stores covid details for a particular city
	struct Covid {
		std::string m_country;
		std::string m_city;
		std::string m_variant;
		int m_year = 0;
		unsigned m_numOfCases = 0;
		unsigned m_numOfDeaths = 0;

		//Part 2
		std::string m_severityStatus = { "General" };
	};
	std::ostream& operator<<(std::ostream& out, const Covid& theCovid);

	class CovidCollection
	{
		std::vector<Covid> m_collection;
		//removes the spaces : for the file content
		std::string removeSpaces(const std::string& str);
	public:
		//Custom constructor
		CovidCollection(const std::string& fileName);
		//Part 2
		//UPDATED : output to the screen by country
		void display(std::ostream& out, const std::string& country = "ALL") const;
		//Sort the collection of Covid objects in ascending order
		void sort(const std::string& field = "country");
		//Search in the collection for a city in the specified country
		bool inCollection(const std::string& variant, const std::string& country, unsigned int deaths) const;
		//Create and return a collection of Covid objects from the current instance
		std::list<Covid> getListForDeaths(unsigned int deaths) const;
		//updates the status of each city
		void updateStatus();
	};

}
#endif // !SDDS_COVIDCOLLECTION_H