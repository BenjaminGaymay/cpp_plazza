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

void Plazza::CommandManager::processCommands(std::string &cmd)
{
	std::vector<std::string> files;
	std::vector<std::string> tab;
	std::string information;
	Parser parser;
	pid_t pid;
	std::string a("salut");

	tab = StringTools::split(cmd);
	parser.getInformationFromString(information, tab);
	parser.getFilesFromString(files, tab);
	if (information.empty() or files.empty())
		return;
	pid = fork();
	if (pid == ERR_FC)
		throw std::runtime_error("Error: can't fork the program.");
	if (pid == CHILD) {
		m_procManager.setMaxThreads(m_maxThreads);
		m_procManager.launchThreads(information, files);
		m_fifo.write(a);
		std::cout << "wut" << std::endl;
		exit(0);
	}
	sleep(2);
	std::cout << m_fifo.read() << std::endl;
}