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
#include "ProcessManager.hpp"

namespace Plazza {
	class CommandManager {
		public:
			CommandManager();
			~CommandManager();

			void processCommands(std::string &);
			void setMaxThreads(int);
		private:
			int m_maxThreads;
			ProcessManager m_procManager;
	};
}