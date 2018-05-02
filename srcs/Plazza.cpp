/*
** EPITECH PROJECT, 2018
** cpp_plazza
** File description:
** Plazza
*/

#include "Plazza.hpp"

Plazza::Plazza::Plazza()
{
	m_convert["PHONE_NUMBER"] = PHONE_NUMBER;
	m_convert["EMAIL_ADDRESS"] = EMAIL_ADDRESS;
	m_convert["IP_ADDRESS"] = IP_ADDRESS;
	m_infos = {
		"EMAIL_ADDRESS",
		"PHONE_NUMBER",
		"IP_ADDRESS"
	};
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

void Plazza::Plazza::run()
{
	std::vector<std::string> files;
	std::vector<std::string> words;
	std::vector<std::string> tab;
	std::string information;

	if (m_maxThreads <= 0)
		throw std::runtime_error("Error: n° of threads must be superior to 0.");
	Fifo::open(FIFO_FILE);
	for (std::string line; std::getline(std::cin, line);) {
		if (line == "exit")
			break;
		tab = StringTools::split(line, ";");
		for (auto &el : tab) {
			el = StringTools::rstrip(el);
			el = StringTools::lstrip(el);
			m_commandManager.processCommands(el);
		}
	}
	Fifo::unlink(FIFO_FILE);
}