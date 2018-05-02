/*
** EPITECH PROJECT, 2018
** cpp_plazza
** File description:
** Fifo
*/

#include "Fifo.hpp"

Plazza::Fifo::Fifo() :
	m_file("/tmp/myfifo"), m_fd(-1)
{
	m_fd = open(m_file.c_str(), O_RDWR);
}

Plazza::Fifo::~Fifo()
{
	close(m_fd);
}

void Plazza::Fifo::writeInFifo(std::string &msg)
{
	write(m_fd, msg.c_str(), msg.size());
}

std::string Plazza::Fifo::readInFifo()
{
	std::string msg;
	char buf;

	while (read(m_fd, &buf, 1) != -1)
		msg += buf;
	return (msg);
}

std::string Plazza::Fifo::getFileName() const
{
	return m_file;
}

int Plazza::Fifo::getFd() const
{
	return m_fd;
}