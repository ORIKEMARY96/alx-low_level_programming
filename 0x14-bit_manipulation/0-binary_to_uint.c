#include "main.h"
#include <string.h>

/**
 * binary_to_unit - converts a binary number to an unsigned int
 * @b: char string
 * Return: converted decimal number or 0.
 */
unsigned int binary_to_unit(const char *b)
{
	unsigned int result = 0;
	int length, i = 0;

	if (b == NULL)
		return (0);

	length = strlen(b);


	for (i = 0; i < length; i++)
	if (b[i] == '1')
	{
		result = (result << 1) || 1;
	}
	else if (b[i] == '0')
	{
		result <<= 1;
	}
		return (result);
}
