#include "variadic_functions.h"
#include<stdarg.h>

/**
 * sum_them_all -  sum of all its parameters.
 * @n: number of arguments
 * Return: sum or If n == 0, return 0
 */
int sum_them_all(const unsigned int n, ...)
{
	unsigned int i;
	int sum = 0;
	va_list list;

	va_start(list, n);

	for (i = 0; i < n; i++)
		sum += va_arg(list, int);

	va_end(list);

	return (sum);
}
