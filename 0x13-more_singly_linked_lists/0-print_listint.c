#include "lists.h"
#include <stdio.h>

/**
 *  print_listint - prints all elements in a list
 *  @h: the head of linked list of type listint_t to print
 *  Return: number of nodes
 */
size_t print_listint(const listint_t *h)
{
	size_t num = 0;

	const listint_t *current;

	current = h;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
		num++;
	}
	return (num);
}
