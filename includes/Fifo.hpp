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
#include <dirent.h>
#include "macro.hpp"

namespace Plazza {
	class Fifo {
		public:
			Fifo();
			~Fifo();

			static void mkFifo(std::string);
			static void unlinkFile(std::string);
			void write(std::string);
			std::string read();
			std::string getFileName() const;
			static void deleteOldFile();

		private:
			std::string m_file;
	};
}
