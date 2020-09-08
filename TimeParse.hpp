#ifndef TIME_PARSE_HPP

#include <ctime>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>


namespace tp {
	using TimeMap = std::vector<std::pair<time_t, std::string>>;
	using Entry = std::pair<time_t, std::string>;



	// Time format to be used by the time parser
	const char* TIME_FORMAT{ "%b %d %H:%M:%S" };
	
	// Default time sruct item to facilitate deliberate use of references in related functions.
	const std::tm DEFAULT_TIME_STRUCT{
		[]() {
			std::tm timeStruct;
			std::istringstream{ "10 Jan 2001 12:33:45" } >> std::get_time(&timeStruct, "%d %b %Y %H:%M:%S");
			return timeStruct;
		}()
	};

	// Returns the time value from a string.
	time_t getTimeFromStr(const std::string& str, const char* timeFmt = TIME_FORMAT) {
		std::istringstream ss{ str };
		std::tm timeStruct{ DEFAULT_TIME_STRUCT };
		ss >> std::get_time(&timeStruct, timeFmt);
		return std::mktime(&timeStruct);
	}


	// Finds entries and returns views to them from an iterator range of a map-like object.
	template<typename It>
	inline std::vector<const Entry*> findEntries(It begin, It end, time_t min, time_t max) {
		return {};
	}



	//std::vector<const Entry*> findEntriesInRange(TimeMap& timeMap, const time_t& low, const time_t& high) {
	//	auto lowIt{ timeMap.lower_bound(low) };
	//	auto hightIt{ timeMap.upper_bound(high) };

	//	std::vector<const Entry*> entries;
	//	entries.reserve(std::distance(lowIt, hightIt));
	//	for (auto it{ lowIt }; it != hightIt; it++) {
	//		entries.push_back(&*it);
	//	}

	//	return entries;
	//}
};


std::ostream& operator<<(std::ostream& out, const tp::Entry& entry) {
	out << '(' << entry.first << ", " << entry.second << ')';
	return out;
}

bool operator<(const tp::Entry& rhs, const tp::Entry& lhs) {
	return rhs.first < lhs.first;
}


bool operator<(const tp::Entry& rhs, const time_t& lhs) {
	return rhs.first < lhs;
}

bool operator<(const time_t& rhs, const tp::Entry& lhs) {
	return rhs < lhs.first;
}

bool operator==(const tp::Entry& rhs, const time_t& lhs) {
	return rhs.first == lhs;
}

bool operator==(const time_t& rhs, const tp::Entry& lhs) {
	return rhs == lhs.first;
}
#endif // !TIME_PARSE_HPP