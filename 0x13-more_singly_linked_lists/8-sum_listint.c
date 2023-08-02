#include "lists.h"

/**
 * sum_listint - calculates the sum of all
 * data(n) in a linked list
 * @head: pointer to the 1st node in the list
 * Return: sum of the elements in the list
 */
int sum_listint(listint_t *head)
{
	int sum = 0;

	listint_t *tmp = head;

	while (tmp != NULL)
	{
		sum += tmp->n;
	tmp = tmp->next;
	}
	return (sum);
}
