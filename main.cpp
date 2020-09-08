// Pedro Escoboza
// A01251531
// 10/08/2020
// TC1031.501

#include "Algorithm.hpp"
#include "TimeParse.hpp"
#include "utilities.hpp"

namespace test {

	void quick_sort_test() {

		tp::TimeMap time_map{
			{ 4, "four" },
			{ 0, "zero" },
			{ 1, "one" },
			{ 2, "two" },
			{ 3, "three"}
		};

		std::cout << "Before:\n";
		ut::print_iterable(time_map, "\n");

		alg::quick_sort(time_map.begin(), time_map.end());

		std::cout << "After:\n";
		ut::print_iterable(time_map, "\n");


		const time_t KEY{ 60 };
		bool is_found{ alg::binary_search(time_map.begin(), time_map.end(), KEY) != time_map.end() };
		std::cout << "Searching: " << KEY << '\n' <<
			"Found: " << std::boolalpha << is_found << '\n';
	}

};

int main() {
	
}




#include <iostream>
#include <iterator>
#include <map>
#include <sstream>
#include <string>
#include <vector>

#include "fileio.hpp"





int main() {
	using ut::input;

	const char* INPUT_FILENAME{"bitacora.txt"};

	// Read the file
	std::vector<std::string> lines{fio::readLines(INPUT_FILENAME)};
	
	// Create the container with the hash map
	tp::TimeMap time_map;

	// Fill the container
	for (const auto& line : lines) {
		tp::add_entry(time_map, line);
	}

	// Sort the container
	alg::quick_sort(time_map.begin(), time_map.end());

	std::cout << "Time format: " << tp::TIME_FORMAT << std::endl;

	auto beginTime{ tp::getTimeFromStr(input("Enter begin time:")) };
	auto endTime{ tp::getTimeFromStr(input("Enter end time:")) };
	
	// Swap the values if necessary
	if (endTime < beginTime) {
		std::swap(beginTime, endTime);
	}

	// Retrieve the map entries in the given range
	auto entries{ tp::findEntriesInRange(time_map, beginTime, endTime) };

	// Case for no entries available
	if (entries.empty()) {
		std::cout << "No entries found in that time range." << std::endl;
	}
	else {
		// Print all the entries found
		for (const auto& entry : entries) {
			std::cout << entry->second << std::endl;
		}
	}


	std::cout << "\nPress ENTER to exit. " << std::endl;
	std::cin.get();

	return 0;
}