/*
** EPITECH PROJECT, 2018
** cpp_plazza
** File description:
** Sfml
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <unistd.h>

namespace Plazza {
	class Sfml {
	public:
		Sfml();
		~Sfml();

		void drawText(const std::string &, const int &, const int &, const sf::Color &);
		void drawSquare(const int &, const int &, const sf::Color &);
		void clearWindow();
		void refreshWindow();
		sf::Keyboard::Key getKey();
		std::pair<int, int> getMousePos();
		void closeWindow();
		void openWindow();
		int getWidth();
		int getHeight();
		int getScaleWidth();
		int getScaleHeight();
		bool isOpen();
		void loadTexture(const std::string &);
		void drawMenu();
		bool isPosInText(const std::pair<int, int> &, int, int, const std::string);

	private:
		int _width;
		int _height;
		int _sx;
		int _sy;

		sf::Keyboard::Key _key;
		sf::RenderWindow _window;
		sf::Font _font;
		sf::Text _text;
		sf::Event _event;
		sf::Sprite _bg;
		sf::Texture _bgText;
		sf::Texture _titleImgText;
		sf::Sprite _title;
		sf::Music _music;
		std::vector<sf::Texture> _texture;
	};

	class SfmlText {
		public:
			enum Click {
				NONE,
				ADDFILE,
				RMFILE,
				INFO,
				VALIDATE
			};
			SfmlText(const int x, const int y, const sf::Color color, const std::string text, int (*onClick)(SfmlText &)) :
				_x(x), _y(y), _color(color), _text(text), _onClick(onClick) {}
			int getX() { return _x; }
			int getY() { return _y; }
			std::string getText() { return _text; }
			sf::Color getColor() { return _color; }
			void setX(const int newX) { _x = newX; }
			void setY(const int newY) { _y = newY; }
			void setColor(const sf::Color newColor) { _color = newColor; }
			static int regularFile(SfmlText &object) { return (object.getColor() == sf::Color::White ? ADDFILE : RMFILE); }
			static int directory(SfmlText &object) { chdir(object.getText().c_str()); return NONE; }
			static int noop(SfmlText &object) { (void)object; return NONE; }
			static int info(SfmlText &object) { (void)object; return INFO; }
			static int validate(SfmlText &object) { (void)object; return VALIDATE; }
		private:
			int _x;
			int _y;
			sf::Color _color;
			std::string _text;
		public:
			int (*_onClick)(SfmlText &);
	};
}