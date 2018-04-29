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

namespace Plazza {
	enum Information {
		PHONE_NUMBER,
		EMAIL_ADDRESS,
		IP_ADDRESS
	};

	class Plazza {
	public:
		Plazza();
		~Plazza();

		void run();
		void setMaxThreads(int);
		void setMaxThreads(const char *);
		void getInformationFromString(std::string &, std::vector<std::string> &);
		void getFilesFromString(std::vector<std::string> &, std::vector<std::string> &);

	private:
		int m_maxThreads;
		std::map<Information, std::vector<std::string>> m_map;
		std::map<std::string, Information> m_convert;
	};
}