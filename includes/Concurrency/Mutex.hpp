/*
** EPITECH PROJECT, 2018
** cpp_plazza
** File description:
** Mutex
*/

#pragma once

#include <mutex>

namespace Plazza {
	class Mutex {
	public:
		Mutex();
		~Mutex();

	private:
		std::mutex m_mutex;
	};
}