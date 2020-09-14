#ifndef TIME_PARSE_HPP
#define TIME_PARSE_HPP

#include <ctime>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>


class tp {
	public:
	using  Entry = std::pair<time_t, std::string>; // Typedef for entry of the map.
	using TimeMap = std::vector<Entry>; // STL container used to store time entries.

	// Time format to be used by the time parser
	static const char* TIME_FORMAT;

	// Default time sruct item to facilitate deliberate use of references in related functions.
	static const std::tm DEFAULT_TIME_STRUCT;
	
	// Returns the time value from a string.
	static time_t getTimeFromStr(const std::string& str, const char* timeFmt = TIME_FORMAT);

	// Adds an entry to a
	static void add_entry(TimeMap& time_map, const std::string& line);

	// Returns the entry views of entries in inclusive range.
	static std::vector<const Entry*> get_entries(const TimeMap& time_map, time_t min, time_t max);
};

// Operator overloading for the Entry typedef for it to work in stl containers.
bool operator<(const tp::Entry& rhs, const time_t& lhs);
bool operator==(const tp::Entry& rhs, const time_t& lhs);
std::ostream& operator<<(std::ostream& out, const tp::Entry& entry);


#endif // !TIME_PARSE_HPP