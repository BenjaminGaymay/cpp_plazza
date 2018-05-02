/*
** EPITECH PROJECT, 2018
** cpp_plazza
** File description:
** Log
*/

#pragma once

#include <iostream>
#include <fstream>
#include <mutex>
#include <map>
#include "macro.hpp"

static std::mutex g_write;

namespace Plazza {
	class Log {
	public:
		Log();
		~Log();

		static void writeLogs(const Information &, const std::string &);
	private:
	};
}