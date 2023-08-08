#include "main.h"

/**
 * append_text_to_file - appends a text in a file
 * @filename: pointer to the file
 * @text_content: the string to append
 * Return: 1 0n success or -1 if fails
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int fd, len, w = 0;

	if (filename == NULL)
		return (-1);

	if (text_content == NULL)
	{
		while (text_content[len] != '\0')

			len++;
	}

	fd = open(filename, O_WRONLY | O_APPEND);

	w = write(fd, text_content, len);

	if (fd == -1  || w == -1)
		return (-1);
	close(fd);

	return (1);
}
