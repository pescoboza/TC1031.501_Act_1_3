#ifndef TESTS_HPP
#define TESTS_HPP

#include "Algorithm.hpp"
#include "TimeParse.hpp"
#include "Utils.hpp"


namespace test {

	void quick_sort_test() {

		tp::TimeMap time_map{
			{4, "four"},
			{0, "zero"},
			{1, "one"},
			{2, "two"},
			{3, "three"},
		};

		std::cout << "Before:\n";
		ut::print_iterable(time_map, "\n");

		alg::quick_sort(time_map.begin(), time_map.end());

		std::cout << "After:\n";
		ut::print_iterable(time_map, "\n");


		const time_t KEY{ 4 };
		bool is_found{ alg::binary_search(time_map.begin(), time_map.end(), KEY) != time_map.end() };
		std::cout << "Searching: " << KEY << '\n' <<
			"Found:" << std::boolalpha << is_found << '\n';
	}

};

#endif // !TESTS_HPPs