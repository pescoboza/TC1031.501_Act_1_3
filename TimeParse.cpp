#include "TimeParse.hpp"

const char* tp::TIME_FORMAT{ "%b %d %H:%M:%S" };

const std::tm tp::DEFAULT_TIME_STRUCT{
	[]() {
		std::tm timeStruct;
		std::istringstream{ "10 Jan 2001 12:33:45" } >> std::get_time(&timeStruct, "%d %b %Y %H:%M:%S");
		return timeStruct;
	}()
};

time_t tp::getTimeFromStr(const std::string& str, const char* timeFmt) {
	std::istringstream ss{ str };
	std::tm timeStruct{ DEFAULT_TIME_STRUCT };
	ss >> std::get_time(&timeStruct, timeFmt);
	return std::mktime(&timeStruct);
}


bool operator<(const tp::Entry& rhs, const time_t& lhs) {
	return rhs.first < lhs;
}

bool operator==(const tp::Entry& rhs, const time_t& lhs) {
	return rhs.first == lhs;
}

std::ostream& operator<<(std::ostream& out, const tp::Entry& entry) {
	out << '(' << entry.first << ", " << entry.second << ')';
	return out;
}