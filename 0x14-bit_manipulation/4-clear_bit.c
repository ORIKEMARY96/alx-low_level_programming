#include "main.h"

/**
 * clear_bit - set the value of a bit 0
 * at a given index.
 * @index: pointer to the decimal number
 * @n: the index position
 * Return: 1 if it worked or -1 if an error ocurred
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int mask;

	if (index >= sizeof(unsigned long int) * 8)
		return (-1);
	mask = ~(1UL << index);

	*n = *n & mask;

	return (1);
}
