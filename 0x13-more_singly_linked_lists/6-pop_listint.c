#include "lists.h"

/**
 *  pop_listint - deletes  the head node of a listint_t linked list.
 *  @head: pointer to the 1st element in the list
 *  Return: the head node's data(n).
 */
int pop_listint(listint_t **head)
{
	int data;

	listint_t *tmp;

	if (*head == NULL)
	{
		return (0);
	}
	data = (*head)->n;
	tmp = *head;
	*head = (*head)->next;
	
	free(tmp);

	return (data);
}
