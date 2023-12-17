//Full Name  : Erkam Metin Yildirim
//Student ID#: 160235206
//Email      : eyildirim1@myseneca.ca
//Date       : 13/10/2023
 /*I have done all the coding by myself and only copied the code that
	my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H

namespace sdds {
	class Movie
	{
		std::string m_title;
		int m_year;
		std::string m_description;
		//Add any other private member that is required by your design!
	public:
		Movie();
		const std::string& title() const;
		Movie(const std::string& strMovie);

		template<typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(m_title);
			spellChecker(m_description);
		}

		friend std::ostream& operator<<(std::ostream& out, const Movie& obj);

		Movie(const Movie& other);
		Movie& operator=(const Movie& other);
	};
}

#endif // !SDDS_MOVIE_H



