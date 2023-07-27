#include <stdio.h>

int first(void) __attribute__ ((constructor));

/**
 * first - prints a statement before the main
 *  function is executed.
 * Return: 0
 */
int first(void)
{
	printf("You're beat! and yet, you must allow,\n");

	printf("I bore my house upon my back!\n");

	return (0);
}
