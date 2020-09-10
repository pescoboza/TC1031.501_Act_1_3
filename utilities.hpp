#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <memory>
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
			out << prompt;
		}
		std::string str;
		std::getline(in, str);
		return str;
	}

	template<typename ... Args>
	std::string string_format(const std::string& format, Args ... args)
	{
		size_t size = snprintf(nullptr, 0, format.c_str(), args ...) + 1; // Extra space for '\0'
		if (size <= 0) { throw std::runtime_error("Error during formatting."); }
		std::unique_ptr<char[]> buf(new char[size]);
		snprintf(buf.get(), size, format.c_str(), args ...);
		return std::string(buf.get(), buf.get() + size - 1); // We don't want the '\0' inside
	}
}

#endif // !UTILS_HPP