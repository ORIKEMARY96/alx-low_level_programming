#include "lists.h"

/**
 * reverse_listint - reverses a linked list
 * @head: pointer to the 1st node
 * Return: pointer to the node
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL;

	listint_t *current = *head;

	listint_t *next = NULL;

	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	*head = prev;

	return (*head);
}
