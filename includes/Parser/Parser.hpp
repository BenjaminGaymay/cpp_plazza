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
#include "macro.hpp"
#include "Fifo.hpp"

static std::mutex g_file;

namespace Plazza {
	class Parser {
	public:
		Parser();
		~Parser();

		void getInformation(std::string &information, std::vector<std::string> &files);
		void getInformationFromString(std::string &, std::vector<std::string> &);
		void getFilesFromString(std::vector<std::string> &, std::vector<std::string> &);

	private:
		std::map<std::string, std::string> m_pattern;
		std::map<std::string, Information> m_convert;
	};
}