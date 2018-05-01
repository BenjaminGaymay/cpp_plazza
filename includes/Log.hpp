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
#include "macro.hpp"

static std::mutex g_write;

namespace Plazza {
	class Log {
	public:
		Log() {};
		~Log() {};

		static void writeLogs(const Information &info, const std::string &msg) {
			g_write.lock();
			std::map<Information, std::string> convert = {
				{PHONE_NUMBER, "Phone number has been found"},
				{EMAIL_ADDRESS, "Email address has been found"},
				{IP_ADDRESS, "IP address has been found"}
			};
			std::ofstream file("./logs/logs.txt", std::ios_base::app);

			file << convert[info] << " : " <<msg << std::endl;
			g_write.unlock();
		}
	protected:
	private:
	};
}