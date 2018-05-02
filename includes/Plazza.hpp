/*
** EPITECH PROJECT, 2018
** cpp_plazza
** File description:
** Plazza
*/

#pragma once

#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include "CommandManager.hpp"
#include "StringTools.hpp"
#include "macro.hpp"

namespace Plazza {
	class Plazza {
	public:
		Plazza();
		~Plazza();

		void run();
		void setMaxThreads(int);
		void setMaxThreads(const char *);

	private:
		int m_maxThreads;
		std::map<Information, std::vector<std::string>> m_map;
		std::map<std::string, Information> m_convert;
		std::vector<std::string> m_infos;

		CommandManager m_commandManager;
	};
}