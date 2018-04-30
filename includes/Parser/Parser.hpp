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
#include <mutex>
#include "Log.hpp"

static std::mutex g_file;

namespace Plazza {
	class Parser {
	public:
		Parser();
		~Parser();

		void getInformation(std::string &information, std::string &fileName);
		void test(std::string);

	private:
		std::map<std::string, std::string> m_pattern;
	};
}