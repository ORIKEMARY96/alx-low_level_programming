#include "lists.h"

/**
 * get_nodeint_at_index - returns the nth node of a listint_t linked list.
 * @index: index of the node to return
 * @head: pointer to the 1st node of the list
 * Return: pointer to the node we are looking for or NULL
 * if does nott exist
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *tmp = head;

	unsigned int count = 0;

	while (tmp != NULL)
	{
		if (count == index)
			return (tmp);
		tmp = tmp->next;
		count++;
	}
	return (NULL);
}
