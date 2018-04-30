/*
** EPITECH PROJECT, 2018
** cpp_plazza
** File description:
** ProcessManager
*/

#include "ProcessManager.hpp"

Plazza::ProcessManager::ProcessManager() :
	m_maxThreads(0), m_currThreads(0)
{}

Plazza::ProcessManager::~ProcessManager()
{}

void Plazza::ProcessManager::setMaxThreads(int max)
{
	m_maxThreads = max;
}

bool Plazza::ProcessManager::launchThreads(std::string &information, std::vector<std::string> &files)
{
	Parser parser;
	std::string info;

	if (m_currThreads == m_maxThreads)
		return false;

	info = parser.getInformation(information, files[0]);
	Log::writeLogs(info);
	return true;
}