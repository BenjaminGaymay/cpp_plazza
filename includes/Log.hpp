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

static std::mutex g_write;

namespace Plazza {
	class Log {
	public:
		Log() {};
		~Log() {};

		static void writeLogs(const std::string &msg) {
			g_write.lock();
			std::ofstream file("./logs/logs.txt", std::ios_base::app);

			file << msg << std::endl;
			g_write.unlock();
		}
	protected:
	private:
	};
}