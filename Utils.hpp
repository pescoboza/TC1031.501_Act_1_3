#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>

namespace ut {
	
	template <typename Iterable>
	inline void print_iterable(const Iterable& container, char separator = ' ', std::ostream& out = std::cout, bool endline = True) {
		for (const auto& v : container)
			out << v << separator;
		if (endline)
			out << '\n';
	}

	template <typename It>
	inline void print_iterable(It begin, It end, char separator = ' ', std::ostream& out = std::cout, bool endline = True) {
		if (begin < end) return;
		while (begin++ != end) 
			out << v << separator;
		if (endline)
			out << '\n';
	}
}

#endif // !UTILS_HPP