/*
** EPITECH PROJECT, 2018
** cpp_plazza
** File description:
** ThreadsManager
*/

#pragma once

#include <vector>
#include <iostream>
#include <thread>
#include <future>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "macro.hpp"
#include "Parser.hpp"
#include "Log.hpp"
#include "Fifo.hpp"

namespace Plazza {
	class ThreadsManager {
	public:
		ThreadsManager();
		~ThreadsManager();

		void setMaxThreads(int);
		int getMaxThreads() { return m_maxThreads; }
		bool launchThreads(std::string &, std::vector<std::string> &);

	private:
		int m_maxThreads;
		int m_currThreads;
	};
}