/*
** EPITECH PROJECT, 2018
** cpp_plazza
** File description:
** Fifo
*/

#pragma once

#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

namespace Plazza {
	class Fifo {
		public:
			Fifo();
			~Fifo();

			void writeInFifo(std::string &);
			std::string readInFifo();
			std::string getFileName() const;
			int getFd() const;

		private:
			std::string m_file;
			int m_fd;
	};
}