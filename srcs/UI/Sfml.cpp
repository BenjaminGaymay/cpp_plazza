/*
** EPITECH PROJECT, 2018
** cpp_plazza
** File description:
** Sfml
*/

#include <iostream>
#include "Sfml.hpp"

using N_Sfml = Plazza::Sfml;

N_Sfml::Sfml() :
	_width(sf::VideoMode::getDesktopMode().width),
	_height(sf::VideoMode::getDesktopMode().height),
	_window(sf::VideoMode(_width, _height), "Plazza", sf::Style::Close | sf::Style::Fullscreen),
	_font(),
	_text()
{
	// if (!_bgText.loadFromFile("./ressources/images/arcade_bg_mano.png") or
	// 	!_titleImgText.loadFromFile("./ressources/images/arcade_title.png") or
	// 	!_music.openFromFile("./ressources/sounds/undertale.ogg"))
	// 	throw std::runtime_error("Can't load ressources.");
	// _bg.setTexture(_bgText);
	// _title.setTexture(_titleImgText);
	// _title.setPosition(sf::Vector2f(600, 50));

	_text.setFont(_font);
	_sx = 30;
	_sy = _sx;

	// _music.setLoop(true);
	// _music.play();
}

N_Sfml::~Sfml()
{}

void N_Sfml::loadTexture(const std::string &path)
{
	sf::Texture texture;

	if (texture.loadFromFile(path) == false)
		throw std::runtime_error("Error: ressources: Can't load sprites");
	_texture.push_back(texture);
}

sf::FloatRect N_Sfml::drawText(const std::string &text, const int &x, const int &y, const sf::Color &color)
{
	_text.setString(text);
	_text.setFillColor(color);
	_text.setPosition(sf::Vector2f(x*_sx, y*_sy));
	_window.draw(_text);
	return _text.getGlobalBounds();
}

bool N_Sfml::isOpen()
{
	return _window.isOpen();
}

void N_Sfml::openWindow()
{
	_window.setFramerateLimit(60);
	if (_font.loadFromFile("./ressources/Lato.ttf") == false)
		throw std::runtime_error("Error: sfml: can't load font.");
}

void N_Sfml::drawSquare(const int &x, const int &y, const sf::Color &color)
{
	sf::RectangleShape rect;
	sf::Sprite sprite;

	rect.setSize(sf::Vector2f(_sx,_sy));
	rect.setPosition(sf::Vector2f(x*_sx, y*_sy));
	sprite.setPosition(sf::Vector2f(x*_sx, y*_sy));
	rect.setFillColor(color);
	_window.draw(rect);
}

void N_Sfml::closeWindow()
{
	// for (float i = 100; i >= 0; i--){
	// 	_music.setVolume(i);
	// 	usleep(1000);
	// }
	//_music.stop();
	_window.close();
}

void N_Sfml::clearWindow()
{
	_window.clear(sf::Color::Black);
	_window.draw(_bg);
}

void N_Sfml::refreshWindow()
{
	_window.display();
}

int N_Sfml::getWidth()
{
	return _width;
}

int N_Sfml::getHeight()
{
	return _height;
}

int N_Sfml::getScaleWidth()
{
	return _width / _sx;
}

int N_Sfml::getScaleHeight()
{
	return _height / _sy;
}

sf::Keyboard::Key N_Sfml::getKey()
{
	return _key;
}

std::pair<int, int> N_Sfml::getMousePos()
{
	sf::Event event;
	std::pair<int, int> pos = {-1, -1};

	while (_window.pollEvent(event)) {
		if (event.type == sf::Event::KeyPressed)
			_key = event.key.code;
		if (event.type == sf::Event::MouseButtonPressed and
		event.mouseButton.button == sf::Mouse::Left) {
			pos.first = event.mouseButton.x;
			pos.second = event.mouseButton.y;
			return pos;
    		}
	}
	return pos;
}

bool N_Sfml::isPosInText(std::pair<int, int> &mousePos, sf::FloatRect &textPos)
{
	int xMin = textPos.left;
	int yMin = textPos.top;
	int xMax = xMin + textPos.width;
	int yMax = yMin + _sy;

	if (mousePos.first >= xMin and mousePos.first <= xMax and
	mousePos.second >= yMin and mousePos.second <= yMax)
		return true;
	return false;
}

void N_Sfml::drawMenu()
{
	_window.draw(_title);
}