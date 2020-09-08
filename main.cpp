// Pedro Escoboza
// A01251531
// 10/08/2020
// TC1031.501

#include <ctime>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <map>
#include <sstream>
#include <string>
#include <vector>

#include "fileio.hpp"

namespace tp {
	using TimeMap = std::map<time_t, std::string>;
	using Entry = std::pair<const time_t, std::string>;

	const char* TIME_FORMAT{ "%b %d %H:%M:%S" };
	const std::tm DEFAULT_TIME_STRUCT{
		[]() {
			std::tm timeStruct;
			std::istringstream{ "10 Jan 2001 12:33:45" } >> std::get_time(&timeStruct, "%d %b %Y %H:%M:%S");
			return timeStruct;
		}()
	};

	time_t getTimeFromStr(const std::string& str, const char* timeFmt = TIME_FORMAT) {
		std::istringstream ss{ str };
		std::tm timeStruct{DEFAULT_TIME_STRUCT};
		ss >> std::get_time(&timeStruct, timeFmt);
		return std::mktime(&timeStruct);
	}

	std::vector<const Entry*> findEntriesInRange(TimeMap& timeMap, const time_t& low, const time_t& high) {
		auto lowIt{ timeMap.lower_bound(low) };
		auto hightIt{ timeMap.upper_bound(high) };

		std::vector<const Entry*> entries;
		entries.reserve(std::distance(lowIt, hightIt));
		for (auto it{ lowIt }; it != hightIt; it++) {
			entries.push_back(&*it);
		}

		return entries;
	}
};


std::string input(const std::string& prompt = "", std::istream& in = std::cin, std::ostream& out = std::cout) {
	if (!prompt.empty()) {
		out << prompt << std::endl;
	}
	std::string str;
	std::getline(in, str);
	return str;
}

int main() {

	// Read the file
	std::vector<std::string> lines{fio::readLines("bitacora.txt")};
	
	// Create the container with the hash map
	tp::TimeMap timeMap;

	// Fill the container
	for (const auto& line : lines) {

		// Get the file line into a stream to output tokens
		std::istringstream fullLine{ line };

		// Token variables
		std::string month;
		std::string date;
		std::string time;

		// Extract the tokens
		fullLine >> month;
		fullLine >> date;
		fullLine >> time;

		// Convert the tokens to a time value
		time_t timeValue{ tp::getTimeFromStr(month + " " + date + " " + time) };
		
		// Emplace the time and the log line into the container
		timeMap.emplace(timeValue, line);

	}

	std::cout << "Time format: " << tp::TIME_FORMAT << std::endl;

	auto beginTime{ tp::getTimeFromStr(input("Enter begin time:")) };
	auto endTime{ tp::getTimeFromStr(input("Enter end time:")) };
	
	// Swap the values if necessary
	if (endTime < beginTime) {
		std::swap(beginTime, endTime);
	}

	// Retrieve the map entries in the given range
	auto entries{ tp::findEntriesInRange(timeMap, beginTime, endTime) };

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