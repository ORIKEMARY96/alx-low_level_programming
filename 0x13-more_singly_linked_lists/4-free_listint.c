#include "lists.h"

/**
 *  free_list - frees a linked list
 *  @head: list to be freed
 *  Return: Nothing.
 */
void free_listint_t(listint_t *head)
{
	listint_t *tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}


