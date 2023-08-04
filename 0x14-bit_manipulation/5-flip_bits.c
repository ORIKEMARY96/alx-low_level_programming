#include "main.h"

/**
 * flip_bits - converts one number to another number
 * @m: second number to convert
 * @n: first number to convert
 *
 * Return: number of bits flipped
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int diff = n ^ m;

	unsigned int num = 0;

	while (diff != 0)
	{
		num += diff & 1;
		diff >>= 1;
	}

	return (num);
}
