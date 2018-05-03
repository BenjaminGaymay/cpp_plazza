/*
** EPITECH PROJECT, 2018
** cpp_plazza
** File description:
** Menu
*/

#pragma once

#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

namespace Plazza {
	class Menu {
		public:
			Menu();
			~Menu();
			static std::vector<std::string> listFiles();
		private:
	};
}
