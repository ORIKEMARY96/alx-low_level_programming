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
	unsigned long hold;

	unsigned long int j;

	if (index >= sizeof(unsigned long int) * 8)
		return (-1);

	for (j = 1; hold > 0; j *= 2)
		hold--;
	if ((*n >> index) & 1)
		*n -= j;
	return (1);
}
