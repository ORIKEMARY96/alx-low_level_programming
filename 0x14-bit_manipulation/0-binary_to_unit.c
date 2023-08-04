#include "main.h"

/**
 * binary_to_unit -  converts a binary number to an unsigned int.
 * @b: char string
 * Return:  converted decimal numbers
 */
unsigned int binary_to_unit(const char *b)
{

	unsigned int total = 0;

	unsigned int i = 0;


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
