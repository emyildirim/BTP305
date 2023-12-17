//Full Name  : Erkam Metin Yildirim
//Student ID#: 160235206
//Email      : eyildirim1@myseneca.ca
//Date       : 09/11/2023
 /*I have done all the coding by myself and only copied the code that
	my professor provided to complete my workshops and assignments.*/

#include <algorithm>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <string>

#include "CovidCollection.h"

namespace sdds {
	//removes the spaces : for the file content
	std::string CovidCollection::removeSpaces(const std::string& str) {
		//find the first and last index of the place where it is not a space
		auto startPos = str.find_first_not_of(" ");
		auto endPos = str.find_last_not_of(" ");
		//if either of the pos is not valid and not found then str is empty
		if (startPos == std::string::npos || endPos == std::string::npos) {
			return "";
		}
		return str.substr(startPos, endPos - startPos + 1);
	}

	//Custom constructor
	CovidCollection::CovidCollection(const std::string& fileName) {
		std::ifstream file(fileName);

		if (file.fail()) {
			throw "Bad file [" + fileName + "]\n";
		}

		while (!file.fail()) {
			Covid city;
			std::string line;
			//get a line from the file until '\n'
			std::getline(file, line);

			
			try {
				//extract the country - 25 field
				city.m_country = removeSpaces(line.substr(0, 25));
				//extract the city - 25 field
				city.m_city = removeSpaces(line.substr(25, 25));
				//extract the variant - 25 field
				city.m_variant = removeSpaces(line.substr(50, 25));
				//extract the year - 5 field
				city.m_year = stoi(removeSpaces(line.substr(75, 5)));
				//extract the numOfCases - 5 field
				city.m_numOfCases = stoi(removeSpaces(line.substr(80, 5)));
				//extract the numOfDeaths - 5 field
				city.m_numOfDeaths = stoi(removeSpaces(line.substr(85, 5)));
				//push the covid structure into the collection
				m_collection.push_back(city);
			}
			catch (...) {

			}
		}
		file.close();
	}

	std::ostream& operator<<(std::ostream& out, const Covid& theCovid) {
		if (!theCovid.m_country.empty()) {
			out << "| " << std::setw(21) << std::left << theCovid.m_country
				<< " | " << std::setw(15) << theCovid.m_city
				<< " | " << std::setw(20) << theCovid.m_variant;
			//checks if the year is valid
			if (theCovid.m_year < 0) {
				out << " | " << std::setfill(' ') << std::setw(6) << std::right << ' ';
			}
			else {
				out << " | " << std::setw(6) << std::right << theCovid.m_year;
			}
			out << " | " << std::setw(4) << theCovid.m_numOfCases
				<< " | " << std::setw(3) << theCovid.m_numOfDeaths
				<< " | | " << std::setw(8) << theCovid.m_severityStatus << " |";
		}
		return out;
	}

	//PART 2-------
	//UPDATED : output to the screen by country
	void CovidCollection::display(std::ostream& out, const std::string& country) const {
		unsigned totalCases = 0;
		unsigned totalDeaths = 0;
		unsigned countryCases = 0;
		unsigned countryDeaths = 0;
		
		//calculate the total num of deaths according to the parameter country provided
		std::for_each(m_collection.begin(), m_collection.end(), [&](const Covid& covid) {
			if (covid.m_country == country) {
				countryCases += covid.m_numOfCases;
				countryDeaths += covid.m_numOfDeaths;
			}
			totalCases += covid.m_numOfCases;
			totalDeaths += covid.m_numOfDeaths;
		});
		
		//check if you need to print all or a specific country only
		if (country == "ALL") {
			std::for_each(m_collection.begin(), m_collection.end(), [&](Covid covid) {
				out << covid << '\n';
			});
			out << "| " << std::setw(79) << std::right << "Total cases around the world: " << totalCases << " |\n";
			out << "| " << std::setw(79) << std::right << "Total deaths around the world: " << totalDeaths << " |\n";
		}
		else {
			std::cout << "Displaying information of country = " << country << "\n";
			std::for_each(m_collection.begin(), m_collection.end(), [&](Covid covid) {
				if (covid.m_country == country) {
					out << covid << '\n';
				}
			});
			std::cout << "----------------------------------------------------------------------------------------\n";
			double percentageDeaths = static_cast<double>(countryDeaths) / totalDeaths * 100.0;
			double percentageCases = static_cast<double>(countryCases) / totalCases * 100;
			out << "| " << std::setw(78 - country.length()) << std::right << "Total cases in " << country << ": " << countryCases << " |\n";
			out << "| " << std::setw(78 - country.length()) << std::right << "Total deaths in " << country << ": " << countryDeaths<< " |\n";
			//manage the witdh needs to be set
			int width = 23;
			if (percentageCases >= 10.0 && percentageDeaths >= 10.0) {
				width -= 2;
					
			}
			else if (percentageCases >= 10.0 || percentageDeaths >= 10.0) {
				width -= 1;
			}
			else {
				//do nothing
			}
			out << "| " << std::setw(width) << std::right << country << " has "
				<< std::fixed << std::setprecision(6) << percentageCases << "% of global cases and "
				<< std::setprecision(6) << percentageDeaths << "% of global deaths |\n";
		}
	}

	//Sort the collection of Covid objects in ascending order
	void CovidCollection::sort(const std::string& field) {
		//sort the collection according to the field parameter
		if (field == "country") {
			std::sort(m_collection.begin(), m_collection.end(), [](const Covid& a, const Covid& b) {
				if (a.m_country == b.m_country) {
					return  a.m_numOfDeaths < b.m_numOfDeaths;
				}
				return a.m_country < b.m_country;
				});
		}
		else if (field == "variant") {
			std::sort(m_collection.begin(), m_collection.end(), [](const Covid& a, const Covid& b) {
				if (a.m_variant == b.m_variant) {
					return  a.m_numOfDeaths < b.m_numOfDeaths;
				}
				return a.m_variant < b.m_variant;
				});
		}
		else if (field == "year") {
			std::sort(m_collection.begin(), m_collection.end(), [](const Covid& a, const Covid& b) {
				if (a.m_year == b.m_year) {
					return  a.m_numOfDeaths < b.m_numOfDeaths;
				}
				return a.m_year < b.m_year;
			});
		}
		else {
			std::sort(m_collection.begin(), m_collection.end(), [](const Covid& a, const Covid& b) {
				return a.m_numOfDeaths < b.m_numOfDeaths;
			});
		}
	}

	//Search in the collection for a city in the specified country
	bool CovidCollection::inCollection(const std::string& variant, const std::string& country, unsigned int deaths) const {
		return std::any_of(m_collection.begin(), m_collection.end(), [&](const Covid& covid) {
			return covid.m_variant == variant && covid.m_country == country && covid.m_numOfDeaths > deaths;
		});
	}

	//Create and return a collection of Covid objects from the current instance
	std::list<Covid> CovidCollection::getListForDeaths(unsigned int deaths) const {
		std::list<Covid> result;
		//create a list from the Covid objects which num of deaths is greather than or equal to the parameter
		std::copy_if(m_collection.begin(), m_collection.end(), std::back_inserter(result), [&](const Covid& covid) {
			return covid.m_numOfDeaths >= deaths;
		});
		return result;
	}

	//updates the status of each city
	void CovidCollection::updateStatus() {
		//set severty status according to num of deaths
		std::for_each(m_collection.begin(), m_collection.end(), [](Covid& covid) {
			if (covid.m_numOfDeaths > 300) {
				covid.m_severityStatus = "EPIDEMIC";
			}
			else if (covid.m_numOfDeaths < 50) {
				covid.m_severityStatus = "EARLY";
			}
			else {
				covid.m_severityStatus = "MILD";
			}
		});
	}
}
