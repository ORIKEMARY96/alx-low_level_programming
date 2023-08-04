#include "main.h"

/**
 * set_bit - sets value of a bit to 1 at a given index
 * @n: decimal number passed to the pointer
 * @index: index position starting from 0
 *
 * Return: 1 if it worked -1 if an error occurred
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long mask;

	if (index >= sizeof(unsigned long) * 8)
		return (-1);

	mask = 1UL << index;
	*n = *n | mask;

	return (1);
}

