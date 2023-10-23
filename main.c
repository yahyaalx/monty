#include "monty.h"
/**
 * main - main func of program
 * @argc: argument count
 * @argv: argument list
 * Return: always 0
 */

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_file(argv[1]);
	free_nodes();
	return (0);
}
