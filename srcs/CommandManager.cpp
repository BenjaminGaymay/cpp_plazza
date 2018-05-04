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

std::vector<std::string> Plazza::CommandManager::divideProcessus(std::vector<std::string> &files, std::string &information)
{
	files = files;
	information = information;
	std::vector<std::vector<std::string>> newFiles;
	std::vector<std::string> res;
	std::vector<std::string> tmp;
	int j = 0;
	int k = 0;

	newFiles.push_back(std::vector<std::string>());
	for (std::size_t i = 0; i < files.size(); i++) {
		if (k == m_maxThreads) {
			k = 0;
			j++;
			newFiles.push_back(std::vector<std::string>());
		}
		k++;
		newFiles[j].push_back(files[i]);
	}
	for (auto &c : newFiles) {
		std::cout << "-------" << std::endl;
		for (auto &a : c) {
			std::cout << a << std::endl;
		}
	}
	res.resize(newFiles.size());
	for (auto &c : newFiles) {
		tmp = launchProcessus(c, information);
		res.insert(res.begin(), tmp.begin(), tmp.end());
	}
	return res;
}

std::vector<std::string> Plazza::CommandManager::launchProcessus(std::vector<std::string> &files, std::string &information)
{
	std::vector<std::string> res;
	std::string msg;
	pid_t pid;

	pid = fork();
	if (pid == ERR_FC)
		throw std::runtime_error("Error: can't fork the program.");
	if (pid == CHILD) {
		m_procManager.setMaxThreads(m_maxThreads);
		m_procManager.launchThreads(information, files);
		exit(0);
	}
	for (std::size_t i = 0; i < files.size(); i++) {
		msg = m_fifo.read();
		if (msg == "Error")
			break;
		else if (msg == "Max threads")
			return divideProcessus(files, information);
		else
			res.push_back(msg);
	}
	return res;
}

std::vector<std::string> Plazza::CommandManager::processCommands(std::string &cmd)
{
	std::vector<std::string> files;
	std::vector<std::string> tab;
	std::vector<std::string> res;
	std::string information;
	Parser parser;

	tab = StringTools::split(cmd);
	parser.getInformationFromString(information, tab);
	parser.getFilesFromString(files, tab);
	if (information.empty() or files.empty())
		return res;
	return launchProcessus(files, information);
}