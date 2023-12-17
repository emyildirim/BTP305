//Full Name  : Erkam Metin Yildirim
//Student ID#: 160235206
//Email      : eyildirim1@myseneca.ca
//Date       : 04/11/2023
 /*I have done all the coding by myself and only copied the code that
	my professor provided to complete my workshops and assignments.*/

#include <iostream>
#include <iomanip>
#include <algorithm> // std::find()
#include "Directory.h"
#include "File.h"

namespace sdds {
	//Custom constructor
	Directory::Directory(const std::string& directoryName) : m_name(directoryName) {
	}
	//sets the parent path to the parameter.
	void Directory::update_parent_path(const std::string& path) {
		m_path = path;
	}
	//a query that returns Flags::DIR
	NodeType Directory::type() const {
		return NodeType::DIR;
	}
	//a query that returns the full absolute path of the directory
	std::string Directory::path() const {
		return m_path + m_name;
	}
	//a query that returns the name of the directory
	std::string Directory::name() const {
		return m_name;
	}
	//a query that returns the number of resources that this directory holds.
	int Directory::count() const {
		return static_cast<int>(m_contents.size());
	}
	//a query that returns the size of the directory in bytes. 
	size_t Directory::size() const {
		size_t totalSize = 0u;
		for (Resource* resource : m_contents) {
			totalSize += resource->size();
		}
		return totalSize;
	}
	//adds a resource to the directory and returns a reference to the current directory.
	Directory& Directory::operator+=(Resource* obj) {
		if (m_contents.size() != 0) {
			bool found = false;
			for (Resource* resource : m_contents) {
				if (resource->name() == obj->name()) {
					found = true;
				}
			}
			if (!found) {
				m_contents.push_back(obj);
				obj->update_parent_path(m_path + m_name);
			}
			else {
				throw "Same resource exist!";
			}
		}
		else {
			m_contents.push_back(obj);
			obj->update_parent_path(m_path + m_name);
		}
		return *this;
	}
	//finds and returns the address of a resource in the directory
	Resource* Directory::find(const std::string& name, const std::vector<OpFlags>& flags) {
		//checks if OpFlags::RECURSIVE is found in flags
		bool isRecursive = std::find(flags.begin(), flags.end(), OpFlags::RECURSIVE) != flags.end();

		for (Resource* resource : m_contents) {
			if (resource->name() == name) {
				return resource;
			}

			//checks if recursive flag exist and resource is a Directory
			if (isRecursive && dynamic_cast<Directory*>(resource) != nullptr) {
				Directory* subDirectory = dynamic_cast<Directory*>(resource);
				Resource* foundResource = subDirectory->find(name, flags);
				if (foundResource != nullptr) {
					return foundResource;  // Match found in the subdirectory, return the resource
				}
			}
		}
		return nullptr;
	}
	//Destructor
	Directory::~Directory() {
		for (Resource* resource : m_contents) {
			delete resource;
		}
	}

	//PART 2
	//deletes a resource from the directory whose name matches the first argument 
	void Directory::remove(const std::string& name, const std::vector<OpFlags>& flags) {

		//checks if OpFlags::RECURSIVE is found in flags
		bool isRecursive = std::find(flags.begin(), flags.end(), OpFlags::RECURSIVE) != flags.end();

		if (m_contents.size() != 0) {
			bool found = false;
			//count index
			int index = 0;
			for (auto resource : m_contents) {
				if (resource->name() == name) {
					found = true;
					if (resource->type() == NodeType::DIR && isRecursive) {
						//deallocate and remove it from the directory
						dynamic_cast<Directory*>(resource)->removeAll();
						delete resource;
						m_contents.erase(m_contents.begin() + index);
						return;
					}
					else if (resource->type() == NodeType::DIR && !isRecursive) {
						throw std::invalid_argument(name + " is a directory. Pass the recursive flag to delete directories.");
					}
					else {
						//deallocate and remove it from the directory
						delete resource;
						m_contents.erase(m_contents.begin() + index);
						return;
					}
				}
				index++;
			}
			if (!found) {
				throw std::string("NAME does not exist in " + m_path);
			}
		}
	}

	//display all the resources in the directory and add extra info according to flags
	void Directory::display(std::ostream& out, const std::vector<FormatFlags>& flags) const {
		
		//checks if FormatFlags::LONG is found in flags
		bool isLONG = std::find(flags.begin(), flags.end(), FormatFlags::LONG) != flags.end();
		
		out << "Total size: "<< this->size() << " bytes\n";
		for (auto resource : m_contents) {
			if (resource->type() == NodeType::DIR) {
				out << "D | " << std::setw(15) << std::left << resource->name() << " |";
				if (isLONG) {
					out << " " << std::setw(2) << std::right << resource->count() << " | " << std::setw(4) << std::right << resource->size() << " bytes | \n";
				}
				else {
					out << "\n";
				}
			}
			else {
				out << "F | " << std::setw(15) << std::left << resource->name() << " |";
				if (isLONG) {
					out << "    | " << std::setw(4) << std::right << resource->size() << " bytes | \n";
				}
				else {
					out << "\n";
				}
			}
		}
	}

	//removes all the files and directories in the dir
	void Directory::removeAll() {
		std::vector<OpFlags> flags = { OpFlags::RECURSIVE };
		int i = 0;
		while (m_contents.size() != 0) {
			this->remove(m_contents[i]->name(), flags);
		}
	}
}
