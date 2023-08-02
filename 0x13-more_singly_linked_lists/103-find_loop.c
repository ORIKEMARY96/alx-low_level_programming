#include "lists.h"


/**
 * find_listint_loop - finds a loop in linked list
 * @head: pointer of the node
 * Return: address of the node or NULL.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow = head;

	listint_t *fast = head;

	while (slow != NULL && fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			slow = head;
			while (slow != fast)
			{
				slow = slow->next;
				fast = fast->next;
			}
			return (slow);
		}
	}

	return (NULL);
}
