/*
** EPITECH PROJECT, 2018
** cpp_plazza
** File description:
** ProcessManager
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

namespace Plazza {
	class ProcessManager {
	public:
		ProcessManager();
		~ProcessManager();

		void setMaxThreads(int);
		bool launchThreads(std::string &, std::vector<std::string> &);

	private:
		int m_maxThreads;
		int m_currThreads;
	};
}