#include "main.h"

/**
 * print_binary - prints the binary reprsentation of numbers
 * @n: decimal numbers  to  print in binary form
 * Return: nothing
 */
void print_binary(unsigned long int n)
{

	if (n == 0)
	{

		printf("0");
		return;
	}

	if (n > 1)
		print_binary(n >> 1);

	putchar((n & 1) + '0');
	return;
}
