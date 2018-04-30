/*
** EPITECH PROJECT, 2018
** cpp_plazza
** File description:
** Parser
*/

#pragma once

#include <iostream>
#include <regex>
#include <fstream>
#include <map>

namespace Plazza {
	class Parser {
	public:
		Parser();
		~Parser();

		std::string getInformation(std::string &information, std::string &file);

	private:
		std::map<std::string, std::string> m_pattern;
	};
}