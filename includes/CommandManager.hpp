/*
** EPITECH PROJECT, 2018
** cpp_plazza
** File description:
** CommandManager
*/

#pragma once

#include <iostream>
#include <vector>
#include <unistd.h>
#include "Parser.hpp"
#include "StringTools.hpp"
#include "ThreadsManager.hpp"
#include "Fifo.hpp"

namespace Plazza {
	class CommandManager {
		public:
			CommandManager();
			~CommandManager();

			std::vector<std::string> processCommands(std::string &);
			void setMaxThreads(int);
		private:
			int m_maxThreads;
			ThreadsManager m_procManager;
			Fifo m_fifo;
	};
}