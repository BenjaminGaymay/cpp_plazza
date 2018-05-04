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

void Plazza::ThreadsManager::quit_child(int sign)
{
	(void)sign;
	exit (0);
}


void Plazza::ThreadsManager::init_alarm_catch()
{
	struct sigaction action;

	action.sa_handler = quit_child;
	sigaction(SIGALRM, &action, NULL);
}


bool Plazza::ThreadsManager::launchThreads(std::string &information, std::vector<std::string> &files)
{
	Parser parser;
	std::string info;
	std::vector<std::thread> threads;
	std::ifstream f;
	Fifo fifo;
	int seconds = 5;

	// if ((int)(files.size()) > m_maxThreads * 2)
	// 	return fifo.write("Max threads"), false;
	for (auto i = 0 ; i < m_maxThreads ; i++)
		std::thread(&Plazza::Parser::getInformation, parser, std::ref(information), std::ref(files)).detach();
	init_alarm_catch();
    	alarm(seconds);
	while (1);
	return true;
}