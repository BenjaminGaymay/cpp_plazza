/*
** EPITECH PROJECT, 2018
** cpp_plazza
** File description:
** ThreadsManager
*/

#include "ThreadsManager.hpp"

Plazza::ThreadsManager::ThreadsManager() :
	m_maxThreads(0), m_currThreads(0)
{}

Plazza::ThreadsManager::~ThreadsManager()
{}

void Plazza::ThreadsManager::setMaxThreads(int max)
{
	m_maxThreads = max;
}

bool Plazza::ThreadsManager::launchThreads(std::string &information, std::vector<std::string> &files)
{
	Parser parser;
	std::string info;
	std::vector<std::thread> threads;
	std::ifstream f;
	Fifo fifo;


	if ((int)(files.size()) > m_maxThreads * 2)
		fifo.write("Max threads");
	for (auto &file : files) {
		if (m_currThreads >= m_maxThreads)
			break ;
		m_currThreads += 1;
		threads.push_back(std::thread(&Plazza::Parser::getInformation, parser, std::ref(information), std::ref(file)));
	}
	for (auto &c : threads)
		c.join();

	m_currThreads = 0;
	files.erase(files.begin(), files.begin() + m_maxThreads);
	if (files.empty() == false)
		launchThreads(information, files);
	return true;
}