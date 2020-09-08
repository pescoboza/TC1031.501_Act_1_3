#include "TimeParse.hpp"
#include "Algorithm.hpp"

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

void tp::add_entry(TimeMap& time_map, const std::string& line){
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
	time_map.emplace_back(timeValue, line);
}

std::vector<const tp::Entry*> tp::get_entries(const tp::TimeMap& time_map, time_t min, time_t max){
	auto begin{ time_map.begin() };
	auto end{ time_map.end() };
	
	if (begin == end) return {};
	
	auto min_it{ alg::binary_search(begin, end, min) };
	auto max_it{ alg::binary_search(begin, end, max) };
	++max_it;
	
	std::vector<const tp::Entry*> query_result;
	query_result.reserve(std::distance(min_it, max_it));
	for (; min_it != max_it; ++min_it) query_result.emplace_back(&*min_it);

	return query_result;
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