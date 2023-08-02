#include "lists.h"

/**
 *  add_nodeint - add a new node at the
 *  begining of a linked list
 *  @n: data to insert in the new node
 *  @head: pointer to the first node in the list
 *  Return: pointer or NULL if fails.
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new_node;

	new_node = malloc(sizeof(listint_t));
	if (new_node != NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = *head;
		*head = new_node;

		return (*head);
}
