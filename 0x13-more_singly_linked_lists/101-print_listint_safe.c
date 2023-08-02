#include "lists.h"


/**
 * print_listint_safe - prints a linked list with a loop safely
 * @head: pointer to 1st node
 * Return: number of node
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *current = head;

	size_t count = 0;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		count++;

		if (current->next >= current)
		{
			exit(98);
		}

		current = current->next;
	}
	return (count);
}
