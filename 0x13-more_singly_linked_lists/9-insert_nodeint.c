#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node in a linked list
 * at a givien position.
 * @idx: index where new node is added
 * @head: pointer to the head of the 1st node
 * @n: data inserted in the new node
 * Return: pointer of the new node por NULL
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new_node, *temp;

	unsigned int count = 0;

	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = n;

	if (idx == 0)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}

	temp = *head;
	while (temp != NULL)
	{
		if (count == idx - 1)
		{
			new_node->next = temp->next;
			temp->next = new_node;
			return (new_node);
		}
		temp = temp->next;
		count++;
	}
	return (NULL);
}
