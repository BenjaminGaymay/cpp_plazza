/*
** EPITECH PROJECT, 2018
** cpp_plazza
** File description:
** Fifo
*/

#include "Fifo.hpp"

Plazza::Fifo::Fifo() :
	m_file(FIFO_FILE)
{}

Plazza::Fifo::~Fifo()
{
	unlink(m_file);
}

void Plazza::Fifo::open(std::string msg)
{
	unlink(msg);
	if (mkfifo(msg.c_str(), 0666) == ERR_FC)
		throw std::runtime_error("Error: can't create fifo file.");
}

void Plazza::Fifo::unlink(std::string msg)
{
	::unlink(msg.c_str());
}

void Plazza::Fifo::write(std::string &msg)
{
	int fd = ::open(m_file.c_str(), O_WRONLY);

	if (fd == ERR_FC)
		throw std::runtime_error("Error: Can't open fifo file.");
	::write(fd, msg.c_str(), msg.size());
	close(fd);
}

std::string Plazza::Fifo::read()
{
	std::string msg;
	char buf;
	int fd = ::open(m_file.c_str(), O_RDONLY);
	char b[256];
	if (fd == ERR_FC)
		throw std::runtime_error("Error: Can't open fifo file.");
	::read(fd, b, 256);
	msg = b;
	// while (read(fd, &buf, 1) != -1)
	// 	msg += buf;
	close(fd);
	return (msg);
}

std::string Plazza::Fifo::getFileName() const
{
	return m_file;
}