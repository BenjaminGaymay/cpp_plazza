/*
** EPITECH PROJECT, 2018
** cpp_plazza
** File description:
** Plazza
*/

#include "StringTools.hpp"
#include "Plazza.hpp"

Plazza::Plazza::Plazza()
{
	m_convert["PHONE_NUMBER"] = PHONE_NUMBER;
	m_convert["EMAIL_ADDRESS"] = EMAIL_ADDRESS;
	m_convert["IP_ADDRESS"] = IP_ADDRESS;
}

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

void Plazza::Plazza::processCommand(std::string &cmd)
{
	std::vector<std::string> files;
	std::vector<std::string> tab;
	std::string information;
	pid_t pid;

	mkfifo(FIFO_FILE, 777);
	tab = StringTools::split(cmd);
	getInformationFromString(information, tab);
	getFilesFromString(files, tab);
	if (information.empty() or files.empty())
		return;
	pid = fork();
	if (pid == ERR_FC)
		throw std::runtime_error("Error: can't fork the program.");
	if (pid == CHILD) {
		m_procManager.setMaxThreads(m_maxThreads);
		if (m_procManager.launchThreads(information, files) == false) {
		}
	}
}

void Plazza::Plazza::run()
{
	std::vector<std::string> files;
	std::vector<std::string> words;
	std::vector<std::string> tab;
	std::string information;

	mkfifo(FIFO_FILE, 777);
	if (m_maxThreads <= 0)
		throw std::runtime_error("Error: n° of threads must be superior to 0.");
	for (std::string line; std::getline(std::cin, line);) {
		if (line == "exit")
			break;
		tab = StringTools::split(line, ",");
		for (auto &el : tab) {
			el = StringTools::rstrip(el);
			el = StringTools::lstrip(el);
			processCommand(el);
		}
	}
}