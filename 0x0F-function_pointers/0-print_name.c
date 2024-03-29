#include "function_pointers.h"
#include<stdlib.h>

/**
 * print_name - prints a name
 * @name: name of a person
 * @f: pointer to the function
 * Return: nothing
 */
void print_name(char *name, void(*f)(char *))
{
	if (f != NULL)
		f(name);
}
