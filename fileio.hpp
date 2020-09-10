// Pedro Escoboza
// A01251531
// 14/04/2020
// TC1030.1


#ifndef FILE_IO_HPP
#define FILE_IO_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <stdexcept>

namespace fio {
	std::vector<std::string> readLines(const char* filename, unsigned numLines = 0U);
	std::stringstream readFile(const char* filename);
	bool writeLines(const char* filename, const std::vector<std::string>& lines);
	bool writeLines(const char* filename, const std::vector<std::string*>& lines);
	bool writeLines(const char* filename, const std::vector<const std::string*>& lines);
};

#endif // !FILE_IO_HPP