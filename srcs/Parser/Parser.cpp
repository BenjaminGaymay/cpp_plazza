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

	m_convert["PHONE_NUMBER"] = PHONE_NUMBER;
	m_convert["EMAIL_ADDRESS"] = EMAIL_ADDRESS;
	m_convert["IP_ADDRESS"] = IP_ADDRESS;
}

Plazza::Parser::~Parser()
{}

void Plazza::Parser::getInformation(std::string &information, std::string &fileName)
{
	g_file.lock();
	std::fstream file(fileName);
	std::string line;
	std::smatch match;
	std::regex pattern(m_pattern[information]);

	if (file.is_open()) {
		while (std::getline(file, line)) {
			if (std::regex_search(line, match, pattern)) {
				Log::writeLogs(m_convert[information], match[0]);
				break;
			}
		}
	}
	g_file.unlock();
}

void Plazza::Parser::test(std::string a)
{
	std::cout << a << " mdr" << std::endl;
}