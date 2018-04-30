/*
** EPITECH PROJECT, 2018
** cpp_plazza
** File description:
** Parser
*/

#include "Parser.hpp"

Plazza::Parser::Parser()
{
	m_pattern["EMAIL_ADDRESS"] = "(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+";
	m_pattern["IP_ADDRESS"] = "(\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}\\.\\d{1,3})";
	m_pattern["PHONE_NUMBER"] = "\\d{10}";

}

Plazza::Parser::~Parser()
{}

std::string Plazza::Parser::getInformation(std::string &information, std::string &fileName)
{
	std::fstream file(fileName);
	std::string line;
	std::smatch match;
	std::regex pattern(m_pattern[information]);

	if (file.is_open()) {
		while (std::getline(file, line)) {
			if (std::regex_search(line, match, pattern)) {
				return (match[0]);
			}
		}
	}
	return (nullptr);
}