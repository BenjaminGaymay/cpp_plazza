/*
** EPITECH PROJECT, 2018
** cpp_plazza
** File description:
** Parser
*/

#include "Parser.hpp"

Plazza::Parser::Parser()
{
	m_pattern["EMAIL_ADDRESS"] = "[a-zA-Z0-9_.-]+@[a-zA-Z0-9_.-]+";
	m_pattern["IP_ADDRESS"] = "(\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}\\.\\d{1,3})";
	m_pattern["PHONE_NUMBER"] = "(\\d{10})|((\\d{2} ){4}\\d{2})";

	m_convert["PHONE_NUMBER"] = PHONE_NUMBER;
	m_convert["EMAIL_ADDRESS"] = EMAIL_ADDRESS;
	m_convert["IP_ADDRESS"] = IP_ADDRESS;
}

Plazza::Parser::~Parser()
{}

void Plazza::Parser::getInformation(std::string &information, std::string &fileName)
{
	std::lock_guard<std::mutex> lockGuard(g_file);
	std::fstream file(fileName);
	std::string line;
	std::smatch matches;
	std::regex pattern(m_pattern[information]);
	Fifo fifo;
	std::string res;

	if (file.is_open()) {
		while (std::getline(file, line)) {
			if (std::regex_search(line, matches, pattern)) {
				Log::writeLogs(m_convert[information], matches[0]);
				std::cout << matches[0] << std::endl;
				res += matches[0];
			}
		}
		fifo.write(res);
	} else {
		std::cerr << "Error: bad file." << std::endl;
		fifo.write("Error");
	}
}

void Plazza::Parser::getInformationFromString(std::string &information, std::vector<std::string> &words)
{
	std::vector<std::string> infos = {
		"EMAIL_ADDRESS",
		"PHONE_NUMBER",
		"IP_ADDRESS"
	};

	for (auto &word : words)
		for (auto &info : infos)
			if (word.find(info) != std::string::npos) {
				information = word;
				return;
			};
}

void Plazza::Parser::getFilesFromString(std::vector<std::string> &files, std::vector<std::string> &words)
{
	std::ifstream fst;
	std::vector<std::string> tmp;
	std::vector<std::string> infos = {
		"EMAIL_ADDRESS",
		"PHONE_NUMBER",
		"IP_ADDRESS"
	};
	int i = 0;

	tmp = words;
	for (auto &file : tmp) {
		if (std::find(infos.begin(), infos.end(), file) != infos.end()) {
			tmp.erase(tmp.begin() + i);
			break;
		}
		++i;
	}

	for (auto &t : tmp) {
		fst.open(t);
		if (fst.good()) {
			files.push_back(t);
			fst.close();
		}
	}
}