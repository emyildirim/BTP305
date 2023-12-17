//Full Name  : Erkam Metin Yildirim
//Student ID#: 160235206
//Email      : eyildirim1@myseneca.ca
//Date       : 13/10/2023
 /*I have done all the coding by myself and only copied the code that
	my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include <iostream>
#include <string>

namespace sdds {

	template<typename T>
	class Collection
	{
		std::string m_name{""};
		T* m_items;
		unsigned m_size;
		void (*m_observerF)(const Collection<T>&, const T&) = nullptr; // observer function reference
	public:
		Collection(const std::string& name);
		~Collection();
		const std::string& name() const;
		size_t size() const;
		void setObserver(void (*observer)(const Collection<T>&, const T&));
		Collection<T>& operator+=(const T& item);
		T& operator[](size_t idx) const;
		T* operator[](const std::string& title) const;

		//std::ostream& operator<<(std::ostream& os, const Collection<T>& obj);
	};

	template<typename T>
	Collection<T>::Collection(const std::string& name) : m_name(name), m_items(nullptr), m_size(0) {
	}

	template<typename T>
	Collection<T>::~Collection() {
		delete[] m_items;
	}

	template<typename T>
	const std::string& Collection<T>::name() const {
		return m_name;
	}

	template<typename T>
	size_t Collection<T>::size() const {
		return m_size;
	}

	template<typename T>
	void Collection<T>::setObserver(void (*observer)(const Collection<T>&, const T&)) {
		m_observerF = *observer;
	}

	template<typename T>
	Collection<T>& Collection<T>::operator+=(const T& item) {
		bool flag = true;
		if (m_items != nullptr && m_size > 0) {

			//check if the same title with the item exist
			for (auto i = 0u; i < m_size; ++i) {
				if (item.title().compare(m_items[i].title()) == 0){
					flag = false;
				}
			}
			if (flag) {
				T* tmp = new T[m_size];
				for (auto i = 0u; i < m_size; ++i) {
					tmp[i] = m_items[i];
				}
				//deallocate and resize
				delete[] m_items;
				m_items = new T[m_size + 1];
				for (auto i = 0u; i < m_size; ++i) {
					m_items[i] = tmp[i];
				}
				m_items[m_size] = item;
				m_size++;
				delete[] tmp;
				if (m_observerF != nullptr) {
					m_observerF(*this, item);
				}
			}
		}
		else {
			m_size++;
			m_items = new T[m_size];
			m_items[0] = item;
			if (m_observerF != nullptr) {
				m_observerF(*this, item);
			}
		}
		return *this;
	}

	template<typename T>
	T& Collection<T>::operator[](size_t idx) const {
		return m_items[idx];
	}

	template<typename T>
	T* Collection<T>::operator[](const std::string& title) const {
		int index = -1;
		for (auto i = 0u; i < m_size; ++i) {
			if (title.compare(m_items[i].title()) == 0) { ////PROBLEMM
				index = i;
			}
		}
		if (index != -1) {
			return &m_items[index];
		}
		return nullptr;
	}

	template<typename T>
	std::ostream& operator<<(std::ostream& os, const Collection<T>& obj) {
		for (auto i = 0u; i < obj.size(); ++i) {
			os << obj[i];
		}
		return os;
	}
}

#endif // !SDDS_COLLECTION_H

