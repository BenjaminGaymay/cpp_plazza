/*
** EPITECH PROJECT, 2018
** cpp_plazza
** File description:
** Plazza
*/

#include <sys/stat.h>
#include "Plazza.hpp"
#include "Sfml.hpp"
#include "Menu.hpp"

Plazza::Plazza::Plazza()
{
	m_convert["PHONE_NUMBER"] = PHONE_NUMBER;
	m_convert["EMAIL_ADDRESS"] = EMAIL_ADDRESS;
	m_convert["IP_ADDRESS"] = IP_ADDRESS;
	m_infos = {
		"EMAIL_ADDRESS",
		"PHONE_NUMBER",
		"IP_ADDRESS"
	};
}

Plazza::Plazza::~Plazza()
{}

void Plazza::Plazza::setMaxThreads(int maxThreads)
{
	m_maxThreads = maxThreads;
}

void Plazza::Plazza::setMaxThreads(const char *maxThreads)
{
	try {
		m_maxThreads = std::stoi(maxThreads);
	} catch (std::invalid_argument &e) { throw e; }
}

void Plazza::Plazza::run()
{
	std::vector<std::string> files;
	std::vector<std::string> words;
	std::vector<std::string> tab;
	std::string information;
	Sfml menu;

	if (m_maxThreads <= 0)
		throw std::runtime_error("Error: n° of threads must be superior to 0.");
	m_commandManager.setMaxThreads(m_maxThreads);

	std::vector<std::string> ls;
	std::vector<std::string> selectedFiles;
	std::vector<std::string> realPathFile;
	std::vector<SfmlText> objects;
	std::vector<std::string>::iterator index;
	std::string selectInfo;
	sf::Color color;
	struct stat buf;
	int y = 2;

	menu.openWindow();
	std::pair<int, int> mousePos;
	while (true) {
		ls = Menu::listFiles();
		y = 2;
		objects.push_back(SfmlText(3, 0, sf::Color::Blue, "..", SfmlText::directory));
		for (auto file : ls) {
			stat(file.c_str(), &buf);
			color = (S_ISDIR(buf.st_mode) ? sf::Color::Blue : sf::Color::White);
			for (auto select : selectedFiles) {
				if (file.compare(select) == 0) {
					color = sf::Color::Green;
					break;
				}
			}
			objects.push_back(SfmlText(3, y, color, file, S_ISDIR(buf.st_mode) ? SfmlText::directory : SfmlText::regularFile));
			y++;
		}

		y = 25;
		for (auto file : realPathFile) {
			objects.push_back(SfmlText(20, y, sf::Color::White, file, SfmlText::noop));
			y++;
		}

		y = 5;
		for (auto info : m_infos) {
			objects.push_back(SfmlText(20, y, (info.compare(selectInfo) == 0 ? sf::Color::Cyan : sf::Color::White), info, SfmlText::info));
			y++;
		}

		objects.push_back(SfmlText(30, 30, sf::Color::Magenta, "Validate", SfmlText::validate));

		mousePos = menu.getMousePos();
		menu.clearWindow();
		for (auto &object : objects) {
			if (menu.isPosInText(mousePos, object.getX(), object.getY(), object.getText())) {
				switch (object._onClick(object)) {
					case SfmlText::ADDFILE:
						selectedFiles.push_back(object.getText());
						realPathFile.push_back(realpath(object.getText().c_str(), NULL));
						break;
					case SfmlText::RMFILE:
						index = std::find(selectedFiles.begin(), selectedFiles.end(), object.getText());
						if (index != selectedFiles.end()) {
							realPathFile.erase(realPathFile.begin() + std::distance(selectedFiles.begin(), index));
    							selectedFiles.erase(index);
						}
						break;
					case SfmlText::INFO:
						selectInfo = object.getText();
						break;
					case SfmlText::VALIDATE:
						std::string cmd;

						for (auto file : realPathFile)
							cmd += file + ' ';
						cmd += selectInfo;
						m_commandManager.processCommands(cmd);
				}
			}
			menu.drawText(object.getText(), object.getX(), object.getY(), object.getColor());
		}
		menu.refreshWindow();
		objects.clear();
	}
	// for (std::string line; std::getline(std::cin, line);) {
	// 	if (line == "exit")
	// 		break;
	// 	tab = StringTools::split(line, ";");
	// 	for (auto &el : tab) {
	// 		el = StringTools::rstrip(el);
	// 		el = StringTools::lstrip(el);
	// 		m_commandManager.processCommands(el);
	// 	}
	// }
}