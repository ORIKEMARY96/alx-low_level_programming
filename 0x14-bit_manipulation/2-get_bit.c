#include "main.h"

/**
 * get_bit - get the value of a bit at a given index
 * @n: number evaluated
 * @index: index starting from 0 of the bit to get
 * Return: the value of bit at index or -1 if an error occured
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int hold;

	if (index >= sizeof(unsigned long int) * 8)
		return (-1);

	hold = n >> index;

	return (hold & 1);
}
