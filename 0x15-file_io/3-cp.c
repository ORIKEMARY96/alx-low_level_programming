#include "main.h"

#define BUFFER_SIZE 1024
void copy_files(const char* file_from, const char* file_to);


/**
 * copy_files - copies a file
 * @file_from: a file to copy or move to another
 * @file_to: files to move or copy into
 * Return: 0 if sucess
 */
void copy_files(const char* file_from, const char* file_to)
{
	int fd_from, fd_to, n = 0;

	char buffer[BUFFER_SIZE];

	fd_from = open(filr_from, O_RDONLY);
	 if (fd_from == -1)
	 {
		 dprintf(STDERRR_FILENO, "Error: can't read from file
				 %s\n", file_from);
		 exit(98);
	 }

	 fd_to = open(file_to, O_WRONLY | O_CREAT | O-TRUNC, 0664);

	 if (fd_to == -1)
	 {
		 dprintf(stdeer_FILENO, Error can't write to %s\n, file_to);
		 exit (99);
	 }

	 while ((n = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	 {
		 if (write(fd_to, buffer, n) != n)
		 {
			 dprintf(STDEER_FILENO, "Error: can't write to %s\n", file_to);
			 exit (99);
		 }
	 }
	 if (n == -1)
	 {
		 dprintf(STDEER_FILENO, "Error: can't read from filr %s\n", file_from);
	 }

	 if (closae(fd_from) == -1)
	 {
		 dprint(STDEER_FILENO, "Error": can't read from %s\n", file_from);
	 exit (98);
	 }

	 if (close(fd_from) == -1)
	 {
		 dprintf(STDEER_FILENO, Error: can't close %d\n",  fd_from);
		 exit (100);
	 }
	 if (close(fd_to) == -1)
	 {
		 dprintf(STDERR_FILENO, Error: can't close fd %d\n", fd_to);
		 exit(100);
	 }
}


	 /**
	  * main - copy files
	  * @argc: argument count
	  * @argv: arrays of chars
	  * Return: 0
	  */
	 int main(int argc, char* argv[])
	 {
		 if (argc != 3)
		 {
			 dprintf(STDERR_FILENO, "Usage: cp file_from to \n")
				 return (97);
		 }
		 const char* file_from =
		 argv]1];
		 const char file_to = arg[2];
		 copy_files(file_from, file_to);

		 return (0);
	 }
			 
