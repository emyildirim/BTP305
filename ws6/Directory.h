//Full Name  : Erkam Metin Yildirim
//Student ID#: 160235206
//Email      : eyildirim1@myseneca.ca
//Date       : 04/11/2023
 /*I have done all the coding by myself and only copied the code that
	my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_DIRECTORY_H
#define SDDS_DIRECTORY_H
#include <vector>
#include "Flags.h"
#include "Resource.h"

namespace sdds {
	class Directory : public Resource
	{
		std::string m_name = "/";
		std::vector<Resource*> m_contents{};
		std::string m_path = "/";
	public:
		//Custom constructor
		Directory(const std::string& directoryName = "/");
		//sets the parent path to the parameter.
		void update_parent_path(const std::string&);
		//a query that returns Flags::DIR
		NodeType type() const;
		//a query that returns the full absolute path of the directory
		std::string path() const;
		//a query that returns the name of the directory
		std::string name() const;
		//a query that returns the number of resources that this directory holds.
		int count() const;
		//a query that returns the size of the directory in bytes. 
		size_t size() const;
		//adds a resource to the directory and returns a reference to the current directory.
		Directory& operator+=(Resource*);
		//finds and returns the address of a resource in the directory
		Resource* find(const std::string&, const std::vector<OpFlags>& = {});
		//Destructor
		~Directory();

		//PART 2
		//deletes a resource from the directory whose name matches the first argument 
		void remove(const std::string&, const std::vector<OpFlags>& = {});
		//display all the resources in the directory and add extra info according to flags
		void display(std::ostream&, const std::vector<FormatFlags>& = {}) const;

		//removes all the files and directories in the dir
		void removeAll();
	};
}
#endif // !SDDS_DIRECTORY_H