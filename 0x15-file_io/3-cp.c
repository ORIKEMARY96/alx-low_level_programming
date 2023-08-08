#include "main.h"
#include <stdio.h>

void copy_file(const char *file_from, const char *file_to);

/**
 * copy_file - copies a file from one to another
 * @file_from: pointer to a file to copy from
 * @file_to: pointer to file to copy to
 * Return: nothing
 */
void copy_file(const char *file_from, const char *file_to)
{
	int fd_from, fd_to, n;

	char buffer[BUFFER_SIZE];

	fd_from = open(file_from, O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: can't read from file %s\n", file_from);
		exit(98);
	}
	fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: can't write to file %s\n", file_to);
		exit(99);
	}
	while ((n = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		if (write(fd_to, buffer, n) != n)
		{
			dprintf(STDERR_FILENO, "Error: can't write to %s\n", file_to);
			exit(99);
		}
	}
	if (n == -1)
	{
		dprintf(STDERR_FILENO, "Error: can't read from fd %s\n", file_from);
		exit(98);
	}
	if (close(fd_from) == -1)
	{
		dprintf(STDERR_FILENO, "Error: can't close file %d\n", fd_from);
		exit(100);
	}
	if (close(fd_to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: can't close fd %d\n", fd_to);
		exit(100);
	}
}

/**
 * main - checks the number of arguments
 * @argc: the argument count
 * @argv: array of chars
 * Return: 0
 */
int main(int argc, char *argv[])
{
	const char *file_from = argv[1];

	const char *file_to = argv[2];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	

	copy_file(file_from, file_to);
		return (0);
}
