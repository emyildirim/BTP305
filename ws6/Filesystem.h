//Full Name  : Erkam Metin Yildirim
//Student ID#: 160235206
//Email      : eyildirim1@myseneca.ca
//Date       : 04/11/2023
 /*I have done all the coding by myself and only copied the code that
	my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_FILESYSTEM_H
#define SDDS_FILESYSTEM_H
#include "File.h"
#include "Directory.h"
#include "Flags.h"

namespace sdds {
	class Filesystem
	{
		Directory* m_root = nullptr;
		Directory* m_current;

		//removes the spaces : for the file content
		std::string removeSpaces(const std::string& str);
		//create directories that does not exist one by one and add the file then return overall dir created
		Directory* createDirStruct(const std::string& path, const std::string content= "");

	public:
		//Custom constructor
		Filesystem(const std::string& filename, const std::string& root = "");

		//Move constructor and Move operator
		Filesystem(Filesystem&& other);
		Filesystem& operator=(Filesystem&& other);

		//adds a resource to the current directory.
		Filesystem& operator+=(Resource*);
		//changes the current directory to the directory
		Directory* change_directory(const std::string& = "");
		//a query that returns the current directory.
		Directory* get_current_directory() const;
		//Destructor
		~Filesystem();
	};
}
#endif // !SDDS_FILESYSTEM_H