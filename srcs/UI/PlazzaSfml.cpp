/*
** EPITECH PROJECT, 2018
** cpp_plazza
** File description:
** PlazzaSfml
*/

#include <sys/stat.h>
#include "Plazza.hpp"
#include "Menu.hpp"
#include "Sfml.hpp"

void Plazza::PlazzaSfml::addList(std::vector<SfmlText> &objects)
{
	std::vector<std::string> ls;
	sf::Color color;
	struct stat buf;
	int y = 10;

	ls = Menu::listFiles();
	objects.push_back(SfmlText(10, 8, sf::Color::Blue, "..", SfmlText::directory));
	for (auto file : ls) {
		stat(file.c_str(), &buf);
		color = (S_ISDIR(buf.st_mode) ? sf::Color::Blue : sf::Color::White);
		for (auto select : _realPathFile) {
			if (std::strcmp(select.c_str() , (_sPwd + file).c_str()) == 0) {
				color = sf::Color::Green;
				break;
			}
		}
		objects.push_back(SfmlText(10, y, color, file, S_ISDIR(buf.st_mode) ? SfmlText::directory : SfmlText::regularFile));
		y++;
	}
}

void Plazza::PlazzaSfml::addInfos(std::vector<SfmlText> &objects, std::vector<std::string> &m_infos)
{
	int y = 5;

	for (auto info : m_infos) {
		objects.push_back(SfmlText(40, y, (info.compare(_selectInfo) == 0 ? sf::Color::Cyan : sf::Color::White), info, SfmlText::info));
		y++;
	}
}

int Plazza::PlazzaSfml::showObjects(Sfml &menu, std::vector<SfmlText> &objects, CommandManager &m_commandManager, std::pair<int, int> &mousePos)
{
	static int state = 0;
	std::vector<std::string>::iterator index;
	sf::FloatRect textPos;
	std::string cmd;

	if (state == 0) {
		for (auto &object : objects) {
			textPos = menu.drawText(object.getText(), object.getX(), object.getY(), object.getColor());
			if (menu.isPosInText(mousePos, textPos)) {
				switch (object._onClick(object)) {
					case SfmlText::CHANGEDIR:
						free(_pwd);
						_pwd = getcwd(NULL, 0);
						_sPwd = std::string(_pwd) + "/";
						break;
					case SfmlText::ADDFILE:
						_selectedFiles.push_back(object.getText());
						_realPathFile.push_back(realpath(object.getText().c_str(), NULL));
						break;
					case SfmlText::RMFILE:
						index = std::find(_realPathFile.begin(), _realPathFile.end(), (_sPwd + object.getText()).c_str());
						if (index != _realPathFile.end()) {
							_selectedFiles.erase(_selectedFiles.begin() + std::distance(_realPathFile.begin(), index));
							_realPathFile.erase(index);
						}
						break;
					case SfmlText::INFO:
						_selectInfo = object.getText();
						break;
					case SfmlText::VALIDATE:
						for (auto file : _realPathFile)
							cmd += file + ' ';
						cmd += _selectInfo;
						_results = m_commandManager.processCommands(cmd);
						return state = 1;
				}
			}
		}
	} else {
		int y = 1;
		for (auto result : _results) {
			if (y > 20)
				break;
			objects.push_back(SfmlText(5, y, sf::Color::Magenta, result, SfmlText::noop));
			y++;
		}
		for (auto &object : objects) {
			textPos = menu.drawText(object.getText(), object.getX(), object.getY(), object.getColor());
			if (menu.isPosInText(mousePos, textPos))
				switch (object._onClick(object)) {
					case SfmlText::BACK:
						return state = 0;
				}
		}
	}
	return state;
}

void Plazza::PlazzaSfml::startLoop(Sfml &menu, std::vector<std::string> &m_infos, CommandManager &m_commandManager)
{
	PlazzaSfml loopMenu;
	std::vector<SfmlText> objects;
	std::pair<int, int> mousePos;
	int state = 0;

	while (true) {
		mousePos = menu.getMousePos();
		if (menu.getKey() == sf::Keyboard::Escape)
			return;
		if (state == 0) {
			loopMenu.addList(objects);
			loopMenu.addInfos(objects, m_infos);
			objects.push_back(SfmlText(30, 30, sf::Color::Magenta, "Validate", SfmlText::validate));
		} else {
			objects.push_back(SfmlText(15, 30, sf::Color::Magenta, "Back", SfmlText::back));
		}
		menu.clearWindow();
		state = loopMenu.showObjects(menu, objects, m_commandManager, mousePos);
		menu.refreshWindow();
		objects.clear();
	}
}