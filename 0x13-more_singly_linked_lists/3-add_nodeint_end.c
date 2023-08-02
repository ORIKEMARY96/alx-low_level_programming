#include "lists.h"

/**
 *  add_nodeint_end - adss a new node at the end of a list
 *  @n: data to add
 *  @head: pointer to the first node
 *  Return: pointer to the new node or NULL if fails
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *current, *tmp = *head;

	current = malloc(sizeof(listint_t));

	if (current == NULL)
	return (NULL);
current->n = n;
current->next = NULL;
if (*head == NULL)
{
	*head = current;
}
else
{
	tmp = *head;

	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = current;
}
return (current);
}
