//Full Name  : Erkam Metin Yildirim
//Student ID#: 160235206
//Email      : eyildirim1@myseneca.ca
//Date       : 04/11/2023
 /*I have done all the coding by myself and only copied the code that
	my professor provided to complete my workshops and assignments.*/

#include <iostream>
#include <string>
#include "File.h"
namespace sdds {
	//Custom constructor
	File::File(const std::string& fileName, const std::string& contents) : m_name(fileName), m_contents(contents) {
	}
	//sets the parent path to the parameter.
	void File::update_parent_path(const std::string& path) {
		m_path = path;
	}

	//a query that returns Flags::FILE
	NodeType File::type() const {
		return NodeType::FILE;
	}
	//a query that returns the full absolute path of the file 
	std::string File::path() const {
		return m_path + m_name;
	}
	//a query that returns the name of the file.
	std::string File::name() const {
		return m_name;
	}
	//a query that returns -1
	int File::count() const {
		return -1;
	}
	//a query that returns the size of the file in bytes. For simplicity, this is the number of characters in m_contents attribute.
	size_t File::size() const {
		return m_contents.length();
	}
}