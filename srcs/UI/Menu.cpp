/*
** EPITECH PROJECT, 2018
** cpp_plazza
** File description:
** Menu
*/

#include "Menu.hpp"

Plazza::Menu::Menu()
{
}

Plazza::Menu::~Menu()
{
}

std::vector<std::string> Plazza::Menu::listFiles()
{
	std::vector<std::string> files;
	std::string data;
	FILE *stream = popen("ls", "r");
	char line[256];

	while (fgets(line, 256, stream) != NULL)
		files.push_back(line);
	pclose(stream);
	for (auto &file : files)
		file[file.size() - 1] = '\0';
	return files;
}