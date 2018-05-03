/*
** EPITECH PROJECT, 2018
** cpp_plazza
** File description:
** Log
*/

#include "Log.hpp"

Plazza::Log::Log()
{}

Plazza::Log::~Log()
{}

void Plazza::Log::writeLogs(const Information &info, const std::string &msg)
{
	std::lock_guard<std::mutex> lockGuard(g_write);
	std::map<Information, std::string> convert = {
		{PHONE_NUMBER, "Phone number has been found"},
		{EMAIL_ADDRESS, "Email address has been found"},
		{IP_ADDRESS, "IP address has been found"}
	};
	std::ofstream file("./logs/logs.txt", std::ios_base::app);

	file << convert[info] << " : " <<msg << std::endl;
}