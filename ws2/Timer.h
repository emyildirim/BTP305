//Full Name  : Erkam Metin Yildirim
//Student ID#: 160235206
//Email      : eyildirim1@myseneca.ca
//Date       : 22/09/2023
 /*I have done all the coding by myself and only copied the code that
	my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_TIMER_H
#define SDDS_TIMER_H
#include <chrono>
namespace sdds {
	class Timer
	{
		std::chrono::time_point<std::chrono::steady_clock> startT;
	public:
		void start();
		long long stop();
	};

}
#endif // !SDDS_TIMER_H
