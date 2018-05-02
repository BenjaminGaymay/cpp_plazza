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
	std::vector<std::thread> threads;

	for (auto &file : files) {
		threads.push_back(std::thread(&Plazza::Parser::getInformation, parser, std::ref(information), std::ref(file)));
	}
	for (auto &c : threads) {
		c.join();
	}
	return true;
}