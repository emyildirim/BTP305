//Full Name  : Erkam Metin Yildirim
//Student ID#: 160235206
//Email      : eyildirim1@myseneca.ca
//Date       : 04/11/2023
 /*I have done all the coding by myself and only copied the code that
	my professor provided to complete my workshops and assignments.*/

#include <iostream>
#include <exception>
#include <fstream>
#include <string>
#include <vector>
#include "Filesystem.h"

namespace sdds {

	//removes the spaces : for the file content
	std::string Filesystem::removeSpaces(const std::string& str) {
		//find the first and last index of the place where it is not a space
		auto startPos = str.find_first_not_of(" ");
		auto endPos = str.find_last_not_of(" ");
		//if either of the pos is not valid and not found then str is empty
		if (startPos == std::string::npos || endPos == std::string::npos) {
			return "";
		}
		return str.substr(startPos, endPos - startPos + 1);
	}

	//create directories that does not exist one by one and add the file
	Directory* Filesystem::createDirStruct(const std::string& path, const std::string content) {
		std::string cursor;
		std::string Path = path;
		Directory* lastDir = m_root;

		//extract each directory and create it, if not exist
		while (Path.find_first_of("/", 0) != std::string::npos) {

			//get the closest directory to the m_root
			cursor = Path.substr(0, Path.find_first_of("/", 0) + 1);

			//search recursively if the directory exist already
			std::vector<OpFlags> flags;
			flags.push_back(sdds::OpFlags::RECURSIVE);
			auto found = m_root->find(cursor, flags);

			if (found != nullptr) {
				//set the found directory as the last dir
				lastDir = dynamic_cast<Directory*>(found);
			}
			else {
				//add the new created dir to the last dir we have
				Directory* dir = new Directory(cursor);
				*lastDir += dir;
				//set the created dir as the lastest dir
				lastDir = change_directory(dir->name());
			}
			Path.erase(0, Path.find_first_of("/", 0) + 1);
		}
		//add the file to the current
		if(content != ""){
			std::string fileName = Path;
			*lastDir += new File(fileName, content);
		}
		return lastDir;
	}

	//Custom constructor
	Filesystem::Filesystem(const std::string& filename, const std::string& root) {

		std::ifstream file(filename);

		//throw exception
		if (file.fail()) {
			delete m_root;
			throw "Bad file [" + filename + "]\n";
			return;
		}

		//create the top root and set the current directory to root
		m_root = new Directory(root);
		m_current = change_directory();
		std::string line;

		while (!file.fail()) {
			std::getline(file, line);

			//if there is no FILE* content - only directory exist
			if (line.find_first_of("|") == std::string::npos) {
				//get the directory root
				std::string dirPath = this->removeSpaces(line);
				
				//create the directory structure
				m_current = createDirStruct(dirPath);
			}
			else {
				//get the directory root and the file content
				std::string filePath = line.substr(0, line.find("|"));
				std::string content = line.substr(line.find("|") + 1, line.length() - line.find("|"));

				//remove spaces from the front and back
				filePath = this->removeSpaces(filePath);
				content = this->removeSpaces(content);

				m_current = createDirStruct(filePath, content);
			}
			//add the dir structure created to the current root
			m_current = change_directory();
		}
		file.close();
	}

	//Move constructor and Move operator
	Filesystem::Filesystem(Filesystem&& other) {
		delete m_root;
		delete m_current;
		//move the other's resources
		m_root = other.m_root;
		m_current = other.m_current;
		//reset the other's resources
		other.m_root = nullptr;
		other.m_current = nullptr;
	}
	Filesystem& Filesystem::operator=(Filesystem&& other) {
		if (this != &other) {
			delete m_root;
			delete m_current;
			//move the other's resources
			m_root = other.m_root;
			m_current = other.m_current;
			//reset the other's resources
			other.m_root = nullptr;
			other.m_current = nullptr;
		}
		return *this;
	}

	//adds a resource to the current directory.
	Filesystem& Filesystem::operator+=(Resource* obj) {
		Resource* found = m_current->find(obj->name());
		if (found != nullptr) {
			throw "The resource already exist";
		}
		else {
			*m_current += obj;
			found->update_parent_path(m_current->name() + obj->name());
		}
		return *this;

	}
	//changes the current directory to the directory
	Directory* Filesystem::change_directory(const std::string& current) {
		if (current == "") {
			m_current = m_root;
		}
		else {
			//search recursively if the directory exist already
			std::vector<OpFlags> flags;
			flags.push_back(sdds::OpFlags::RECURSIVE);
			auto found = m_root->find(current, flags);
			if (found == nullptr) {
				throw std::invalid_argument("Cannot change directory! " + current + " not found!");
			}
			else {
				m_current = dynamic_cast<Directory*>(found);
			}
			
		}
		return m_current;
	}
	//a query that returns the current directory.
	Directory* Filesystem::get_current_directory() const {
		return m_current;
	}
	//Destructor
	Filesystem::~Filesystem() {
		m_root->removeAll();
		delete m_root;
	}
}