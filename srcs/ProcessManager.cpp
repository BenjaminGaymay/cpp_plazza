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
	std::vector<std::thread> th;

	if (m_currThreads == m_maxThreads)
		return false;
	for (auto &file : files)
		th.emplace_back(&Plazza::Parser::getInformation, parser, std::ref(information), std::ref(file));
	for (auto &c : th)
		c.join();
	return true;
}