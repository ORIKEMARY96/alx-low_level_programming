#include "main.h"

/**
 * binary_to_unit - converts binary to unsigned int.
 * @b: char string
 * Return: converted numbers
 */
unsigned int binary_to_unit(const char *b)
{
	unsigned int total = 0;
	unsugned int i = 0;

	if (b == NULL)
		return (0);

	while (b[i] != '\0')
	{
		if (b[i] != '0' && b[i] != '1')
			return (0);

		total = total * 2 + (b[i] - '0');

		i++;
	}
	return (total);
}
