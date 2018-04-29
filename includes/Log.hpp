/*
** EPITECH PROJECT, 2018
** cpp_plazza
** File description:
** Log
*/

#pragma once

#include <iostream>
#include <fstream>

namespace Plazza {
	class Log {
	public:
		Log() {};
		~Log() {};

		static void writeLogs(const std::string &msg) {
			std::ofstream file("./logs/logs.txt");

			file << msg << std::endl;
		}
	protected:
	private:
	};
}