#ifndef TIME_PARSE_HPP
#define TIME_PARSE_HPP

#include <ctime>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>


class tp {
	public:
	using  Entry = std::pair<time_t, std::string>;
	using TimeMap = std::vector<Entry>;

	
	// Time format to be used by the time parser
	static const char* TIME_FORMAT;

	// Default time sruct item to facilitate deliberate use of references in related functions.
	static const std::tm DEFAULT_TIME_STRUCT;
	
	// Returns the time value from a string.
	static time_t getTimeFromStr(const std::string& str, const char* timeFmt = TIME_FORMAT);


	// Finds entries and returns views to them from an iterator range of a map-like object.
	/*template<typename It>
	inline std::vector<const Entry*> findEntries(It begin, It end, time_t min, time_t max) {
		return {};
	}*/


};

// Operator overloading for the Entry typedef for it to work in stl containers.
bool operator<(const tp::Entry& rhs, const time_t& lhs);
bool operator==(const tp::Entry& rhs, const time_t& lhs);
std::ostream& operator<<(std::ostream& out, const tp::Entry& entry);


#endif // !TIME_PARSE_HPP