//Full Name  : Erkam Metin Yildirim
//Student ID#: 160235206
//Email      : eyildirim1@myseneca.ca
//Date       : 13/10/2023
 /*I have done all the coding by myself and only copied the code that
	my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H

constexpr unsigned SIZE = 6; // size for statically allocate

namespace sdds {
	class SpellChecker
	{
		std::string m_badWords[SIZE];
		std::string m_goodWords[SIZE];
		static unsigned count[SIZE]; //count the bad word replacement
	public:
		SpellChecker(const char* filename);
		void operator()(std::string& text);
		void showStatistics(std::ostream& out) const;
	};
}

#endif // !SDDS_SPELLCHECKER_H

