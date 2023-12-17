//Full Name  : Erkam Metin Yildirim
//Student ID#: 160235206
//Email      : eyildirim1@myseneca.ca
//Date       : 22/09/2023
 /*I have done all the coding by myself and only copied the code that
	my professor provided to complete my workshops and assignments.*/

#include <iostream>
#include <chrono>
#include "Timer.h"


namespace sdds {

	void Timer::start() {
		startT = std::chrono::steady_clock::now();
	}
	long long Timer::stop() {
		auto endT = std::chrono::steady_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(endT - startT);
		return duration.count();
	}
}
