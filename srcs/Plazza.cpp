/*
** EPITECH PROJECT, 2018
** cpp_plazza
** File description:
** Plazza
*/

#include "StringTools.hpp"
#include "Plazza.hpp"

Plazza::Plazza::Plazza()
{}

Plazza::Plazza::~Plazza()
{}

void Plazza::Plazza::setMaxThreads(int maxThreads)
{
	m_maxThreads = maxThreads;
}

void Plazza::Plazza::setMaxThreads(const char *maxThreads)
{
	try {
		m_maxThreads = std::stoi(maxThreads);
	} catch (std::invalid_argument &e) { throw e; }
}

void Plazza::Plazza::getInformationFromString(std::string &information, std::vector<std::string> &words)
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
			}
}

void Plazza::Plazza::getFilesFromString(std::vector<std::string> &files, std::vector<std::string> &words)
{
	int i = 0;
	std::vector<std::string> infos = {
		"EMAIL_ADDRESS",
		"PHONE_NUMBER",
		"IP_ADDRESS"
	};

	files = words;
	for (auto &file : files) {
		if (std::find(infos.begin(), infos.end(), file) != infos.end()) {
			files.erase(files.begin() + i);
		}
		++i;
	}
}

void Plazza::Plazza::run()
{
	std::string information;
	std::vector<std::string> files;
	std::vector<std::string> words;

	if (m_maxThreads <= 0)
		throw std::runtime_error("Error: n° of threads must be superior to 0.");
	for (std::string line; std::getline(std::cin, line);) {
		words = StringTools::split(line, " ");
		getInformationFromString(information, words);
		getFilesFromString(files, words);
		if (information.empty())
			continue;
		
	}
}