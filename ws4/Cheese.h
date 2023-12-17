//Full Name  : Erkam Metin Yildirim
//Student ID#: 160235206
//Email      : eyildirim1@myseneca.ca
//Date       : 06/10/2023
 /*I have done all the coding by myself and only copied the code that
	my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_CHEESE_H
#define SDDS_CHEESE_H
#include <iostream>
namespace sdds {
	class Cheese
	{
		std::string m_name{ "NaC" }; // :Not a Cheese
		int m_weight;	//in grams
		double m_pricePerGram;
		std::string m_features;
	public:
		Cheese();
		Cheese(const std::string& str);
		Cheese slice(size_t weight);
		friend std::ostream& operator<<(std::ostream& out, const Cheese& obj);

		//Queries to retrieve the value of each attribute of the cheese.
		std::string getName(std::string& line)const;
		int getWeight(std::string& line)const;
		double getPrice(std::string& line)const;
		std::string getFeatures(std::string& line)const;
		void eraseSpace(std::string& str)const;

		int showWeight()const;
		Cheese(const Cheese& other);
	};
}

#endif // !SDDS_CHEESE_H

