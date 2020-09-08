#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <string>

namespace ut {
	
	template <typename Iterable>
	void print_iterable(const Iterable& container, const char* separator = " ", bool endline = true, std::ostream& out = std::cout) {
		for (const auto& v : container)
			out << v << separator;
		if (endline)
			out << '\n';
	}

	template <typename It>
	void print_iterable(It begin, It end, const char* separator = " ", bool endline = true, std::ostream& out = std::cout ) {
		if (begin < end) return;
		while (begin != end) {
			out << *begin << separator;
			++begin;
		}
		if (endline)
			out << '\n';
	}

	std::string input(const std::string& prompt = "", std::istream& in = std::cin, std::ostream& out = std::cout) {
		if (!prompt.empty()) {
			out << prompt << std::endl;
		}
		std::string str;
		std::getline(in, str);
		return str;
	}
}

#endif // !UTILS_HPP