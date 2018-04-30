/*
** EPITECH PROJECT, 2018
** cpp_plazza
** File description:
** StringTools
*/

#pragma once

#include <vector>
#include <iostream>
#include <regex>

class StringTools {
public:
	StringTools();
	~StringTools();

	static std::vector<std::string> split(std::string &str, std::string delimiters = " ") {
		std::vector<std::string> tokens;

		std::string::size_type lastPos = str.find_first_not_of(delimiters, 0);
		std::string::size_type pos = str.find_first_of(delimiters, lastPos);
		while (std::string::npos != pos || std::string::npos != lastPos) {
			tokens.push_back(str.substr(lastPos, pos - lastPos));
			lastPos = str.find_first_not_of(delimiters, pos);
			pos = str.find_first_of(delimiters, lastPos);
		}
		return tokens;
	}

	static std::string lstrip(std::string &str, std::string delimiters = " \t\n\r\v\f") {
		str.erase(0, str.find_first_not_of(delimiters));
		return str;
	}

	static std::string rstrip(std::string &str, std::string delimiters = " \t\n\r\v\f") {
		str.erase(str.find_last_not_of(delimiters) + 1);
		return str;
	}
};
