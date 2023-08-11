#include "main.h"

/**
 * create_file - creates a file
 * @filename: pointer to the file name to crete
 * @text_content: pointr to a string to write
 * Return: 1 on success or -1 if fail
 */
int create_file(const char *filename, char *text_content)
{
	int fd, len, w = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
		while (text_content[len] != '\0')
		{
			len++;
		}
	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, S_IRUSR | S_IWUSR);
		w = write(fd, text_content, len);

		if (fd == -1 || w == -1)
		return (-1);

		close(fd);

		return (1);
}
