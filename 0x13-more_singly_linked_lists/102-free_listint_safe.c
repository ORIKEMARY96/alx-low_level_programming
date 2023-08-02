#include "lists.h"

/**
 * free_listint_safe - frees a list with a loop
 * @h: pointer to the 1st node in the list
 * Return: number of elements freed
 */
size_t free_listint_safe(listint_t **h)
{
	size_t num = 0;

	listint_t *current = *h;

	listint_t *temp = NULL;

	while (current != NULL)
	{
		temp = current;
		current = current->next;
		num++;


		if (temp->next >= temp)
		{
			*h = NULL;
			return (num);
		}
		free(temp);
	}
	*h = NULL;
	return (num);
}
