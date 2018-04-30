/*
** EPITECH PROJECT, 2018
** cpp_plazza
** File description:
** main
*/

#include "macro.hpp"
#include "Plazza.hpp"
#include "Log.hpp"

void usage(const char *prog)
{
	std::cout << "USAGE:\n\t" << prog <<
		"\tthreads\nDESCRIPTION\n\tthreads\tnumber of threads"
		<< std::endl;
}

int main(int ac, char **av)
{
	Plazza::Plazza plazza;
	int ret = SUCCESS;

	if (ac != 2)
		return (usage(av[0]), ERROR);
	try {
		plazza.setMaxThreads(av[1]);
		plazza.run();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		ret = ERROR;
	}
	unlink(FIFO_FILE);
	return (ret);
}