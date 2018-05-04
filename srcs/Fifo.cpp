/*
** EPITECH PROJECT, 2018
** cpp_plazza
** File description:
** Fifo
*/

#include "Fifo.hpp"

Plazza::Fifo::Fifo() :
	m_file(FIFO_FILE)
{
	mkFifo(m_file);
}

Plazza::Fifo::~Fifo()
{
	unlinkFile(m_file);
}

void Plazza::Fifo::mkFifo(std::string msg)
{
	struct stat st;

	if (stat(msg.c_str(), &st) == 0)
		return;
	if (mkfifo(msg.c_str(), 0666) == ERR_FC)
		throw std::runtime_error("Error: can't create fifo file.");
}

void Plazza::Fifo::deleteOldFile()
{
	DIR *dir;
	struct dirent *ent;
	std::string path;

	if ((dir = opendir(".tmp")) == nullptr) {
		std::cerr << "Error: no directory \".tmp\", try `mkdir .tmp`" << std::endl;
	} else {
		while ((ent = readdir(dir))) {
			path = ".tmp/";
			if (ent->d_type == DT_FIFO) {
				path += ent->d_name;
				unlink(path.c_str());
			}
		}
		closedir(dir);
	}
}

void Plazza::Fifo::unlinkFile(std::string msg)
{
	unlink(msg.c_str());
}

void Plazza::Fifo::write(std::string msg)
{
	int fd = open(m_file.c_str(), O_WRONLY);

	if (fd == ERR_FC)
		throw std::runtime_error("Error: Can't open fifo file to write.");
	::write(fd, msg.c_str(), msg.size());
	close(fd);
}

std::string Plazza::Fifo::read()
{
	std::string msg;
	char buf;
	int fd = open(m_file.c_str(), O_RDONLY);

	if (fd == ERR_FC)
		throw std::runtime_error("Error: Can't open fifo file to read.");
	while (::read(fd, &buf, 1) != 0)
		msg += buf;
	close(fd);
	return (msg);
}

std::string Plazza::Fifo::getFileName() const
{
	return m_file;
}