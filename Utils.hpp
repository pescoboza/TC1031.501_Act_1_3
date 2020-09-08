#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>

namespace ut {
	
	template <typename Iterable>
	inline void print_iterable(const Iterable& container, const char* separator = " ", bool endline = true, std::ostream& out = std::cout) {
		for (const auto& v : container)
			out << v << separator;
		if (endline)
			out << '\n';
	}

	template <typename It>
	inline void print_iterable(It begin, It end, const char* separator = " ", bool endline = true, std::ostream& out = std::cout ) {
		if (begin < end) return;
		while (begin != end) {
			out << *begin << separator;
			++begin;
		}
		if (endline)
			out << '\n';
	}
}

#endif // !UTILS_HPP