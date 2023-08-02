#include "lists.h"

/**
 *  listint_len - returns number of element in a linked list
 *  @h: head of linked list to traverse
 *  Return: number of nodes
 */
size_t listint_len(const listint_t *h)
{

	size_t count = 0;

	while (h != NULL)
	{
		count++;
	       h = h->next;
	}
	return (count);
}
