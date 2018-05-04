/*
** EPITECH PROJECT, 2018
** cpp_plazza
** File description:
** CommandManager
*/

#include "CommandManager.hpp"

Plazza::CommandManager::CommandManager() :
	m_maxThreads(0), m_procManager(), m_fifo()
{}

Plazza::CommandManager::~CommandManager()
{}

void Plazza::CommandManager::setMaxThreads(int max)
{
	m_maxThreads = max;
}

void Plazza::CommandManager::divideProcessus(std::vector<std::string> &files, std::string &information)
{
	files = files;
	information = information;
	exit(0);
}

std::vector<std::string> Plazza::CommandManager::processCommands(std::string &cmd)
{
	std::vector<std::string> files;
	std::vector<std::string> tab;
	std::vector<std::string> res;
	std::string information;
	std::string s;
	Parser parser;
	pid_t pid;

	tab = StringTools::split(cmd);
	parser.getInformationFromString(information, tab);
	parser.getFilesFromString(files, tab);
	if (information.empty() or files.empty())
		return res;
	pid = fork();
	if (pid == ERR_FC)
		throw std::runtime_error("Error: can't fork the program.");
	if (pid == CHILD) {
		m_procManager.setMaxThreads(m_maxThreads);
		m_procManager.launchThreads(information, files);
		exit(0);
	}
	for (std::size_t i = 0; i < files.size(); i++) {
		s = m_fifo.read();
		if (s == "Error")
			break;
		else if (s == "Max threads") {
			divideProcessus(files, information);
		} else
			res.push_back(s);
	}
	return res;
}