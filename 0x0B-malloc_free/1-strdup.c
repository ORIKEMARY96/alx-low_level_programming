#include "main.h"
#include <stdlib.h>
/**
 * _strdup - returns a pointer to a newly allocated space in memory.
 * @str: string.
 *
 * Return: pointer of an array of chars
 */
char *_strdup(char *str)
{
	char *strout;
	unsigned int i, l;

	i = 0;

	l = 0;


	if (str == NULL)
		return (NULL);

	while (str[l] != '\0')
		l++;

	strout = (char *)malloc(sizeof(char) * (l + 1));

	if (strout == NULL)
		return (NULL);

	while ((strout[i] = str[i]) != '\0')
		i++;


	return (strout);
}
