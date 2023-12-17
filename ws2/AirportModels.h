//Full Name  : Erkam Metin Yildirim
//Student ID#: 160235206
//Email      : eyildirim1@myseneca.ca
//Date       : 22/09/2023
 /*I have done all the coding by myself and only copied the code that
	my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_AIRPORTMODELS_H
#define SDDS_AIRPORTMODELS_H
#include <iostream>

namespace sdds {
	struct Airport{
		std::string m_code;
		std::string m_name;
		std::string m_city;
		std::string m_state;
		std::string m_country;
		double m_latitude;
		double m_longitude;
	public:
		Airport() : m_code(""), m_name(""), m_city(""), m_state(""), m_country(""), m_latitude(0.0), m_longitude(0.0) {}
		Airport(std::string code, std::string name, std::string city, std::string state, std::string country, double latitude, double longitude)
			: m_code(code), m_name(name), m_city(city), m_state(state), m_country(country), m_latitude(latitude), m_longitude(longitude) {}
		Airport& operator=(const Airport& other);
		friend std::ostream& operator<<(std::ostream& out, const Airport& obj);

	};

	class AirportLog
	{
		Airport* m_airports;
		int m_count;
	public:
		AirportLog() : m_airports(nullptr), m_count(0) {};
		AirportLog(const char* file);
		void addAirport(const Airport& obj);
		AirportLog findAirport(const char* state, const char* country) const;
		Airport operator[](size_t);
		operator size_t() const;

		AirportLog(const AirportLog&);
		AirportLog& operator=(const AirportLog&);
		~AirportLog();
		AirportLog(AirportLog&&);
		AirportLog& operator=(AirportLog&&);
	};

}

#endif // !SDDS_AIRPORTMODELS_H

