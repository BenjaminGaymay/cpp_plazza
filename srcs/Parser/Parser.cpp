/*
** EPITECH PROJECT, 2018
** cpp_plazza
** File description:
** Parser
*/

#include "Parser.hpp"

Plazza::Parser::Parser()
{
	m_pattern["EMAIL_ADDRESS"] = "(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))";
	m_pattern["IP_ADDRESS"] = "(\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}\\.\\d{1,3})";
	m_pattern["PHONE_NUMBER"] = "(\\d{10})";
}

Plazza::Parser::~Parser()
{}

void Plazza::Parser::getInformation(std::string &information, std::string &fileName)
{
	std::fstream file(fileName);
	std::string line;
	std::smatch match;
	std::regex pattern(m_pattern[information]);

	// while (g_file.try_lock() != true) {}
	if (file.is_open()) {
		while (std::getline(file, line)) {
			if (std::regex_search(line, match, pattern)) {
				std::cout << match[0] << std::endl;
				Log::writeLogs(match[0]);
			}
		}
	}
	// g_file.unlock();
}

void Plazza::Parser::test(std::string a)
{
	std::cout << a << " mdr" << std::endl;
}