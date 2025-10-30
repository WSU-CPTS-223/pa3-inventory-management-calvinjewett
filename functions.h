#pragma once
#include <string>
#include <vector>
#include <istream>

std::vector<std::string> parseCSVLine(const std::string& line);
std::vector<std::vector<std::string>> readCSV(std::istream& in);