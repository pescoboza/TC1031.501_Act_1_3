#include "Algorithm.hpp"
#include "TimeParse.hpp"

int main() {

	tp::TimeMap time_map{
		{4, "four"}
		{0, "zero"},
		{1, "one"},
		{2, "two"},
		{3, "three"},
		
	};

	return 0;
}


//// Pedro Escoboza
//// A01251531
//// 10/08/2020
//// TC1031.501
//
//#include <iostream>
//#include <iterator>
//#include <map>
//#include <sstream>
//#include <string>
//#include <vector>
//
//#include "fileio.hpp"
//
//
//
//std::string input(const std::string& prompt = "", std::istream& in = std::cin, std::ostream& out = std::cout) {
//	if (!prompt.empty()) {
//		out << prompt << std::endl;
//	}
//	std::string str;
//	std::getline(in, str);
//	return str;
//}
//
//int main() {
//	
//	const char* INPUT_FILENAME{"bitacora.txt"};
//
//	// Read the file
//	std::vector<std::string> lines{fio::readLines(INPUT_FILENAME)};
//	
//	// Create the container with the hash map
//	tp::TimeMap timeMap;
//
//	// Fill the container
//	for (const auto& line : lines) {
//
//		// Get the file line into a stream to output tokens
//		std::istringstream fullLine{ line };
//
//		// Token variables
//		std::string month;
//		std::string date;
//		std::string time;
//
//		// Extract the tokens
//		fullLine >> month;
//		fullLine >> date;
//		fullLine >> time;
//
//		// Convert the tokens to a time value
//		time_t timeValue{ tp::getTimeFromStr(month + " " + date + " " + time) };
//		
//		// Emplace the time and the log line into the container
//		timeMap.emplace(timeValue, line);
//
//	}
//
//	std::cout << "Time format: " << tp::TIME_FORMAT << std::endl;
//
//	auto beginTime{ tp::getTimeFromStr(input("Enter begin time:")) };
//	auto endTime{ tp::getTimeFromStr(input("Enter end time:")) };
//	
//	// Swap the values if necessary
//	if (endTime < beginTime) {
//		std::swap(beginTime, endTime);
//	}
//
//	// Retrieve the map entries in the given range
//	auto entries{ tp::findEntriesInRange(timeMap, beginTime, endTime) };
//
//	// Case for no entries available
//	if (entries.empty()) {
//		std::cout << "No entries found in that time range." << std::endl;
//	}
//	else {
//		// Print all the entries found
//		for (const auto& entry : entries) {
//			std::cout << entry->second << std::endl;
//		}
//	}
//
//
//	std::cout << "\nPress ENTER to exit. " << std::endl;
//	std::cin.get();
//
//	return 0;
//}