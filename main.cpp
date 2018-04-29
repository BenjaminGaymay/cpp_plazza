/*
** EPITECH PROJECT, 2018
** cpp_plazza
** File description:
** main
*/

#include <iostream>
#include "macro.hpp"

void usage(const char *prog)
{
	std::cout << "USAGE:\n\t" << prog <<
		"\tthreads\nDESCRIPTION\n\tthreads\tnumber of threads"
		<< std::endl;
}

int main(int ac, char **av)
{
	if (ac != 2)
		return (usage(av[0]), ERROR);
	return (SUCCESS);
}