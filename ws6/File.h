//Full Name  : Erkam Metin Yildirim
//Student ID#: 160235206
//Email      : eyildirim1@myseneca.ca
//Date       : 04/11/2023
 /*I have done all the coding by myself and only copied the code that
	my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_FILE_H
#define SDDS_FILE_H
#include "Flags.h"
#include "Resource.h"

namespace sdds {
	class File : public Resource
	{
		std::string m_name;
		std::string m_contents;
		std::string m_path = "/";
		//NOTE: Add any other function that is required by your design, but make sure they are private members!
	public:
		//Custom constructor
		File(const std::string& fileName, const std::string& content = "");
		//sets the parent path to the parameter.
		void update_parent_path(const std::string&);

		//a query that returns Flags::FILE
		NodeType type() const;
		//a query that returns the full absolute path of the file 
		std::string path() const;
		//a query that returns the name of the file.
		std::string name() const;
		//a query that returns -1
		int count() const;
		//a query that returns the size of the file in bytes. For simplicity, this is the number of characters in m_contents attribute.
		size_t size() const;
	};
}

#endif // !SDDS_FILE_H