//Full Name  : Erkam Metin Yildirim
//Student ID#: 160235206
//Email      : eyildirim1@myseneca.ca
//Date       : 28/09/2023
 /*I have done all the coding by myself and only copied the code that
    my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_ORDEREDCOLLECTION_H
#define SDDS_ORDEREDCOLLECTION_H
#include <iostream>
#include "Collection.h"
#include "Book.h"
namespace sdds {
	template <typename T>
	class OrderedCollection : public Collection<T, 72>
	{
	public:
		bool operator+=(const T& item) {
            unsigned size = Collection<T, 72>::size();
            if (size >= Collection<T, 72>::capacity()) {
                return false;
            }
            
            size++;
            if (size == 1) {
                (*this)[size-1] = item;
            }
            else {
                (*this)[size - 1] = item;
                for (unsigned i = 0; i < size; i++) {
                    for (unsigned j = 0; j < size - 1; j++) {
                        if ((*this)[j] > (*this)[j + 1]) {
                            T tmp = (*this)[j];
                            (*this)[j] = (*this)[j + 1];
                            (*this)[j + 1] = tmp;
                            //std::cout << (*this)[j] << std::endl;
                        }
                    }
                }
            }
            Collection<T, 72>::setSmallestItem(item);
            Collection<T, 72>::setLargestItem(item);
            Collection<T, 72>::incrSize();
            return true; 
		}
	};
}
#endif // !SDDS_ORDEREDCOLLECTION_H


